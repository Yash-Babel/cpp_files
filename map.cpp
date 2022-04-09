#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    // map<int, int> m1;
    // // Inserting
    // m1.insert({2, 5});
    // m1[7] = 1;
    // m1[3]++;
    // m1[3]++;
    // // printing
    // cout << "m1[3] = " << m1[3] << endl;
    // cout << "m1[2] = " << m1[2] << endl;

    map<string, int> m2;
    m2["chesse"] = 1;
    m2["salsa"] = 2;
    m2["salsa"] = m2["salsa"] + m2["chesse"];
    // cout << "m2[\"salsa\"] = " << m2["salsa"] << endl;
    // cout << "m2[\"chesse\"] = " << m2["chesse"] << endl;
    // for (auto it : m2)
    // {
    //     cout << it.first << " " << m2[it.first] << endl;
    // }
}