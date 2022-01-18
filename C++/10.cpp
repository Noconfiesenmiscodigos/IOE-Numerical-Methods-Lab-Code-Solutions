/* Factorization method */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define N 3
typedef float matrix[N][N];
matrix l,u,a;
float b[N],x[N],v[N];
void urow(int i)
{
    float s;
    int j,k;
    for (j=i; j<N; j++)
    {
        s = 0;
        for (k=0; k<N-1; k++)
            s += u[k][j]*l[i][k];
        u[i][j] = a[i][j]-s;
    }
}
void lcol(int j)
{
    float s;
    int i,k;
    for (i=j+1; i<N; i++)
    {
        s = 0;
        for (k=0; k<=j-1; k++)
            s += u[k][j]*l[i][k];
        l[i][j] = (a[i][j]-s)/u[j][j];
    }
}
void printmat(matrix x)
{
    int i,j;
    for (i=0; i<N; i++)
    {
        for (j=0; j<N; j++)
            cout << setw(8) << setprecision(4) << x[i][j];
        cout << endl;
    }
}
int main()
{
    int i,j,m;
    float s;
    cout << "Enter the elements of augmented"
         << " matrix rowwise" << endl;
    for (i=0; i<N; i++)
    {
        for (j=0; j<N; j++)
            cin >> a[i][j];
        cin >> b[i];
    }
    cout << fixed;
    /* now calculating the elements of l and u */
    for (i=0; i<N; i++)
        l[i][i] = 1.0;
    for (m=0; m<N; m++)
    {
        urow(m);
        if (m < N-1) lcol(m);
    }
    /* now printing the elements of l and u */
    cout << setw(14) << "U" << endl;
    printmat(u);
    cout << setw(14) << "L" << endl;
    printmat(l);
    /* now solving LV=B
    by forward substitution */
    for (i=0; i<N; i++)
    {
        s = 0;
        for (j=0; j<=i-1; j++)
            s += l[i][j]*v[j];
        v[i] = b[i]-s;
    }
    /* now solving UX=V
    by backward substitution */
    for (i=N-1; i>=0; i--)
    {
        s = 0;
        for (j=i+1; j<N; j++)
            s += u[i][j]*x[j];
        x[i] = (v[i]-s)/u[i][i];
    }
    /* printing the results */
    cout << "The solution is:-" << endl;
    for (i=0; i<N; i++)
        cout << "x[" << setw(3) << i+1 << "] = "
             << setw(6) << setprecision(4)
             << x[i] << endl;
    return 0;
}

/*
Enter the elements of augmented matrix rowwise
3 2 7 4
2 3 1 5
3 4 1 7
U
3.0000
0.0000
0.0000
2.0000
1.6667
0.0000
7.0000
-3.6667
-1.6000
L
1.0000
0.6667
1.0000
0.0000
1.0000
1.2000
0.0000
0.0000
1.0000
The solution is:
x[1] = 0.8750
x[2] = 1.1250
x[3] = - 0.1250
*/

/*
Enter the elements of augmented matrix rowwise
10 -7 3 5 6
-6 8 -1 -4 5
3 1 4 11 2
5 -9 -2 4 7
U
10.0000 -7.0000 3.0000 5.0000
0.0000 3.8000 0.8000 -1.0000
0.0000 0.0000 2.4474 10.3158
0.0000 0.0000 0.0000 9.9247
L
1.0000 0.0000 0.0000 0.0000
-0.6000 1.0000 0.0000 0.0000
0.3000 0.8158 1.0000 0.0000
0.5000 -1.4474 -0.9570 1.0000
The solution is:-
x[ 1] = 5.0000
x[ 2] = 4.0000
x[ 3] = -7.0000
x[ 4] = 1.0000
*/
