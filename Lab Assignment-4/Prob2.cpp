/**
* @file Prob2.cpp
* @brief this file contains code for problem2 of Lab-Assignment4
*
*@author Prateek Sachan
*
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/**
 * Checks if queen at given row and col can be correctly placed
*/
bool arrangementPossible(int n, int **arr, int row, int col)
{
    for (int i = row; i >= 0; i--)
        if (arr[i][col])
            return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (arr[i][j])
            return false;
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (arr[i][j])
            return false;
    return true;
}
/**
 * Solves the n-queen problem for given array
*/
bool NQueenSolver(int n, int **arr, int row)
{
    if (row == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }
    bool possible = false;
    for (int i = 0; i < n; i++)
    {
        if (arrangementPossible(n, arr, row, i))
        {
            arr[row][i] = 1;
            possible = NQueenSolver(n, arr, row + 1) || possible;
            arr[row][i] = 0;
        }
    }
    return possible;
}
int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    int **board;
    board = new int *[N];
    for (int i = 0; i < N; i++)
        board[i] = new int[N];

    NQueenSolver(N, board, 0);
    return 0;
}