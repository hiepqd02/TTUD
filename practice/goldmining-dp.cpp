#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1;

int a[N],
    S[N];

int n,
    L1, L2, ans;

void input()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >>
        n >> L1 >> L2;

    for (int i = 1; i <= n; i++)
        cin >>
            a[i];
}

void solveN2()
{

    S[1] = a[1];
    ans = S[1];

    for (int i = 2; i <= n; i++)
    {

        S[i] = a[i];

        for (int d = L1; d <= L2; d++)
        {

            int j = i - d;

            if (j >= 1 && S[i] < S[j] + a[i])
                S[i] = S[j] + a[i];
        }

        ans = max(ans, S[i]);
    }

    cout
        << ans;
}

int main()
{

    input();

    solveN2();

    return 0;
}
