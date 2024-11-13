#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
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
    ll n, k;
    cin >> n >> k;
    vll coins(n);
    inputArray<ll>(coins, n);
    vector<vll> dp(n + 1, vll(k + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1; // Base case: 1 way to make the sum 0 (using no coins)
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int sum = 1; sum <= k; sum++)
        {
            int skip = dp[i + 1][sum]; // Skip the current coin
            int pick = 0;
            if (coins[i] <= sum)
            {
                pick = dp[i][sum - coins[i]]; // Pick the current coin
            }
            dp[i][sum] = (pick + skip) % MOD;
        }
    }
    print(dp[0][k]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
