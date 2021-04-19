/*WAP to find Solution of System of Linear Algebraic Equation with Cholesky Method.*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#define pi 3.14159265358979323846264338327950288419716939937510
#define e 2.71828182845904523536028747135266249775724709369995
using namespace std;
double a[3][4],l[3][3];
void get_matrix()
{
    int i,j;
    cout<<"\n\t\tCHOLESKY METHOD";
    cout<<"\n\n Condition for CHOLESKY METHOD to work: ";
    cout<<"\n\n 1. 0 <= a[1][1]";
    cout<<"\n\n 2. a[2][1]^2 <= a[1][1].a[2][2]";
    cout<<"\n\n 3. (a[3][2].a[1][1]-a[3][1].a[2][1])^2 <= (a[3][3].a[1][1]-a[2][1]^2).(a[2][2].a[1][1]-a[2][1]^2)";
    cout<<"\n\n Enter 3*3 linear equations.";
    cout<<"\n\n Enter SYMMETRIC MATRIX ";
    cout<<"\n\n a11x + a12y + a13z = b1";
    cout<<"\n\n a21x + a22y + a23z = b2";
    cout<<"\n\n a31x + a32y + a33z = b3";
    cout<<"\n\n Enter a[1][1] ";
    cin>>a[0][0];
    cout<<" Enter a[1][2] (=a[2][1]) ";
    cin>>a[0][1];
    a[1][0]=a[0][1];
    cout<<" Enter a[1][3] (=a[3][1]) ";
    cin>>a[0][2];
    a[2][0]=a[0][2];
    cout<<"\n Enter a[1][4] ";
    cin>>a[0][3];
    cout<<"\n\n Enter a[2][2] ";
    cin>>a[1][1];
    cout<<" Enter a[2][3] (=a[3][2]) ";
    cin>>a[1][2];
    a[2][1]=a[1][2];
    cout<<"\n Enter a[2][4] ";
    cin>>a[1][3];
    cout<<"\n\n Enter a[3][3] ";
    cin>>a[2][2];
    cout<<"\n Enter a[3][4] ";
    cin>>a[2][3];
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
    int i,j;
    double x,y,z,y1,y2,y3;
    cout.precision(9);
    while(1)
    {
        get_matrix();
        print_matrix();
        l[0][0]=sqrt(a[0][0]);
        l[1][0]=a[0][1]/l[0][0];
        l[0][1]=0;
        l[2][0]=a[0][2]/l[0][0];
        l[0][2]=0;
        l[1][1]=sqrt(a[1][1]-l[1][0]*l[1][0]);
        l[2][1]=(a[2][1]-l[2][0]*l[1][0])/l[1][1];
        l[1][2]=0;
        l[2][2]=sqrt(a[2][2]-l[2][0]*l[2][0]-l[2][1]*l[2][1]);
        if ((a[0][0]<0) || ((a[1][1]-l[1][0]*l[1][0])<0) || ((a[2][2]-l[2][0]*l[2][0]-l[2][1]*l[2][1])<0))
        {
            cout<<"\n\n Cholesky Method FAILS at these values.";
        }
        else
        {
            for (i=0; i<3; i++)
            {
                for (j=0; j<3; j++)
                {
                    a[i][j]=l[i][j];
                }
            }
            cout<<"\n\n A = LL'";
            cout<<"\n\n L = ";
            print_matrix();
            y1=a[0][3]/l[0][0];
            y2=(a[1][3]-l[1][0]*y1)/l[1][1];
            y3=(a[2][3]-l[2][0]*y1-l[2][1]*y2)/l[2][2];
            cout<<"\n\n AX = B";
            cout<<"\n\n LL'X = B";
            cout<<"\n\n Y = L'X";
            cout<<"\n\n LY = B";
            cout<<"\n\n y1 = "<<y1;
            cout<<"\n\n y2 = "<<y2;
            cout<<"\n\n y3 = "<<y3;
            a[0][3]=y1;
            a[1][3]=y2;
            a[2][3]=y3;
            for (i=0; i<3; i++)
            {
                for (j=0; j<3; j++)
                {
                    l[i][j]=a[j][i];
                }
            }
            cout<<"\n\n L' = ";
            for (i=0; i<3; i++)
            {
                for (j=0; j<3; j++)
                {
                    a[i][j]=l[i][j];
                }
            }
            print_matrix();
            z=y3/l[2][2];
            y=(y2-l[1][2]*z)/l[1][1];
            x=(y1-l[0][1]*y-l[0][2]*z)/l[0][0];
            cout<<"\n\n x = "<<x;
            cout<<"\n\n y = "<<y;
            cout<<"\n\n z = "<<z;
        }
        cout<<"\n\n************************************************************************************************************************************************************************\n\n";
    }
    return 0;
}

