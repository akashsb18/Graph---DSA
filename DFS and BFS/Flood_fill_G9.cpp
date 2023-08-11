// An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

// You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

// To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

// Return the modified image after performing the flood fill.

#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> &ans, vector<vector<int>> image, int sr, int sc, int colour, int delRow[], int delCol[])
{
    int initColour = image[sr][sc];
    ans[sr][sc] = colour;
    int n = image.size();
    int m = image[0].size();
    for (int i = 0; i < 4; i++)
    {
        int newRow = sr + delRow[i];
        int newCol = sc + delCol[i];
        if (newRow >= 0 and newRow < n and newCol >= 0 and newCol < m and ans[newRow][newCol] != colour and image[newRow][newCol] == initColour)
        {
            DFS(ans, image, newRow, newCol, colour, delRow, delCol);
        }
    }
}

int main()
{

    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};

    int sr = 1, sc = 1, color = 2;

    vector<vector<int>> ans = image;
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    DFS(ans, image, sr, sc, color, delRow, delCol);

    for (auto it : ans)
    {
        cout << it[0] << " " << it[1] << " " << it[2] << endl;
    }

    return 0;
}