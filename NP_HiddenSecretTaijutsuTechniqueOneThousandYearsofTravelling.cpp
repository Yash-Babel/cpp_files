#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i, a, b) for (int i = a; i < b; i++)
const int mod = 1000000007;

void YN(bool possible)
{
    if (possible)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

bool commonSetElement(set<int> *a, set<int> *b)
{
    auto fstart = a->begin();
    auto sstart = b->begin();
    auto fend = a->end();
    auto send = b->end();
    while (fstart != fend && sstart != send)
    {
        if (*fstart > *sstart)
        {
            sstart++;
        }
        else if (*fstart < *sstart)
        {
            fstart++;
        }
        else
        {
            return true;
        }
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int n, m, k, q, tmp;
    cin >> n >> m;
    vector<set<int>> vs(n + 1);
    for (int i = 1; i < m + 1; i++)
    {
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> tmp;
            vs[tmp].insert(i);
        }
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        bool possible = false;
        int a, b;
        cin >> a >> b;
        if (commonSetElement(&vs[a], &vs[b]))
        {
            possible = true;
        }
        YN(possible);
    }
    return 0;
}