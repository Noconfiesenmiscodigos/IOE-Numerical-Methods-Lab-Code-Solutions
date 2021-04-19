/*WAP to find Solution of System of Linear Algebraic Equation with Gauss Elimination with Partial Pivoting Method.*/
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
    cout<<"\nGAUSS ELIMINATION METHOD WITH PARTIAL PIVOTING";
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
int main()
{
    double x,y,z;
    int i,j;
    while(1)
    {
        get_matrix();
        cout<<"\n\n Original Matrix";
        print_matrix();
        if (abs(a[0][0])<abs(a[1][0]))//partial pivoting part
        {
            i=1;
        }
        if (abs(a[0][0])<abs(a[2][0]))//partial pivoting part
        {
            i=2;
        }
        if (abs(a[0][0])<abs(a[i][0]))//partial pivoting part
        {
            x=a[0][0];
            a[0][0]=a[i][0];
            a[i][0]=x;
            x=a[0][1];
            a[0][1]=a[i][1];
            a[i][1]=x;
            x=a[0][2];
            a[0][2]=a[i][2];
            a[i][2]=x;
            x=a[0][3];
            a[0][3]=a[i][3];
            a[i][3]=x;
            cout<<"\n\n After partial pivoting matrix looks like this ";
            print_matrix();
        }
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
        if (abs(a[1][1])<abs(a[2][1]))//partial pivoting part
        {
            i=2;
            x=a[1][1];
            a[1][1]=a[i][1];
            a[i][1]=x;
            x=a[1][2];
            a[1][2]=a[i][2];
            a[i][2]=x;
            x=a[1][3];
            a[1][3]=a[i][3];
            a[i][3]=x;
            cout<<"\n\n After partial pivoting matrix looks like this ";
            print_matrix();
        }
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

