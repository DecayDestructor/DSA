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
    ll n;
    cin >> n;
    vector<vch> grid(n, vch(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    // Edge case: If start or end is blocked
    if (grid[0][0] == '*' || grid[n - 1][n - 1] == '*')
    {
        print(0);
        return;
    }

    vector<vll> dp(n, vll(n, 0));

    // Initialize the first column
    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == '*')
            break;
        dp[i][0] = 1;
    }

    // Initialize the first row
    for (int j = 0; j < n; j++)
    {
        if (grid[0][j] == '*')
            break;
        dp[0][j] = 1;
    }

    // Fill the dp array
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (grid[i][j] == '*')
                continue;

            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }

    print((dp[n - 1][n - 1]));
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
