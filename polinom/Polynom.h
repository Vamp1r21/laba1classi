#include<iostream>
#include<fstream>
using namespace std;
class Polynom
{//1)���� ������� ������ ���� private 2)�������� ���������  
public:
    int n; //������� ��������
    double* koef; //��������� �� ������ ������������� �������� koef[i] - ����������� ��� i-� �������
    Polynom();
    Polynom(int an);//����������� � �����������
    Polynom(const Polynom&); //�����������
    ~Polynom();//����������
    int getn(); //������� ��������� ������� ��������
    double getkoef(int); //������� ��������� ������������ ��� i-� �������
    Polynom operator+(const Polynom&);   //�������� �������� ���� ���������
    Polynom operator-(const Polynom&);   //�������� ��������� ���� ���������
    Polynom operator*(const Polynom&);// �������� ���������
    Polynom operator+=(const Polynom&);   //�������� �������� ���� ���������
    Polynom operator-=(const Polynom&);   //�������� ��������� ���� ���������
    Polynom operator*=(const Polynom&); // �������� ���������
    Polynom operator=(const Polynom&);   
    Polynom operator == (const Polynom&);   
    Polynom operator <(const Polynom&);   
    Polynom operator >(const Polynom&);
    Polynom operator <=(const Polynom&);
    Polynom operator>=(const Polynom&); 
    Polynom operator!=(const Polynom&); 
    friend ostream& operator<<(ostream& s, const Polynom& c); // ������������� �������� ������
    friend istream& operator>>(istream& s, Polynom& c); // ������������� �������� �����
};

