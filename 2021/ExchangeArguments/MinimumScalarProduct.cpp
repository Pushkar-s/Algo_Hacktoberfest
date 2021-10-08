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
    problem: given two vectors a,b you can permute them anyway you want calculate the maximum scalar product you can get.
             scalar product = a[0]*b[0] + a[1]*b[1] + ..... a[n]*b[n];
    main theme: minimum product happens when difference b/w numbers is maximum and 
    vice versa for maximum product

    Exchange Arguments Proof:
    a[0] <= a[1] <= a[2] .... a[n]
    b[0] >= b[1] >= b[2] .... b[n]
    let, i < j , so a[i] <= a[j]
            and     b[i] >= b[j] but after swapping b[i] <= b[j] ...
    what happens when we swap b[i] & b[j] 
    difference in scalar product in two different scenarios :  (a[i]*b[i] + a[j]*b[j]) - (a[i]*b[j] + a[j]*b[i])
    rearranging we get : a[i](b[i] - b[j]) + a[j](b[j] - b[i]) 
                         a[i](b[i] - b[j]) + a[j]*(-1)*(b[i] - b[j])
                         (b[i]-b[j])*(a[i] - a[j])
                         -ve * -ve  = +ve 
                         so since differnce is +ve hence scalar product was more before.
                         therefore the cost(scalar product) decreases.



*/

int solve() {
    int n; cin >> n; 
    vector < int > a(n),b(n);
    rep (i,n) cin >> a[i];
    rep (i,n) cin >> b[i];
    sort(all(a));
    sort(b.rbegin(),b.rend());
    int res = 0;
    rep (i,n) {
        res += (a[i]*b[i]);
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    rep (i,t) {
        cout << "Case #" << i+1 << ": "<< solve() << endl;
    }
}





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
        if this condition satisfies then reward1 >= reward2 implies we do not need to change the positions 
        hence in sort function we will pass the reverse arguments.
         
    now we will solve the problem of choosing the problems which can be done by dp similar to knapsack.

*/

