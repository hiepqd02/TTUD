// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     int a[100];
//     int count = 0;
//     cin >>
//         n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     for (int j = 0; j < n - 1; j++)

//     {
//         if (a[j] > a[j + 1])
//         {
//             count++;
//         }
//     }

//     cout << count + 1;
// }

#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

stack<int> stk;

queue<int> que;

int n;
string str;

int main()

{
    cin >> n;
    int a[n];
    for (int j = 0; j < n; j++)
        cin >> a[j];
    cin >> str;
    for (int i = n - 1; i >= 0; i--)
    {
        stk.push(a[i]);
    }

    for (int k = 0; k < str.length(); k++)
    {
        if (!que.empty() && str[k] == 'H')
        {
            stk.push(que.front());
            que.pop();
        }
        if (!stk.empty() && str[k] == 'C')
        {
            que.push(stk.top());
            stk.pop();
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << stk.top();
        stk.pop();
    }
}