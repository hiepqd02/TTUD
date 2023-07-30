#include <iostream>
using namespace std;
int main()
{
    // kieur du lei
    int n;
    int k;
    int m;
    long a[100];
    long sum = 0;
    long count = 0;
    cin >> n >> k >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = 0; j < k; j++)
        {
            sum += a[i + j];
        }
        if (sum == m)
        {
            count++;
        }
    }
    cout << count;
}

// #include <iostream>
// using namespace std;

// int main()
// {
//     int n, k, m;
//     long a[100];
//     long sum = 0;
//     long count = 0;

//     cin >> n >> k >> m;

//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     // Calculate initial sum
//     for (int i = 0; i < k; i++)
//     {
//         sum += a[i];
//     }

//     if (sum == m)
//     {
//         count++;
//     }

//     // Sliding window technique
//     for (int i = k; i < n; i++)
//     {
//         sum = sum - a[i - k] + a[i];

//         if (sum == m)
//         {
//             count++;
//         }
//     }

//     cout << count << endl;

//     return 0;
// }