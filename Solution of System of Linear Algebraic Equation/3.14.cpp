/*WAP to find Solution of System of Linear Algebraic Equation with Gauss Seidel Method.*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#define pi 3.14159265358979323846264338327950288419716939937510
#define e 2.71828182845904523536028747135266249775724709369995
using namespace std;
double a[3][4];
double x,p_m=0.0,y,p_n=0.0,z,p_o=0.0,err;
int k,counter,error;
void get_matrix()
{
    int i,j;
    cout<<"\n\t\tGAUSS SEIDEL ITERATION METHOD";
    cout<<"\n\n Enter Diagonally Dominant System";
    cout<<"\n\n |a1|>|b1|+|c1|, |b2|>|a2|+|c2| & |c3|>|b3|+|a3|";
    cout<<"\n\n Enter 3*3 linear equations.";
    cout<<"\n\n a11x + a12y + a13z = b1";
    cout<<"\n\n a21x + a22y + a23z = b2";
    cout<<"\n\n a31x + a32y + a33z = b3";
    for(i=0; i<3; i++)
    {
        cout<<endl<<endl;
        for(j=0; j<3; j++)
        {
            cout<<" Enter a["<<i+1<<"]["<<j+1<<"]\t";
            cin>>a[i][j];
        }
        cout<<"\n Enter b["<<i+1<<"]["<<j+1<<"]\t";
        cin>>a[i][j];
    }
    if (a[0][0]==0 || a[1][1]==0 || a[2][2]==0)
    {
        cout<<"\n\n Invalid values!!!";
        cout<<"\n\n Interchange rows or column and enter again such that no diagonals elements are zero!!!";
        cout<<"\n\n JACOBIS’s INVERSE METHOD fails if any diagonal element is zero!!!\n\n";
        exit(1);
    }
    cout<<"\n\n************************************************************************************************************************************************************************\n\n";
}
void jacobi_inverse(double & m,double & n,double & o)
{
  cout<<endl<<endl<<" "<<counter<<"\t\t"<<setw(9)<<setprecision(9)<<m;
  cout<<"\t\t"<<setw(9)<<setprecision(9)<<n;
  cout<<"\t\t"<<setw(9)<<setprecision(9)<<o;
  p_m=m;
  p_n=n;
  p_o=o;
  m = (a[0][3]-a[0][1]*n-a[0][2]*o)/a[0][0];
  n = (a[1][3]-a[1][0]*m-a[1][2]*o)/a[1][1];
  o = (a[2][3]-a[2][0]*m-a[2][1]*n)/a[2][2];
  err = (abs(m-p_m)+abs(n-p_n)+abs(o-p_o))/3;
  cout<<"\t\t"<<setw(9)<<setprecision(9)<<err;
}
int main()
{
    while(1)
    {
        get_matrix();
        cout<<"\nEnter tolerance (10^-k)";
        cout<<"\nEnter k: ";
        cin>>k;
        cout<<"\n\n x = ("<<a[0][3]<<"-("<<a[0][1]<<"y)-("<<a[0][2]<<"z))/"<<a[0][0];
        cout<<"\n\n y = ("<<a[1][3]<<"-("<<a[1][0]<<"x)-("<<a[1][2]<<"z))/"<<a[1][1];
        cout<<"\n\n z = ("<<a[2][3]<<"-("<<a[2][0]<<"x)-("<<a[2][1]<<"y))/"<<a[2][2];
        cout<<"\n\n************************************************************************************************************************************************************************\n\n";
        cout<<"\n\n SN\t\t\tx"<<"\t\t\t y"<<"\t\t\tz"<<"\t\tError \n\n";
        x=0.0;
        y=0.0;
        z=0.0;
        counter = 0;
        error=10;
        while (error>9)
        {
            counter++;
            jacobi_inverse(x,y,z);
            error = (int)trunc(err*pow(10,k));//error is in order of 10^k
        }
        cout<<"\n\n\n\n************************************************************************************************************************************************************************\n\n";
        cout<<endl<<endl;
    }
}
