/* Solution of Hyperbolic equation */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define XEND 5
#define TEND 5
float f(int x)
{
    return x*x*(5-x);
}
int main()
{
    float u[XEND+1][TEND+1],csqr,ust,uet;
    int i,j;
    cout << "Enter the square of 'c'" << endl;
    cin >> csqr;
    cout << "Enter the value of u(0, t)" << endl;
    cin >> ust;
    cout << "Enter the value of u("
         << XEND << ", t)" << endl;
    cin >> uet;
    cout << fixed;
    for (j=0; j<=TEND; j++)
    {
        u[0][j] = ust;
        u[XEND][j] = uet;
    }
    for (i=1; i<=XEND-1; i++)
        u[i][1] = u[i][0] = f(i);
    for (j=1; j<=TEND-1; j++)
        for (i=1; i<=XEND-1; i++)
            u[i][j+1] = u[i-1][j]+u[i+1][j]
                        -u[i][j-1];
    cout << "The values of u(i, j) are:-" << endl;
    for (j=0; j<=TEND; j++)
    {
        for (i=0; i<=XEND; i++)
            cout << setw(6) << setprecision(1)
                 << u[i][j];
        cout << endl;
    }
    return 0;
}
/*
Enter the square of "c"
16
Enter value of u(0, t)
0
Enter value of u(5, t)
0
The values of u(i, j) are:-
0.0 4.0 12.0 18.0 16.0 0.0
0.0 4.0 12.0 18.0 16.0 0.0
0.0 8.0 10.0 10.0 2.0 0.0
0.0 6.0 6.0 -6.0 -6.0 0.0
0.0 -2.0 -10.0 -10.0 -8.0 0.0
0.0 -16.0 -18.0 -12.0 -4.0 0.0
*/
