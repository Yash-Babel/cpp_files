#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    string str = "Hello Yash Babel";
    stringstream ss;
    ss << str;

    // string s2;
    // ss >> s2;
    // string s3;
    // ss >> s3;
    // cout << s2 << endl
    //      << s3;

    // string word;
    // int count = 0;
    // while (ss >> word)
    // {
    //     count++;
    // }
    // cout << count;

    // string temp;
    // string str1;
    // str1 = "";
    // while (ss >> temp)
    // {
    //     str1 += temp;
    // }
    // cout << str1;

    // string str2 = "123456";
    // stringstream ss1;
    // ss1 << str2;

    // string input, age;
    // cin >> input >> age;
    // ofstream outfile;
    // outfile.open("trial.txt");
    // outfile << input << endl;
    // outfile << age;

    // ifstream infile;
    vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);
    vec.push_back(60);
    vec.pop_back();
    vec.pop_back();
    if (vec.empty())
    {
        cout << "vec is empty" << endl;
    }
    else
    {
        cout << "size of vec is " << vec.size() << endl;
    }
    cout << "front element is " << vec.front() << endl;
}
// This is a file.
// This is a line 2.