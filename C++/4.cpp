/* Regula Falsi Method */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
float f(float x)
{
    return cos(x)-x*exp(x);
}
void regula (float *x, float x0, float x1,
             float fx0, float fx1, int *itr)
{
    *x = x0-((x1-x0)/(fx1-fx0))*fx0;
    ++(*itr);
    cout << "Iteration no." << setw(3) << *itr
         << "X = " << setw(7) << setprecision(5)
         << *x << endl;
}
int main()
{
    int itr=0, maxitr;
    float x0,x1,x2,x3,aerr;
    cout << "Enter the values for x0,x1,"
         << "allowed error,maximum iterations" << endl;
    cin >> x0 >> x1 >> aerr >> maxitr;
    regula(&x2,x0,x1,f(x0),f(x1),&itr);
    cout << fixed;
    do
    {
        if (f(x0)*f(x2) < 0)
            x1 = x2;
        else
            x0 = x2;
        regula(&x3,x0,x1,f(x0),f(x1),&itr);
        if (fabs(x3-x2) < aerr)
        {
            cout << "After" << itr << "iterations,"
                 << "root = " << setw(6) << setprecision(4)
                 << x3 << endl;
            return 0;
        }
        x2=x3;
    }
    while(itr < maxitr);
    cout << "Solution does not converge,"
         << "iterations not sufficient" << endl;
    return 1;
}

/*
Enter the values for x0, x1, allowed error, maximum iterations
0 1.0001 20
Iteration No. 1 X = 0.31467
Iteration No. 2 X = 0.44673
Iteration No. 3 X = 0.49402
Iteration No. 4 X = 0.50995
Iteration No. 5 X = 0.51520
Iteration No. 6 X = 0.51692
Iteration No. 7 X = 0.51748
Iteration No. 8 X = 0.51767
Iteration No. 9 X = 0.51773
After 9 iterations, root = 0.5177
*/
