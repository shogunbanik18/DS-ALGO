#include <bits/stdc++.h>
using namespace std;
#define M 3
#define N 3

// Method 1

// void printrotatedmatrix(int mat[M][N])
// {
//     int sr = 0, er = M - 1;
//     int sc = 0, ec = N - 1;

//     for (int j = sc; j <= ec; j++)
//     {
//         for (int i = er; i >= sr; i--)
//         {
//             cout << mat[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

// Method 2

void print(int mat[M][N])
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

void printrotatedmatrix(int mat[M][N])
{
    // transpose of matrix
    for (int i = 0; i < M; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // reversing the individual rows
    for (int i = 0; i < M; i++)
    {
        int low = 0, high = N - 1;
        while (low < high)
        {
            swap(mat[i][low], mat[i][high]);
            low++;
            high--;
        }
    }
}

// TC: O(N^2)
// SC: O(1)

int main()
{
    // int M = 3, N = 3;
    int mat[M][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    printrotatedmatrix(mat);
    print(mat);

    return 0;
}


// vector of vector solution //
#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
      // your code goes here
       int n = matrix.size();
        int a = 0;
        int b = n-1;
        while(a<b){
            for(int i=0;i<(b-a);++i){
                swap(matrix[a][a+i], matrix[a+i][b]);
                swap(matrix[a][a+i], matrix[b][b-i]);
                swap(matrix[a][a+i], matrix[b-i][a]);
            }
            ++a;
            --b;
        }
      
}

// leetcode 

class Solution {
public:
    void swap1(vector<vector<int>>&matrix,int i,int j)
    {
        int temp=matrix[i][j];
        matrix[i][j]=matrix[j][i];
        matrix[j][i]=temp;
    }
    
    void rotate(vector<vector<int>>& matrix)
    {
        // taking the transpose
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<m;j++)
            {
                swap1(matrix,i,j);
                // swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        // reversing the indiviual row
        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
