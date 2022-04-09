#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const int mod = 1000000007;

void DFS(int i, int j, int initialColor, int newColor, vector<vector<int>> &image)
{
    int rows = image.size();
    int columns = image[0].size();
    if (i < 0 || j < 0 || i >= rows || j >= columns || image[i][j] != initialColor)
        return;
    image[i][j] = newColor;
    DFS(i - 1, j, initialColor, newColor, image);
    DFS(i + 1, j, initialColor, newColor, image);
    DFS(i, j - 1, initialColor, newColor, image);
    DFS(i, j + 1, initialColor, newColor, image);
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    if (image[sr][sc] == newColor)
    {
        return image;
    }
    DFS(sr, sc, image[sr][sc], newColor, image);
    return image;
}

vector<vector<int>> check(vector<vector<int>> vec)
{
    vec[1][1] = 2;
    return vec;
}

int main()
{
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    // vector<vector<int>> image = {{0, 0, 0}, {0, 0, 0}};
    // vector<vector<int>> image = {{0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}};
    image = floodFill(image, 1, 1, 2);
    // image = check(image);
    for (int i = 0; i < image.size(); i++)
    {
        for (int j = 0; j < image[0].size(); j++)
        {
            cout << image[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}