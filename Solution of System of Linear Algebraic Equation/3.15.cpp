/*WAP to find Eigen Values by Power Method.*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#define pi 3.14159265358979323846264338327950288419716939937510
#define e 2.71828182845904523536028747135266249775724709369995
using namespace std;
double a[3][3],x,y,z,px,py,pz,eigen,peigen,err;
int counter,error,k;
void get_matrix()
{
    int i,j;
    cout<<"\n\t\tEIGEN VALUE BY POWER METHOD";
    cout<<"\n\n To find Dominant Eigen value & Dominant Eigen vector enter your system.";
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
        }
    }
    cout<<"\n\n************************************************************************************************************************************************************************\n\n";
}
void print_matrix()
{
    cout<<"\n\n "<<setw(9)<<setprecision(9)<<a[0][0]<<"\t"<<setw(9)<<setprecision(9)<<a[0][1]<<"\t"<<setw(9)<<setprecision(9)<<a[0][2];
    cout<<"\n\n "<<setw(9)<<setprecision(9)<<a[1][0]<<"\t"<<setw(9)<<setprecision(9)<<a[1][1]<<"\t"<<setw(9)<<setprecision(9)<<a[1][2];
    cout<<"\n\n "<<setw(9)<<setprecision(9)<<a[2][0]<<"\t"<<setw(9)<<setprecision(9)<<a[2][1]<<"\t"<<setw(9)<<setprecision(9)<<a[2][2];
    cout<<"\n\n************************************************************************************************************************************************************************\n\n";
}
void find_eigenvalue()
{
  cout<<endl<<endl<<" "<<counter;
  px=x;
  py=y;
  pz=z;
  peigen=eigen;
  x=a[0][0]*px+a[0][1]*py+a[0][2]*pz;
  y=a[1][0]*px+a[1][1]*py+a[1][2]*pz;
  z=a[2][0]*px+a[2][1]*py+a[2][2]*pz;
  if ((abs(x)>abs(y)) && (abs(x)>abs(z))) eigen=abs(x);
  if ((abs(y)>abs(x)) && (abs(y)>abs(z))) eigen=abs(y);
  if ((abs(z)>abs(x)) && (abs(z)>abs(y))) eigen=abs(z);
  x=x/eigen;
  y=y/eigen;
  z=z/eigen;
  cout<<"\t\t"<<eigen<<"\t   "<<"[ "<<x<<", "<<y<<", "<<z<<" ]'";
  err=(abs(px-x)+abs(py-y)+abs(pz-z)+abs(peigen-eigen))/4;
  cout<<"\t\t"<<err;
}
int main()
{
    while(1)
    {
        get_matrix();
        cout<<"\nEnter tolerance (10^-k)";
        cout<<"\nEnter k: ";
        cin>>k;
        cout<<"\n\n Y = AX";
        cout<<"\n\n A = ";
        print_matrix();
        cout<<"\n\n************************************************************************************************************************************************************************\n\n";
        cout<<"\n\n SN\t   Eigen Value"<<"\t\t Eigen Vector"<<"\t\tError \n\n";
        counter=0;
        error=10;
        x=1.0;
        eigen=1.0;
        while (error>9)
        {
            counter++;
            find_eigenvalue();
            error = (int)trunc(err*pow(10,k));//error is in order of 10^k
        }
        cout<<"\n\n\n\n************************************************************************************************************************************************************************\n\n";
        cout<<endl<<endl;
    }
}
