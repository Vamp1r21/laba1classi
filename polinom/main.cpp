#include<iostream>
#include<iomanip>
#include<fstream>
#include "Polynom.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "");
    int n, m,t,y;
    cout << "������� ������� �������� A � ������� �������� B:" << '\n';
    cin >> n >> m;
    Polynom A(n), B(m), D, K, Y;
    cout << "������� ����������� �������� A:" << '\n';
    cin >> A;
    cout << "������� ����������� �������� B:" << '\n';
    cin >> B;
    cout << "��������� �:" << setw(5) << A << '\n';
    cout << "��������� B:" << setw(5) << B << '\n';
    cout << "��������� D=A+B:" << setw(5) << (D = A + B) << '\n';
    cout << "��������� A+=B:" << setw(5) << (A+=B) << '\n';
    cout << "��������� K=A-B:" << setw(5) << (K = A - B) << '\n';
    cout << "��������� A-=B:" << setw(5) << (A-=B) << '\n';
    cout << "��������� Y=A*B:" << setw(5) << (Y = A * B) << '\n';
    cout << "��������� A*=B:" << setw(5) << (A *= B) << '\n';
    system("pause");
}