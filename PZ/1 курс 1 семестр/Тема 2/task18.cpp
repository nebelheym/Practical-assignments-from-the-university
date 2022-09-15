#include <iostream>
using namespace std;

int main() {
    int Ivanov, Petrov, Sidorov, m1, m2, m3, n1, n2, n3, p1, p2, p3;
    cout << "How many points did Ivanov score in the first round?" << endl;
    cin >> m1;
    cout << "How many points did Ivanov score in the second round?" << endl;
    cin >> n1;
    cout << "How many points did Ivanov score in the third round?" << endl;
    cin >> p1;
    cout << "How many points did Petrov score in the first round?" << endl;
    cin >> m2;
    cout << "How many points did Petrov score in the second round?" << endl;
    cin >> n2;
    cout << "How many points did Petrov score in the third round?" << endl;
    cin >> p2;
    cout << "How many points did Sidorov score in the first round?" << endl;
    cin >> m3;
    cout << "How many points did Sidorov score in the second round?" << endl;
    cin >> n3;
    cout << "How many points did Sidorov score in the third round?" << endl;
    cin >> p3;
    Ivanov = m1 + n1 + p1;
    Petrov = m2 + n2 + p2;
    Sidorov = m3 + n3 + p3;
    if(Sidorov > Petrov && Sidorov>Ivanov)
    {
        cout << "Sidorov became the winner and scored " << Sidorov << " points";
    }
    else if(Petrov>Sidorov && Petrov>Ivanov)
    {
        cout << "Petrov became the winner and scored " << Petrov << " points";
    }
    else
    {
        cout << "Ivanov became the winner and scored " << Ivanov << " points";
    }
    return 0;
}