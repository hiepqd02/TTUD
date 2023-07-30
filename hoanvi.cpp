#include <bits/stdc++.h>
#define MAX 100
using namespace std;

int N;
int X[MAX];      // permutation 1,2,...,N
int appear[MAX]; // appear[v] = 1 indicates that v has appeared

void solution()
{
    for (int i = 1; i <= N; i++)
    {
        cout << X[i] << " ";
    }
    cout << endl;
}

void Try(int k)
{
    for (int j = 1; j <= N; j++)
    {
        cout << j;
        if (appear[j] == 0)
        {
            X[k] = j;
            appear[j] = 1;
            if (k == N)
            {
                solution();
            }
            else
            {
                Try(k + 1);
            }
            appear[j] = 0; // backtrack
        }
    }
}
int main()
{
    N = 3;

    Try(1);
    return 0;
}

// 1next 12next 123print solution 1 2 3 back done back 3next 12print solution 1 3 2 back 3done back done back 2next 1next 123print solution 2 1 3 back done back 23next 1print solution 2 3 1 back 23done back done back 3next 1next 12print solution 3 1 2 back 3done back 2next 1print solution 3 2 1 back 23done back 3done back[1] + Done