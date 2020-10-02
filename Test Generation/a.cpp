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

/*
    whenever intervals are given always sort by their end value as the starting pt
    of any particular interval will always be less than the end value
*/
void solve() {
    int n; cin >> n;
    pair  < int , pair < int ,int > > arr[n+1];
    arr[0] = mp(0,mp(0,0));
    reps (i,n+1,1) {
        int s,e,p; cin >> s >> e >> p;
        arr[i] = (mp(e,mp(s,p)));
    }
    sort(arr,arr+n+1);
    // rep (i,n) {}
    int dp[n+1],res = 0; ms(dp);
    reps (i,n+1,1) {
        // if we use this interval in our ans
        int start = 0,end = i-1,idx = -1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (arr[mid].first < arr[i].second.first) {
                idx = mid;
                start = mid+1;
            }else {
                end = mid-1;
            }
        }
        dp[i] = max(dp[i-1],arr[i].second.second + dp[idx]);
        // dp[i] = arr[i].second.second + dp[idx];
        res = max(res,dp[i]);

    }
    // reps (i,n+1,1) {
    //     cout << arr[i].second.first << " " << arr[i].first << " " << arr[i].second.second << endl;
    // }
    // cout << endl;
    // rep (i,n+1) cout << dp[i] << " "; cout << endl;
    cout << res << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; t=1;
    while (t--) solve();
}
