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
