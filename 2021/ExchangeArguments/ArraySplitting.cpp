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
problem: https://codeforces.com/contest/1175/problem/D

given an array you want to divide it into k continuous segments and multiply i to sum of all integers in ith segment. and add all.
what is the maximum sum you can obtain.
-1 -2 5 -4 8 k=2
two segments will give max ans [-1,-2] and [5,-4,8] = 1*(first) + 2*(second) = 1*(-3) + 2*(9) = 15

-1 -2 5 -4 8
        s-> suffix array            
    ans =   1*(s[0] - s[a]) + 2*(s[a] - s[b]) + ..... + k*(s[z]); a< ... b....<z.
    simplifying, we get - s[0] + s[a] + s[b] + s[c] + .......+ s[z];
    note while implementation: s[0] is compulsary so ans is s[0] + max(all suf[] except s[0]);

*/

void solve() {
    int n,k; cin >> n >> k; 
    int arr[n]; rep (i,n) cin >> arr[i];
    vector < int > ans;
    int sum = 0;
    repd (i,n) {
        sum += arr[i];
        if (i>0) ans.eb(sum);
    }
    sort(all(ans));
    int res = 0;
    rep (i,k-1) res += ans[n-2-i]; 
    cout << res + sum << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; t=1;
    while (t--) solve();
}
