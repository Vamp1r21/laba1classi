#include "Polynom.h"
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
Polynom::Polynom()
{
    koef = NULL;
}
Polynom::~Polynom()
{
    delete[]koef;
}
Polynom::Polynom(int an)
{
    int i;
    n = an;
    koef = new double[n + 1];
    for (i = 0; i <= n; i++)
    {
        koef[i] = 0;
    }
}
Polynom::Polynom(const Polynom& f)
{
    n = f.n;
    koef = new double[n + 1];
    for (int i = 0; i <= n; i++)
        koef[i] = f.koef[i];
}
int Polynom::getn()
{
    return n;
}
double Polynom::getkoef(int i)
{
    if (i <= n)
        return koef[i];
    else
        return 0.0;
}
Polynom Polynom::operator-(const Polynom& t) //оператор вычитания А-В
{
    int i;
    if (n >= t.n)//А>B
    {
        Polynom Z = *this;
        for (i = 0; i <= t.n; i++)
            Z.koef[i] = koef[i] - t.koef[i];
        return Z;
    }
    else//B>A
    {
        Polynom Z(t.n);
        for (i = 0; i <= n; i++)
            Z.koef[i] = -t.koef[i] + koef[i];
        for (i = n + 1; i <= t.n; i++)
            Z.koef[i] = -t.koef[i];
        return Z;
    }
}
Polynom Polynom::operator-=(const Polynom& t) //оператор вычитания А-В
{
    int i;
    if (n >= t.n)//А>B
    {
        Polynom Z = *this;
        for (i = 0; i < n; i++)
        {
            Z.koef[i] = koef[i];
        }
        for (i = 0; i <= t.n; i++)
            Z.koef[i] -= t.koef[i];
        for (i = n + 1; i <= t.n; i++)
            Z.koef[i] -= t.koef[i];
        for (i = 0; i < n; i++)
        {
            koef[i] = Z.koef[i];
        }
        return Z;
    }
    else//B>A
    {
        Polynom Z(*this);
        for (i = 0; i < n; i++)
        {
            Z.koef[i] = t.koef[i];
        }
        for (i = 0; i <= t.n; i++)
            Z.koef[i] -= koef[i];
        for (i = 0; i < n; i++)
        {
            t.koef[i] = Z.koef[i];
        }
        return Z;
    }
}
Polynom Polynom::operator+(const Polynom& t)//оператор сложения A+B
{
    int i;
    if (n >= t.n)//A>B
    {
        Polynom Z = *this;
        for (i = 0; i <= n; i++)
            Z.koef[i] = koef[i] + t.koef[i];
        return Z;
    }
    else//A<B
    {
        Polynom Z = t;
        for (i = 0; i <= n; i++)
            Z.koef[i] = t.koef[i] + koef[i];
        return Z;
    }
}
Polynom Polynom::operator+=(const Polynom& t)//оператор сложения A+B
{
    int i;
    if (n >= t.n)//A>B
    {
        Polynom Z = *this;
        for (i = 0; i < n; i++)
        {
            Z.koef[i] = koef[i];
        }
        for (i = 0; i <= n; i++)
            Z.koef[i] +=t.koef[i];
        return Z;
    }
    else//A<B
    {
        Polynom Z = t;
        for (i = 0; i < n; i++)
        {
            Z.koef[i] = t.koef[i];
        }
        for (i = 0; i <= n; i++)
            Z.koef[i] += koef[i];
        return Z;
    }
}
Polynom Polynom::operator*(const Polynom& t)//оператор умножения А*В
{
    int i, j, s = 0;
    Polynom Y(n + t.n);
    for (i = 0; i <= n; i++)
        for (j = 0; j <= t.n; j++)
            Y.koef[i + j] += koef[i] * t.koef[j];
    return Y;
}
Polynom Polynom::operator*=(const Polynom& t)//оператор умножения А*В
{
    int i, j, s = 0;
    Polynom Z = *this;
    Polynom Y(n + t.n);
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= t.n; j++){

            for (int k = 0; k < n;k++)
            {
                Z.koef[k] = koef[k];
            }
        Z.koef[i] *= t.koef[j];
        Y.koef[i + j] += Z.koef[i];
        }
    }

    return Y;
}
Polynom Polynom::operator = (const Polynom& t)
{
    if (this != &t)
    {
        delete[] koef;
        n = t.n;
        koef = new double[n + 1];
        for (int i = 0; i <= n; i++)
            koef[i] = t.koef[i];
    }
    return *this;
}
istream& operator>>(istream& s, Polynom& c)// перегруженный оператор ввода
{
    int i;
    for (i = 0; i <= c.n; i++)
    {
        s >> c.koef[i];
    }
    return s;
}
ostream& operator << (ostream& s, const Polynom& c)
{
    int i, n = 0;
    for (i = 0; i <= c.n; i++)
    {
        if (c.koef[i] != 0)
            n++;
    }
    if (n != 0)
    {
        if (c.koef[0] != 0)
        {
            s << c.koef[0];
        }
        for (i = 1; i <= c.n; i++)
        {
            if (c.koef[i] < 0)
            {
                if (c.koef[i] != -1)
                    s << c.koef[i] << "X^" << i;
                else
                    s << "-" << "X^" << i;
            }
            else
            {
                if (c.koef[i] != 0)
                {
                    if (c.koef[i] != 1)
                        s << "+" << c.koef[i] << "X^" << i;
                    else
                        s << "+" << "X^" << i;
                }
            }
        }
        s << '\n';
    }
    else
    {
        s << 0;
    }
    return s;
}