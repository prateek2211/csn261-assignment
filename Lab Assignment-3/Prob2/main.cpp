#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    list<int> dp;
    dp.push_back(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i - 1];
        dp.push_back(dp.back() ^ arr[i - 1]);
    }
    int totalCount = 0;
    int i = 1;
    for (auto it = dp.begin(); it != prev(prev(dp.end())); it++)
    {
        int k = i + 1;
        for (auto it2 = ++next(it); it2 != dp.end(); it2++)
        {
            if (*it == *it2)
            {
                totalCount += (k - i);
                for (int j = i + 1; j <= k; j++)
                    printf("(%d, %d, %d)\n", i, j, k);
            }
            k++;
        }
        i++;
    }
    printf("%d\n", totalCount);
    return 0;
}