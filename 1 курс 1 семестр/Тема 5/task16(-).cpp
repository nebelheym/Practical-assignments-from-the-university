#include <iostream>
using namespace std;
int main() {
    const int m = 10;
    int x[m], aStart[m], aFinish[m], b[m], j = 0, k, s = 0, f = 0;
    for(int i = 1; i<=m; i++)
    {
        cout << "Enter x" << i << ": " << endl;
        cin >> x[i];
    }
    for(int i = 1; i<=m; i++)
    {
        if(i%2 == 0)
            if(x[i+1] < x[i])
            {
                b[j++] = x[i];
                if(aStart[s] == 0)
                    aStart[s] = i;
            }
        else
            {
            aFinish[f++] = i;
            s++;
            }
        if(i%2 != 0 && i != 0)
            if(x[i+1] > x[i])
            {
                b[j++] = x[i];
                if(aStart[s] == 0)
                    aStart[s] = i;
            }
        else
            {
                aFinish[f++] = i;
                s++;
            }
    }
    for(int i = 0; i<s; i++)
        cout << "s" << i << " = " << s << endl;
    for(int i = 0; i<f; i++)
        cout << "f" << i << " = " << f << endl;
    if(aStart[0] == 0)
        cout << "No sequence";
    else
        for(int i = 0; i<j; i++)
            cout << "b" << i << ": " << b[i] << endl;
    return 0;
}
