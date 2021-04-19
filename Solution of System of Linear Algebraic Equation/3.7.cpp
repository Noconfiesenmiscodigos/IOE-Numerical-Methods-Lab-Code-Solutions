/*WAP to find Solution of System of Linear Algebraic Equation with Crout’s Method (LU Factorization/Triangular Method).*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#define pi 3.14159265358979323846264338327950288419716939937510
#define e 2.71828182845904523536028747135266249775724709369995
using namespace std;
double a[3][4],l[3][3],u[3][3];
int i,j;
void get_matrix()
{
    cout<<"\n\t\tCrout's Method (LU Factorization/Triangular Method).";
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
    double d,x,y,z,v1,v2,v3;
    cout.precision(9);
    while(1)
    {
        get_matrix();
        print_matrix();
        u[0][0]=1;
        u[1][1]=1;
        u[2][2]=1;
        u[1][0]=0;
        u[2][0]=0;
        u[2][1]=0;
        l[0][1]=0;
        l[0][2]=0;
        l[1][2]=0;
        l[0][0]=a[0][0];
        u[0][1]=a[0][1]/l[0][0];
        u[0][2]=a[0][2]/l[0][0];
        l[1][0]=a[1][0];
        l[1][1]=a[1][1]-l[1][0]*u[0][1];
        u[1][2]=(a[1][2]-l[1][0]*u[0][2])/l[1][1];
        l[2][0]=a[2][0];
        l[2][1]=a[2][1]-l[2][0]*u[0][1];
        l[2][2]=a[2][2]-l[2][0]*u[0][2]-l[2][1]*u[1][2];
        cout<<"\n\n A = LU";
        for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
              a[i][j]=l[i][j];
            }
        }
        cout<<"\n\n L = ";
        print_matrix();
        cout<<"\n\n U = ";
        for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
              a[i][j]=u[i][j];
            }
        }
        print_matrix();
        v1=a[0][3]/l[0][0];
        v2=(a[1][3]-l[1][0]*v1)/l[1][1];
        v3=(a[2][3]-l[2][0]*v1-l[2][1]*v2)/l[2][2];
        cout<<"\n\n A = LU";
        cout<<"\n\n AX = B";
        cout<<"\n\n LUX = B";
        cout<<"\n\n UX = V";
        cout<<"\n\n LV = B";
        cout<<"\n\n v1 = "<<v1;
        cout<<"\n\n v2 = "<<v2;
        cout<<"\n\n v3 = "<<v3;
        a[0][3]=v1;
        a[1][3]=v2;
        a[2][3]=v3;
        cout<<"\n\n So, Original System becomes: ";
        for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
              a[i][j]=u[i][j];
            }
        }
        print_matrix();
        z=v3;
        y=v2-u[1][2]*z;
        x=v1-u[0][1]*y-u[0][2]*z;
        cout<<" x = "<<x;
        cout<<"\n\n y = "<<y;
        cout<<"\n\n z = "<<z;
        cout<<"\n\n************************************************************************************************************************************************************************\n\n";
    }
    return 0;
}
