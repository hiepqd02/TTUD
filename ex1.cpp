#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    int A[1001];
    int B[1001];
    int count = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        {
        cin >> A[i];
        }

    cin >> m;
    for (int i = 0; i < m; i++)
        {
        cin >> B[i];
        };


    for (int i = 0; i < n; i++)
        {
        for (int j = 0; j < m; j++)
            {
            if (A[i] == B[j]) count++;
            }

        }

    cout << count << endl;
    };
