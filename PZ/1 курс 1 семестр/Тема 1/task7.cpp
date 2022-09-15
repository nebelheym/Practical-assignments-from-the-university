#include <iostream>
using namespace std;
int main()
{
    double first_cost, second_cost, new_first_cost, new_second_cost, p;
    cout << "Enter first cost:" << endl;
    cin >> first_cost;
    cout << "Enter second cost:" << endl;
    cin >> second_cost;
    cout << "Enter the percentage increase in the price of the product:" << endl;
    cin >> p;
    new_first_cost = (first_cost*p)/100+first_cost;
    new_second_cost = (second_cost*p)/100+second_cost;
    cout << "First cost is: "<< first_cost << endl;
    cout << "Second cost is: " << second_cost << endl;
    cout << "New first cost is: " << new_first_cost << endl;
    cout << "New second cost is: " << new_second_cost << endl;
    return 0;
}