#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image)
{

    int row = image.size();
    int col = image[0].size();

    vector<vector<int>> matrix(row, vector<int>(col, 0));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = image[i][col - 1 - j]; // Flip horizontally
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] ^= 1; // Invert (0->1 and 1->0)
        }
    }

    return matrix;
}

int main()
{
    vector<vector<int>> image = {{1,1,0},{1,0,1},{0,0,0}};

    for (auto row : flipAndInvertImage(image))
    {
        for (auto val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}