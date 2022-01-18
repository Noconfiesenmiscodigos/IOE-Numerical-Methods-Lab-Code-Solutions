/* Gauss Seidal method */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define N 3
int main()
{
    float a[N][N+1],x[N],aerr,maxerr, t,s,err;
    int i,j,itr,maxitr;
    /* first initializing the array x */
    for (i=0; i<N; i++) x[i]=0;
    cout << "Enter the elements of the"
         << "augmented matrix rowwise" << endl;
    for (i=0; i<N; i++)
        for (j=0; j<N+1; j++)
            cin >> a[i][j];
    cout << "Enter the allowed error,"
         << "maximum iterations" << endl;
    cin >> aerr >> maxitr;
    cout << fixed;
    cout << "Iteration" << setw(6) << "x[1]"
         << setw(11) << "x[2]"
         << setw(11) << "x[3]" << endl;
    for (itr=1; itr<=maxitr; itr++)
    {
        maxerr = 0;
        for (i=0; i<N; i++)
        {
            s = 0;
            for (j=0; j<N; j++)
                if (j!=i) s += a[i][j]*x[j];
            t = (a[i][N]-s)/a[i][i];
            err = fabs(x[i]-t);
            if (err > maxerr) maxerr = err;
            x[i] = t;
        }
        cout << setw(5) << itr;
        for (i=0; i<N; i++)
            cout << setw(11) << setprecision(4) << x[i];
        cout << endl;
        if (maxerr < aerr)
        {
            cout << "Converges in" << setw(3) << itr
                 << "iterations" << endl;
            for (i=0; i<N; i++)
                cout << "x[" << setw(3) << i+1 << "] = "
                     << setw(7) << setprecision(4) << x[i]
                     << endl;
            return 0;
        }
    }
    cout << "Solution does not converge,"
         << "iterations not sufficient" << endl;
    return 1;
}

/*
Enter the elements of augmented matrix rowwise
20 1 -2 17
3 20 -1 -18
2 - 3 20 25
Enter the allowed error, maximum iterations
.0001 10
Iteration X(1) X(2) X(3)
1 0.8500 - 1.0275 1.0109
2 1.0025 - 0.9998 0.9998
3 1.0000 - 1.0000 1.0000
4 1.0000 - 1.0000 1.0000
Converges in 4 iterations
X[1] = 1.0000
X[2] = -1.0000
X[3] = 1.0000
*/
/*
Enter the elements of the augmented matrix rowwise
10 -2 -1 -1 3
-2 10 -1 -1 15
-1 -1 10 -2 27
-1 -1 -2 10 -9
Enter the allowed error, maximum iterations
.0001 15
Iteration
1
2
3
4
5
6
7
x[1]
0.3000
0.8869
0.9836
0.9968
0.9994
0.9999
1.0000
x[2]
1.5600
1.9523
1.9899
1.9982
1.9997
1.9999
2.0000
x[3]
2.8860
2.9566
2.9924
2.9987
2.9998
3.0000
3.0000
x[4]
-0.1368
-0.0248
-0.0042
-0.0008
-0.0001
-0.0000
-0.0000
Converges in 7 iterations
x[ 1] = 1.0000
x[ 2] = 2.0000
x[ 3] = 3.0000
x[ 4] = 0.0000
*/