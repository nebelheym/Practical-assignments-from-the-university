#include <iostream>
using namespace std;
int main()
{
    double A[2], B[2], C[2], a, b, c, p, Wa, R, S;
    cout << "Enter Ax, Ay:" << endl;
    cin >> A[0] >> A[1];
    cout << "Enter Bx, By" << endl;
    cin >> B[0] >> B[1];
    cout << "Enter Cx, Cy" << endl;
    cin >> C[0] >> C[1];
    a = sqrt((B[0]-A[0])*(B[0]-A[0]) + (B[1]-A[1])*(B[1]-A[1]));
    b = sqrt((C[0]-B[0])*(C[0]-B[0]) + (C[1]-B[1])*(C[1]-B[1]));
    c = sqrt((A[0]-C[0])*(A[0]-C[0]) + (A[1]-C[1])*(A[1]-C[1]));
    p = (a + b + c) / 2;
    Wa = (2/(b+c)) * sqrt(b*c*p*(p-a));
    S = sqrt(p*(p-a)*(p-b)*(p-c));
    R = (a*b*c)/(4*S);
    cout << "Wa =" << " " << Wa << endl;
    cout << "S =" << " " << S << endl;
    cout << "R =" << " " << R << endl;
    return 0;
}