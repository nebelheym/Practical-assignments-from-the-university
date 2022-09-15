#include <iostream>
using namespace std;
int main()
{
    int start_hours, start_minutes, start_seconds;

    cout << "Enter start time:" << endl;
    cout << "Enter start hours:" << endl;
    cin >> start_hours;
    cout << "Enter start minutes:" << endl;
    cin >> start_minutes;
    cout << "Enter start seconds:" << endl;
    cin >> start_seconds;
    cout << "Task start time is:" << " " << start_hours << ":" << start_minutes << ":" << start_seconds << endl;

    if (start_hours >=  0 && start_hours < 24)
    {
        if (start_minutes >= 0 && start_minutes < 60)
        {
            if (start_seconds >= 0 && start_seconds < 60)
            {
                int task_hours, task_minutes, task_seconds;

                cout << "Enter task time:" << endl;
                cout << "Enter task hours:" << endl;
                cin >> task_hours;
                cout << "Enter task minutes:" << endl;
                cin >> task_minutes;
                cout << "Enter task seconds:" << endl;
                cin >> task_seconds;
                cout << "Task time is:" << " " << task_hours << ":" << task_minutes << ":" << task_seconds << endl;

                if (task_hours >= 0 && task_hours < 24)
                {
                    if (task_minutes >= 0 && task_minutes < 60)
                    {
                        if (task_seconds >= 0 && task_seconds < 60)
                        {
                            int end_hours, end_minutes, end_seconds, add_hours, add_minutes, add_seconds;

                            add_hours = 0;
                            add_minutes = 0;
                            add_seconds = 0;

                            end_seconds = start_seconds + task_seconds;
                            if(end_seconds >= 60)
                            {
                                end_seconds = end_seconds - 60;
                                add_minutes += 1;
                            }

                            end_minutes = start_minutes + task_minutes;
                            if(end_minutes >= 60)
                            {
                                end_minutes = end_minutes - 60;
                                add_hours += 1;
                            }

                            end_hours = start_hours + task_hours;
                            if(end_hours >= 24)
                            {
                                end_hours = end_hours - 24;
                            }

                            end_minutes = end_minutes + add_minutes;
                            if(end_minutes >= 60)
                            {
                                end_minutes = end_minutes - 60;
                                add_hours += 1;
                            }
                            end_seconds = end_seconds + add_seconds;
                            end_hours = end_hours + add_hours;

                            cout << "Task end time is:" << " " << end_hours << ":" << end_minutes << ":" << end_seconds;

                        }
                        else
                        {
                            cout << "Error. One minute cannot be more than 60 seconds.";
                        }
                    }
                    else
                    {
                        cout << "Error. One hour cannot be more than 60 minutes.";
                    }
                }
                else
                {
                    cout << "Error. There are only 24 hours in a day.";
                }

            }
            else
            {
                cout << "Error. One minute cannot be more than 60 seconds.";
            }
        }
        else
        {
            cout << "Error. One hour cannot be more than 60 minutes.";
        }
    }
    else
    {
        cout << "Error. There are only 24 hours in a day.";
    }
    return 0;
}
