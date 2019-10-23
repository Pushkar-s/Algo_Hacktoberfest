
#include <bits/stdc++.h>
using namespace std;

#define  F(i, a) for (int i = 0; i < (a); i++)
#define Fd(i, a) for (int i = (a)-1; i >= 0; i--)
#define Fs(i, a, j) for (int i = (j); i < (a); i++)
#define deb(x) cout << #x << " " << x << endl;
#define ll long long
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define pii pair<int,int>
#define all(c) c.begin(), c.end()
template<typename... T>void read(T&... args){((cin >> args), ...);}
template<typename... T>void write(T&&... args){((cout << args << " "), ...);}
const ll INF = 1e18+7;

// graph and variables
int n,m,k;
vector<pair<int,int>>g[100010];
long long dist[100010];
int path[100010];

void Dijkstra(int s){
    multiset<pair<int,int>>m;
    m.insert(mp(0,s));
    dist[s] = 0;
    while(!m.empty()){
        pii x = *m.begin();
        m.erase(m.begin());
        int u = x.s;
        if(u==k)break;
        F(i,g[u].size()){
            int v = g[u][i].f,w = g[u][i].s;
            if( dist[u] + w < dist[v]){
                dist[v] = dist[u]+w;
                m.insert(mp(dist[v],v));
                path[v] = u; 
            }
        }
    }

}

void print_path(int p){
    if(p==1){cout<<1<<" ";return;}
    print_path(path[p]);
    cout<<p<<" ";
}

int main(){
    ios_base::sync_with_stdio(false);
	  cin.tie(nullptr);
	  cout.tie(nullptr);
	  cerr.tie(nullptr);

    read(n,m);
    int u,v,w;
    F(i,m){
        read(u,v,w);
        g[u].eb(mp(v,w));
        g[v].eb(mp(u,w));
    }
    F(i,n+1){
        dist[i]=INF;
    }
    k=n;
    Dijkstra(1);
    if(dist[k]!=INF){
        print_path(k); 
    }
    return 0;
}


