#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a) for (int i = 0; i < (a); i++)
#define repd(i, a) for (int i = (a)-1; i >= 0; i--)
#define reps(i, a, j) for (int i = (j); i < (a); i++)
#define deb(x) cout << #x << " " << x << endl;
#define debs(x) cout << #x << " " << x << " ";
#define deba(x) for (auto _i:x) cout << _i << " "; cout << endl;
#define ms(a) memset(a,0,sizeof(a));
#define mp make_pair
#define eb emplace_back
#define pii pair < int , int >
#define all(a) a.begin(),a.end()

const int INF = 1e18 + 7;

/*
    Boxes qustion:
    https://atcoder.jp/contests/cf17-final/tasks/cf17_final_d

    1. required sorting 
    2. Dp with dp[pref][used] = we used 'used' no of items till pref item.
    dp[pref][used] = min(dp[i-1][j],(this one if only possible)dp[i-1][j-1] + cur_w );
*/

void solve() {
    int n; cin >> n;
    vector < pii > arr(n);
    rep (i,n) cin >> arr[i].first >> arr[i].second;
    sort (arr.begin(),arr.end(),[](pii a, pii b){
        return a.first + a.second < b.first + b.second;
    });
    // rep (i,n) cout << arr[i].first << " " << arr[i].second << endl;
    int dp[n][n];  
    rep (i,n) rep (j,n) dp[i][j] = INF;
    dp[0][0] = arr[0].second;
    reps (i,n,1) {
        rep (j,n) {
            if (j == 0) {
                dp[i][j] = min(arr[i].second,dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
                if (dp[i-1][j-1] <= arr[i].first) dp[i][j] = min(dp[i][j],dp[i-1][j-1] + arr[i].second);
            }
        }
    }
    int res;
    rep (i,n) if (dp[n-1][i] < INF) res = i+1;
    cout << res << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; t=1;
    while (t--) solve();
}
