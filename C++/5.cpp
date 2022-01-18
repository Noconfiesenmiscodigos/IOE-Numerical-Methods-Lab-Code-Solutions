/* Newton Raphson Method */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
float f(float x)
{
    return x*log10(x)-1.2;
}
float df(float x)
{
    return log10(x) + 0.43429;
}
int main()
{
    int itr,maxitr;
    float h,x0,x1,aerr;
    cout << "Enter x0,allowed error,"
         << "maximum iterations" << endl;
    cin >> x0 >> aerr >> maxitr;
    cout << fixed;
    for (itr=1; itr<=maxitr; itr++)
    {
        h = f(x0)/df(x0);
        x1 = x0-h;
        cout << "Iteration no." << setw(3) << itr
             << "X = " << setw(9) << setprecision(6)
             << x1 << endl;
        if (fabs(h) < aerr)
        {
            cout << "After" << setw(3) << itr
                 << "iterations, root = "
                 << setw(8) << setprecision(6) << x1;
            return 0;
        }
        x0 = x1;
    }
    cout << "Iterations not sufficient,"
         << "solution does not converge" << endl;
    return 1;
}
/*
Enter x0, allowed error, maximum iterations
2.000001 10
Iteration No. 1 X = 2.813170
Iteration No. 2 X = 2.741109
Iteration No. 3 X = 2.740646
Iteration No. 4 X = 2.740646
After 4 iterations, root = 2.740646
*/
