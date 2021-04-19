/*WAP to find Solution of System of Linear Algebraic Equation with Gauss Elimination Method.*/
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
    cout<<"\n\t\tGAUSS ELIMINATION METHOD";
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
        cout<<"\n\n GAUSS ELIMINATION METHOD fails if any diagonal element is zero!!!\n\n";
        exit(1);
    }
    cout<<"\n\n************************************************************************************************************************************************************************\n";
    cout<<"************************************************************************************************************************************************************************\n\n";
}
void print_matrix()
{
    cout<<"\n\n "<<setw(9)<<setprecision(9)<<a[0][0]<<"\t"<<setw(9)<<setprecision(9)<<a[0][1]<<"\t"<<setw(9)<<setprecision(9)<<a[0][2]<<"\t"<<setw(9)<<setprecision(9)<<a[0][3];
    cout<<"\n\n "<<setw(9)<<setprecision(9)<<a[1][0]<<"\t"<<setw(9)<<setprecision(9)<<a[1][1]<<"\t"<<setw(9)<<setprecision(9)<<a[1][2]<<"\t"<<setw(9)<<setprecision(9)<<a[1][3];
    cout<<"\n\n "<<setw(9)<<setprecision(9)<<a[2][0]<<"\t"<<setw(9)<<setprecision(9)<<a[2][1]<<"\t"<<setw(9)<<setprecision(9)<<a[2][2]<<"\t"<<setw(9)<<setprecision(9)<<a[2][3];
    cout<<"\n\n************************************************************************************************************************************************************************\n\n";
}
int main()
{
    double x,y,z;
    cout.precision(9);
    while(1)
    {
        get_matrix();
        print_matrix();
        cout<<"\n\n R2 = R2 - ("<<a[1][0]<<"/"<<a[0][0]<<") * R1\n\n";
        cout<<" R3 = R3 - ("<<a[2][0]<<"/"<<a[0][0]<<") * R1\n\n";
        a[1][1]=a[1][1]-(a[1][0]*a[0][1])/a[0][0];//R2
        a[1][2]=a[1][2]-(a[1][0]*a[0][2])/a[0][0];
        a[1][3]=a[1][3]-(a[1][0]*a[0][3])/a[0][0];
        a[1][0]=0;
        a[2][1]=a[2][1]-(a[2][0]*a[0][1])/a[0][0];//R3
        a[2][2]=a[2][2]-(a[2][0]*a[0][2])/a[0][0];
        a[2][3]=a[2][3]-(a[2][0]*a[0][3])/a[0][0];
        a[2][0]=0;
        print_matrix();
        cout<<"\n\n R3 = R3 - ("<<a[2][1]<<"/"<<a[1][1]<<") * R2\n\n";
        a[2][2]=a[2][2]-(a[2][1]*a[1][2])/a[1][1];//R3
        a[2][3]=a[2][3]-(a[2][1]*a[1][3])/a[1][1];
        a[2][1]=0;
        print_matrix();
        z=a[2][3]/a[2][2];
        y=(a[1][3]-a[1][2]*z)/a[1][1];
        x=(a[0][3]-a[0][2]*z-a[0][1]*y)/a[0][0];
        cout<<" x = "<<setw(9)<<setprecision(9)<<x<<endl<<endl;
        cout<<" y = "<<setw(9)<<setprecision(9)<<y<<endl<<endl;
        cout<<" z = "<<setw(9)<<setprecision(9)<<z<<endl<<endl;
        cout<<"\n\n************************************************************************************************************************************************************************\n";
        cout<<"************************************************************************************************************************************************************************\n\n";
    }
    return 0;
}
