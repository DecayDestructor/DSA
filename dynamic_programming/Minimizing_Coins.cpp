#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define loop(n) for (int i = 0; i < n; i++)
#define py cout << "YES" << nl
#define pn cout << "NO" << nl
#define print(ans) cout << ans << nl
#define isEven(n) if (n % 2 == 0)
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<char> vch;
template <typename T1, typename T2>
using vpp = vector<pair<T1, T2>>;
// Template functions for input and output
template <typename T>
void inputArray(vector<T> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

template <typename T>
void outputArray(vector<T> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << nl;
    }
}
void solve()
{
    // print("Hello");
    ll n,
        target;
    cin >> n >> target;

    vll coins(n);
    inputArray<ll>(coins, n);
    vll dp(target + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= target; i++)
    {
        // print("First loop");
        for (int j = 0; j < n; j++)
        {
            if (i >= coins[j])
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    // print(dp[target]);
    if (dp[target] == 1e9)
    {
        print(-1);
    }
    else
        print(dp[target]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}