#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    int A[1001];
    int do_dai_day[1001];

    cin >> n;
    for (int i = 0; i < n; i++)
        {
        cin >> A[i];
        do_dai_day[i] = 1;
        }
    for (int i = 0; i < n; i++)
        {
        int max = A[i];
        for (int j = i + 1;j < n;j++) {
            if (A[j] == max + 1)
                {
                max = A[j];
                do_dai_day[i]++;
                }

            }
        }
    int kq = 1;
    for (int i = 0; i < n; i++)

        {
        if (do_dai_day[i] > kq)
            kq = do_dai_day[i];
        }
    cout << kq << endl;

    }