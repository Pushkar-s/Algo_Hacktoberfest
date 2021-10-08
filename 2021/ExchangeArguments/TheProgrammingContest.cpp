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
    lets suppose we know which questions are we going to choose then only problem remains is choosing the order of problems
    reward of each problem is = maxPoints[i] - (requiredTime[i]+something)*pointsPerMinute[i];
                            reward = m1 - d1*(t1 + x) +  m2 - d2*(t1 + t2)
    suppose we have two problems one after another 
        reward1 = m1 - d1*(t1) + m2 - d2*(t1 + t2)
        reward2 = m2 - d2*(t2) + m1 - d1*(t1 + t2)
        we search for this condition,
        when, reward1 - reward2 >= 0
          m1 - d1*(t1) + m2 - d2*(t1 + t2)
        -(m2 - d2*(t2) + m1 - d1*(t1 + t2)) >= 0
        =>  d1*(t2)) >= d2*(t1)    (condition for sorting)
        if this condition satisfies then reward1 >= reward2 
        hence in sort function we will pass the arguments.
         
    now we will solve the problem of choosing the problems which can be done by dp similar to knapsack.

*/

// const int inf = 1e9 + 7;
int find(int T, vector <int> maxPoints, vector <int> pointsPerMinute, vector <int> requiredTime) {
    int n = maxPoints.size();
    vector < pair < int , pair < int , int > > > arr;
    for (int i=0; i<n; i++) {
        if (requiredTime[i] <= T) {
            arr.push_back(make_pair(maxPoints[i],make_pair(pointsPerMinute[i],requiredTime[i])));
        }
    }
    sort(arr.begin(),arr.end(),[](pair < int , pair < int , int > > a, pair < int , pair < int , int > > b){
        return (a.second.first*b.second.second) >= (b.second.first*a.second.second);
    }); 
    n = arr.size();
    // for (auto  e: arr) {
    //     // cout << e.first << " " << e.second.first << " " << e.second.second << endl;
    // }
    vector < vector < int > > dp(n,vector < int > (T+1,0));
    int res = 0;
    for (int i=0; i<n; i++) {
        int m = arr[i].first;
        int d = arr[i].second.first;
        int rt = arr[i].second.second;
        for (int j=rt; j<=T; j++) {
            dp[i][j] = max({(i>0&&j-rt>=0?dp[i-1][j-rt]:0)+ m - j*d, i>0?dp[i-1][j]:0,dp[i][j-rt]});
            res = max(res,dp[i][j]);
            if (dp[i][j] == 1295067296) cout << "hi" << endl;
        }
    }
    // rep (i,n) cout << dp[i][0] << " " << dp[i][25] <<" "<< dp[i][50]  << " " << dp[i][75] << endl;
    
    return res;
} 
