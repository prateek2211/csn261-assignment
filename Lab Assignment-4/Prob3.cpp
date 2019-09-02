/**
* @file Prob3.cpp
* @brief this file contains code for problem3 of Lab-Assignment3
*
*@author Prateek Sachan
*
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/**
 * Stores the starting and ending index of max subarray
*/
struct Index
{
    int startIndex;
    int endIndex;
};

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    cin >> n;
    unordered_map<int, int> m;
    int sum = 0;
    int maxLength = 0;
    Index arrInd;
    for (int i = 0; i < size; i++)
    {
        int length = 0;
        sum += arr[i];
        if (sum == n && i + 1 > maxLength)
        {
            maxLength = i + 1;
            arrInd.startIndex = 0;
            arrInd.endIndex = i;
        }
        else if (m.find(sum - n) != m.end() && maxLength < i - m[sum - n])
        {
            maxLength = i - m[sum - n];
            arrInd.startIndex = m[sum - n] + 1;
            arrInd.endIndex = i;
        }
        if (m.find(sum) == m.end())
            m[sum] = i;
    }
    cout << "Max Length = " << maxLength << "\n";
    cout << "Starting Index = " << arrInd.startIndex << "\n";
    cout << "Ending Index = " << arrInd.endIndex << "\n";
    return 0;
}