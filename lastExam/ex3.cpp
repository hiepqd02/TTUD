#include <iostream>
#include <vector>
using namespace std;
int countSubsequences(const vector<int> &arr, int a, int b)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(b + 1, 0));
    // Base case: when sum = 0, there is always an empty subsequence
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            dp[i][j] = dp[i - 1][j]; // Exclude current element
            if (j >= arr[i - 1])
            {
                dp[i][j] += dp[i - 1][j - arr[i - 1]]; // Include current element
            }
        }
    }
    int totalCount = 0;
    for (int sum = a; sum <= b; sum++)
    {
        totalCount += dp[n][sum];
    }
    return totalCount;
}
int main()
{
    int n;
    int a;
    int b;
    cin >> n, a, b;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int totalCount = countSubsequences(arr, a, b);
    cout << "Total number of subsequences with sum from " << a << " to " << b << ": " << totalCount << std::endl;
    return 0;
}