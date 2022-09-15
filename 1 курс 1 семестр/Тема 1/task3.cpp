#include <iostream>
using namespace std;
int main()
{
    double cost, seconds, minutes;
    cout << "Enter the cost of a minute of telephone conversation:" << endl;
    cin >> cost;
    cout << "How long is a conversation in minutes?:" << endl;
    cin >> minutes;

    if (minutes >= 0 && minutes < 60)
    {
        cout << "How long is a conversation in seconds?:" << endl;
        cin >> seconds;
        if (seconds >= 0 && seconds < 60)
        {
            double cost_per_second = cost / 60;
            double call_cost, call_lenght;
            call_lenght = seconds + minutes * 60;
            call_cost = call_lenght * cost_per_second;
            cout << "The cost of a call long " << minutes << " minutes and " << seconds << " seconds will cost " << call_cost << endl;
        }
        else
        {
            cout << "Error.";
        }

    }
    else
    {
        cout << "Error.";
    }

    return 0;
}