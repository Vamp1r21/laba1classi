#include<iostream>
#include<iomanip>
#include<fstream>
#include "Polynom.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "");
    int n, m,t,y;
    cout << "Введите степень полинома A и степень полинома B:" << '\n';
    cin >> n >> m;
    Polynom A(n), B(m), D, K, Y;
    cout << "Введите коэфициенты полинома A:" << '\n';
    cin >> A;
    cout << "Введите коэфициенты полинома B:" << '\n';
    cin >> B;
    cout << "Многочлен А:" << setw(5) << A << '\n';
    cout << "Многочлен B:" << setw(5) << B << '\n';
    cout << "Многочлен D=A+B:" << setw(5) << (D = A + B) << '\n';
    cout << "Многочлен A+=B:" << setw(5) << (A+=B) << '\n';
    cout << "Многочлен K=A-B:" << setw(5) << (K = A - B) << '\n';
    cout << "Многочлен A-=B:" << setw(5) << (A-=B) << '\n';
    cout << "Многочлен Y=A*B:" << setw(5) << (Y = A * B) << '\n';
    cout << "Многочлен A*=B:" << setw(5) << (A *= B) << '\n';
    system("pause");
}