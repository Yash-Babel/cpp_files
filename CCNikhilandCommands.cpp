#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        string answer = "/";
        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            if (str == "pwd")
            {
                if (answer == "/")
                {
                    cout << "/\n";
                }
                else
                {
                    cout << answer << "/"
                         << "\n";
                }
            }
            else
            {
                cin >> str;
                if (str[0] == '/')
                {
                    answer = str;
                }
                else
                {
                    if (answer != "/")
                    {
                        answer += "/";
                    }
                    answer += str;
                }
                while (true)
                {
                    int k = answer.find(".");
                    if (k == -1)
                    {
                        break;
                    }
                    string str1 = answer.substr(0, k - 1);
                    string str2 = answer.substr(k + 2, str.size() - k - 2);
                    k = str1.rfind("/");
                    str1 = str1.substr(0, k);
                    answer = str1 + str2;
                }
            }
        }
    }

    return 0;
}