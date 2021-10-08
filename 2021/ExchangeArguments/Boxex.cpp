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
    given n boxes each with a strength and weight. we will stack boxes on top of on another any box holding some boxes on top 
    of it is required to have strength greater or equal to the weights above it.
    How many maximum no of boxes you can stack over.

    sol:
    we can do dp here whether this box is in the optimal ans or not if it is then we can do some kind of knapsack on it.
    but the order matters in this kind of dp, we can do dp only if all boxes which can be on top of it is covered before we calculate
    for this one. so we first need to sort the boxes.

    1  2  3  .... n
    w1 w2 w3 .... wn
    s1 s2 s3 .... sn

    box[1] = w1 s1
    box[2] = w2 s2

    we can have conditions like box[1] can only be on top if s[2] >= w[1]  we can have s[1] >= w[2] as well. In that case both can be on top
    of one another. but we care about when should we must swap that is when can box[1] can't be put on top of box[2]. other wise dp will work.
    in both arrangement but it wont if arrangement is faulty.
    we formulate when do we have a must arrangement of box[1] on top of box[2] Note: 'must' 
    1. s[2] >= w[1] // necessary if this is not satisfied we must swap
    2. s[1] < w[2] // condition when box[2] can't be put on top.
    combining both we get s[2] + w[2] > s[1] + w[1]   Note: >= changes to > since we have > in condition second.

    so this will be our condition for sort function:

    gist : strength[i] + weight[i] is enough to sort.


    example : boxno    = 1 2 3 4 
              weight   = 4 7 1 1 
              strength = 9 3 2 10
    order after sorting  = boxno (3,2,4,1);

    Then DP:
    If we're given n items and we should choose some of them and choose their order, 
    we should sort them with some strange/tricky comparator, and then do O(N2) dynamic programming.
    The dp should be 
    dp[pref][used] — best possible result (balance) if we chose used items so far (in the prefix pref).

    question: Zabuton in the same folder.

*/



void solve() {

}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; t=1;
    while (t--) solve();
}
