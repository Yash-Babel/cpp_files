#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i, a, b) for (int i = a; i < b; i++)
const int mod = 1000000007;

#define pdd pair<double, double>

double radius;
void lineFromPoints(pdd P, pdd Q, double &a, double &b, double &c)
{
    a = Q.second - P.second;
    b = P.first - Q.first;
    c = a * (P.first) + b * (P.second);
}
void perpendicularBisectorFromLine(pdd P, pdd Q, double &a, double &b, double &c)
{
    pdd mid_point = make_pair((P.first + Q.first) / 2, (P.second + Q.second) / 2);
    c = -b * (mid_point.first) + a * (mid_point.second);
    double temp = a;
    a = -b;
    b = temp;
}
pdd lineLineIntersection(double a1, double b1, double c1, double a2, double b2, double c2)
{
    double determinant = a1 * b2 - a2 * b1;
    if (determinant == 0)
    {
        return make_pair(FLT_MAX, FLT_MAX);
    }
    else
    {
        double x = (b2 * c1 - b1 * c2) / determinant;
        double y = (a1 * c2 - a2 * c1) / determinant;
        return make_pair(x, y);
    }
}
pdd findCircumCenter(pdd P, pdd Q, pdd R)
{
    double a, b, c;
    lineFromPoints(P, Q, a, b, c);
    double e, f, g;
    lineFromPoints(Q, R, e, f, g);
    perpendicularBisectorFromLine(P, Q, a, b, c);
    perpendicularBisectorFromLine(Q, R, e, f, g);
    pdd circumcenter = lineLineIntersection(a, b, c, e, f, g);
    return circumcenter;
}
double directDistance(pdd x, pdd y)
{
    double fir = (x.first - y.first);
    double sec = (x.second - y.second);
    return sqrt((fir * fir) + (sec * sec));
}
double circularDistance(pdd x, pdd y, double distance)
{
    double theta = 2 * (asin(distance / (2 * radius)));
    return (radius * theta);
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
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        double x, y;
        cin >> n >> k;
        cin >> x >> y;
        pdd P = make_pair(x, y);
        cin >> x >> y;
        pdd Q = make_pair(x, y);
        cin >> x >> y;
        pdd R = make_pair(x, y);
        pdd circumcenter = findCircumCenter(P, Q, R);
        radius = directDistance(P, circumcenter);
        vector<pdd> vec;
        double dd = directDistance(P, Q);
        double cd = circularDistance(P, Q, dd);
        vec.push_back({dd - cd, cd});
        dd = directDistance(Q, R);
        cd = circularDistance(Q, R, dd);
        vec.push_back({dd - cd, cd});
        for (int i = 3; i < n; i++)
        {
            cin >> x >> y;
            Q = R;
            R = make_pair(x, y);
            dd = directDistance(Q, R);
            cd = circularDistance(Q, R, dd);
            vec.push_back({dd - cd, cd});
        }
        // for (pdd ele : vec)
        // {
        //     cout << ele.first << ' ' << ele.second << '\n';
        // }
        sort(vec.begin(), vec.end());
        double answer = 0;
        auto it = vec.begin();
        for (int i = 0; i < k; i++)
        {
            answer += (*it).first + (*it).second;
            it++;
        }
        for (int i = k + 1; i < n; i++)
        {
            answer += (*it).second;
            it++;
        }
        cout << fixed;
        cout << setprecision(8) << answer << '\n';
    }
    return 0;
}