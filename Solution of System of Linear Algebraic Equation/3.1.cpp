/*WAP to check consistency of System of Linear Algebraic Equation.*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#define pi 3.14159265358979323846264338327950288419716939937510
#define e 2.71828182845904523536028747135266249775724709369995
using namespace std;
double a[3][4];
void get_matrix()
{
    int i,j;
    cout<<"\n\t\tCONSISTENCY OF SYSTEM OF LINEAR ALGEBRIAC EQUATION";
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
        cout<<"\n Enter b"<<i+1<<"\t";
        cin>>a[i][j];
    }
    cout<<"\n\n************************************************************************************************************************************************************************\n\n";
}
void print_matrix()
{
    cout<<"\n\n "<<setw(9)<<setprecision(9)<<a[0][0]<<"\t"<<setw(9)<<setprecision(9)<<a[0][1]<<"\t"<<setw(9)<<setprecision(9)<<a[0][2]<<"\t"<<setw(9)<<setprecision(9)<<a[0][3];
    cout<<"\n\n "<<setw(9)<<setprecision(9)<<a[1][0]<<"\t"<<setw(9)<<setprecision(9)<<a[1][1]<<"\t"<<setw(9)<<setprecision(9)<<a[1][2]<<"\t"<<setw(9)<<setprecision(9)<<a[1][3];
    cout<<"\n\n "<<setw(9)<<setprecision(9)<<a[2][0]<<"\t"<<setw(9)<<setprecision(9)<<a[2][1]<<"\t"<<setw(9)<<setprecision(9)<<a[2][2]<<"\t"<<setw(9)<<setprecision(9)<<a[2][3];
    cout<<"\n\n************************************************************************************************************************************************************************\n\n";
}
double determinant(double b00,double b01,double b02,double b10,double b11,double b12,double b20,double b21,double b22)
{
    double det3;
    det3 = b00*(b11*b22-b12*b21)-b01*(b10*b22-b12*b20)+b02*(b10*b21-b11*b20);
    return det3;
}
int main()
{
    double d,x,y,z;
    cout.precision(9);
    while(1)
    {
        get_matrix();
        print_matrix();
        d = determinant(a[0][0],a[0][1],a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2]);
        x = determinant(a[0][3],a[0][1],a[0][2],a[1][3],a[1][1],a[1][2],a[2][3],a[2][1],a[2][2]);
        y = determinant(a[0][0],a[0][3],a[0][2],a[1][0],a[1][3],a[1][2],a[2][0],a[2][3],a[2][2]);
        z = determinant(a[0][0],a[0][1],a[0][3],a[1][0],a[1][1],a[1][3],a[2][0],a[2][1],a[2][3]);
        cout<<"\n\n |A| = "<<setw(9)<<setprecision(9)<<d;
        cout<<"\n\n|del x| = "<<setw(9)<<setprecision(9)<<x;
        cout<<"\n\n|del y| = "<<setw(9)<<setprecision(9)<<y;
        cout<<"\n\n|del z| = "<<setw(9)<<setprecision(9)<<y<<endl<<endl;
        if (d!=0)
        {
            x = x/d;
            y = y/d;
            z = z/d;
            cout<<" System has unique Solution & is consistent."<<endl<<endl;
            cout<<" x = |del x|/|A| = "<<setw(9)<<setprecision(9)<<x<<endl<<endl;
            cout<<" y = |del y|/|A| = "<<setw(9)<<setprecision(9)<<y<<endl<<endl;
            cout<<" z = |del z|/|A| = "<<setw(9)<<setprecision(9)<<z<<endl<<endl;
        }
        else
        {
            if ((x==0)&&(y==0)&&(z==0))
            {
                cout<<" System has infinite number of Solution & is consistent."<<endl<<endl;
            }
           else
            {
               cout<<" System has no Solution & is inconsistent."<<endl<<endl;
            }
        }
        cout<<"\n\n************************************************************************************************************************************************************************\n\n";
    }
    return 0;
}
