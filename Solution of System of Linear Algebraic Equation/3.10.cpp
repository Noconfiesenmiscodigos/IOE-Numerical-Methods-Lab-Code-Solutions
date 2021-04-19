/*WAP to find Solution of System of Linear Algebraic Equation with Matrix Inverse with Gauss Jordan Method.*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#define pi 3.14159265358979323846264338327950288419716939937510
#define e 2.71828182845904523536028747135266249775724709369995
using namespace std;
double a[3][4],b[3][3];
int i,j;
void get_matrix()
{
    cout<<"\n\t\tMATRIX INVERSE BY GAUSS JORDAN METHOD";
    cout<<"\n\n Enter 3*3 matrix";
    cout<<"\n\n a11x + a12y + a13z";
    cout<<"\n\n a21x + a22y + a23z";
    cout<<"\n\n a31x + a32y + a33z";
    for(i=0; i<3; i++)
    {
        cout<<endl<<endl;
        for(j=0; j<3; j++)
        {
            cout<<" Enter a["<<i+1<<"]["<<j+1<<"]\t";
            cin>>a[i][j];
            b[i][j]=0;
        }
        b[i][i]=1;
    }
    cout<<"\n\n************************************************************************************************************************************************************************\n";
    cout<<"************************************************************************************************************************************************************************\n\n";
}
void print_matrix()
{
    cout<<"\n\n "<<setw(9)<<setprecision(9)<<a[0][0]<<"\t"<<setw(9)<<setprecision(9)<<a[0][1]<<"\t"<<setw(9)<<setprecision(9)<<a[0][2];
    cout<<"\n\n "<<setw(9)<<setprecision(9)<<a[1][0]<<"\t"<<setw(9)<<setprecision(9)<<a[1][1]<<"\t"<<setw(9)<<setprecision(9)<<a[1][2];
    cout<<"\n\n "<<setw(9)<<setprecision(9)<<a[2][0]<<"\t"<<setw(9)<<setprecision(9)<<a[2][1]<<"\t"<<setw(9)<<setprecision(9)<<a[2][2];
    cout<<"\n\n************************************************************************************************************************************************************************\n\n";
}
void print_gauss_jordan_matrix()
{
    cout<<"\n\n "<<setw(9)<<setprecision(9)<<a[0][0]<<"\t"<<setw(9)<<setprecision(9)<<a[0][1]<<"\t"<<setw(9)<<setprecision(9)<<a[0][2];
    cout<<"\t  : "<<setw(9)<<setprecision(9)<<b[0][0]<<"\t"<<setw(9)<<setprecision(9)<<b[0][1]<<"\t"<<setw(9)<<setprecision(9)<<b[0][2];
    cout<<"\n\n "<<setw(9)<<setprecision(9)<<a[1][0]<<"\t"<<setw(9)<<setprecision(9)<<a[1][1]<<"\t"<<setw(9)<<setprecision(9)<<a[1][2];
    cout<<"\t  : "<<setw(9)<<setprecision(9)<<b[1][0]<<"\t"<<setw(9)<<setprecision(9)<<b[1][1]<<"\t"<<setw(9)<<setprecision(9)<<b[1][2];
    cout<<"\n\n "<<setw(9)<<setprecision(9)<<a[2][0]<<"\t"<<setw(9)<<setprecision(9)<<a[2][1]<<"\t"<<setw(9)<<setprecision(9)<<a[2][2];
    cout<<"\t  : "<<setw(9)<<setprecision(9)<<b[2][0]<<"\t"<<setw(9)<<setprecision(9)<<b[2][1]<<"\t"<<setw(9)<<setprecision(9)<<b[2][2];
    cout<<"\n\n************************************************************************************************************************************************************************\n\n";
}
void correction_R1()
{
  if (a[0][0]==0)
    {
        cout<<"\n\n Invalid values!!!";
        cout<<"\n\n Interchange rows or column and enter again!!!\n\n";
        exit(1);
    }
    cout<<"\n\n R1 = R1 / "<<a[0][0]<<endl;
    a[0][1]=a[0][1]/a[0][0];
    a[0][2]=a[0][2]/a[0][0];
    b[0][0]=b[0][0]/a[0][0];
    b[0][1]=b[0][1]/a[0][0];
    b[0][2]=b[0][2]/a[0][0];
    a[0][0]=1;
    print_gauss_jordan_matrix();
}
void correction_R2()
{
    if (a[1][1]==0)
    {
        cout<<"\n\n Invalid values!!!";
        cout<<"\n\n Interchange rows or column and enter again!!!\n\n";
        exit(1);
    }
    cout<<"\n\n R2 = R2 / "<<a[1][1]<<endl;
    a[1][2]=a[1][2]/a[1][1];
    b[1][0]=b[1][0]/a[1][1];
    b[1][1]=b[1][1]/a[1][1];
    b[1][2]=b[1][2]/a[1][1];
    a[1][1]=1;
    print_gauss_jordan_matrix();
}
void correction_R3()
{
    if (a[2][2]==0)
    {
        cout<<"\n\n Invalid values!!!";
        cout<<"\n\n Interchange rows or column and enter again!!!\n\n";
        exit(1);
    }
    cout<<"\n\n R3 = R3 / "<<a[2][2]<<endl;
    b[2][0]=b[2][0]/a[2][2];
    b[2][1]=b[2][1]/a[2][2];
    b[2][2]=b[2][2]/a[2][2];
    a[2][2]=1;
    print_gauss_jordan_matrix();
}
int main()
{
    double x,y,z;
    cout.precision(9);
    while(1)
    {
        get_matrix();
        print_matrix();
        print_gauss_jordan_matrix();
        correction_R1();
        cout<<"\n\n R2 = R2 - ("<<a[1][0]<<"/"<<a[0][0]<<") * R1\n\n";
        cout<<" R3 = R3 - ("<<a[2][0]<<"/"<<a[0][0]<<") * R1\n\n";
        a[1][1]=a[1][1]-a[1][0]*a[0][1];//R2
        a[1][2]=a[1][2]-a[1][0]*a[0][2];
        b[1][0]=b[1][0]-a[1][0]*b[0][0];
        b[1][1]=b[1][1]-a[1][0]*b[0][1];
        b[1][2]=b[1][2]-a[1][0]*b[0][2];
        a[1][0]=0;
        a[2][1]=a[2][1]-a[2][0]*a[0][1];//R3
        a[2][2]=a[2][2]-a[2][0]*a[0][2];
        b[2][0]=b[2][0]-a[2][0]*b[0][0];
        b[2][1]=b[2][1]-a[2][0]*b[0][1];
        b[2][2]=b[2][2]-a[2][0]*b[0][2];
        a[2][0]=0;
        print_gauss_jordan_matrix();
        correction_R2();
        cout<<"\n\n R3 = R3 - ("<<a[2][1]<<"/"<<a[1][1]<<") * R2\n\n";
        a[2][2]=a[2][2]-a[2][1]*a[1][2];//R3
        b[2][0]=b[2][0]-a[2][1]*b[1][0];
        b[2][1]=b[2][1]-a[2][1]*b[1][1];
        b[2][2]=b[2][2]-a[2][1]*b[1][2];
        a[2][1]=0;
        print_gauss_jordan_matrix();
        correction_R3();
        cout<<"\n\n R1 = R1 - ("<<a[0][2]<<"/"<<a[2][2]<<") * R3\n\n";
        cout<<"\n\n R2 = R2 - ("<<a[1][2]<<"/"<<a[2][2]<<") * R3\n\n";
        b[1][0]=b[1][0]-a[1][2]*b[2][0];//R2
        b[1][1]=b[1][1]-a[1][2]*b[2][1];
        b[1][2]=b[1][2]-a[1][2]*b[2][2];
        b[0][0]=b[0][0]-a[0][2]*b[2][0];//R2
        b[0][1]=b[0][1]-a[0][2]*b[2][1];
        b[0][2]=b[0][2]-a[0][2]*b[2][2];
        a[0][2]=0;
        a[1][2]=0;
        print_gauss_jordan_matrix();
        cout<<"\n\n R1 = R1 - ("<<a[0][1]<<"/"<<a[1][1]<<") * R2\n\n";
        b[0][0]=b[0][0]-a[0][1]*b[1][0];//R1
        b[0][1]=b[0][1]-a[0][1]*b[1][1];
        b[0][2]=b[0][2]-a[0][1]*b[1][2];
        a[0][1]=0;
        print_gauss_jordan_matrix();
        cout<<"\n\n Matrix inverse = ";
        for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
                a[i][j]=b[i][j];
            }
        }
        print_matrix();
        cout<<"\n\n************************************************************************************************************************************************************************\n";
        cout<<"************************************************************************************************************************************************************************\n\n";
    }
    return 0;
}
