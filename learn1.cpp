#include <iostream>
using namespace std;
struct employee
{
    int eid = 0;
    char favChar = 'a';
};
union money
{
    int rice;
    char ch;
    float pounds;
};
int main()
{
    struct employee yash;
    yash.eid = 1;
    yash.favChar = 'Y';
    struct employee raj;
    cout << "The value of yash.eid is: " << yash.eid << endl;
    cout << "The value of yash.favChar is: " << yash.favChar << endl;
    cout << "The value of raj.eid is: " << raj.eid << endl;
    cout << "The value of raj.favChar is: " << raj.favChar << endl;

    // money m1;
    // m1.rice = 5;
    // cout << "The value of m1.rice is: " << m1.rice << endl;
    // m1.ch = 'a';
    // m1.pounds = 1.37430e-042;
    // cout << "The value of m1.rice is: " << m1.rice << endl;
    // cout << "The value of m1.ch is: " << m1.ch << endl;
    // cout << "The value of m1.pounds is: " << m1.pounds << endl;
}