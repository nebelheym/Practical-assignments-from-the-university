#include <iostream>
using namespace std;
int main()
{
    int n = 10;
    int a[n], tmp, sum;
    for(int i = 0; i < n; i++)
    {
        cout << "Enter a" << i+1 << ":" << endl;
        cin >> a[i];
    }
    for(int i = 0; i < n - 1; ++i)
    {
        for(int j = 0; j < n - 1; ++j)
        {
            if(a[j + 1] < a[j])
            {
                tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
    }
   //cout<<"Array after bubble sort:"<<endl;
   // for(int i = 0;i < n; i++)
   //{
   //    cout<<"a["<<i<<"]="<<a[i]<<endl;
   //}

    for(int i = 0; i < n; i++)
    {
        //cout << a[i] << " " << a[n-i-1] << endl;
        sum = a[i] + a[n - i - 1];
        cout << "sum = " << sum << endl;
    }
    return 0;
}