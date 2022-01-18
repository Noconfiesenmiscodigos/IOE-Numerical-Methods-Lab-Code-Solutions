/* Gauss jordan method */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define N 4
int main()
{
    float a[N][N+1],t;
    int i,j,k;
    cout << "Enter the elements of the"
         << "augmented matrix rowwise" << endl;
    for (i=0; i<N; i++)
        for (j=0; j<N+1; j++)
            cin >> a[i][j];
    /* now calculating the values
    of x1,x2,....,xN */
    cout << fixed;
    for (j=0; j<N; j++)
        for (i=0; i<N; i++)
            if (i!=j)
            {
                t = a[i][j]/a[j][j];
                for (k=0; k<N+1; k++)
                    a[i][k] -= a[j][k]*t;
            }
    /* now printing the diagonal matrix */
    cout << "The diagonal matrix is:-" << endl;
    for (i=0; i<N; i++)
    {
        for (j=0; j<N+1; j++)
            cout << setw(9) << setprecision(4) << a[i][j];
        cout << endl;
    }
    /* now printing the results */
    cout << "The solution is:- " << endl;
    for (i=0; i<N; i++)
        cout << "x[" << setw(3) << i+1 << "] ="
             << setw(7) << setprecision(4)
             << a[i][N]/a[i][i] << endl;
    return 0;
}

/*
Enter elements of augmented matrix rowwise
10 -7 3 5 6
-6 8 -1 -4 5
3 1 4 11 2
5 -9 -2 4 7
The diagonal matrix is:-
10.0000 -0.0000 -0.0000 -0.0000 50.0000
0.0000 3.8000 -0.0000 0.0000 15.2000
-0.0000 0.0000 2.4474 0.0000 -17.1316
0.0000 -0.0000 0.0000 9.9247 9.9247
The solution is:-
X[ 1] = 5.0000
X[ 2] = 4.0000
X[ 3] = -7.0000
X[ 4] = 1.0000
*/
