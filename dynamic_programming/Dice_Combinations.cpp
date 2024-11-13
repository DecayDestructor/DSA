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
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    // state
    // dp[i] = number of ways to make a sum of i

    // base case
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (j <= i)
            {
                // transition
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }

    // final subproblem
    cout << dp[n] << endl;
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