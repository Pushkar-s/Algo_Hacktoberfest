#include <iostream>
#include <vector>
#include <queue>

using namespace std;



int main(){
    int n,x,y;
    cin>>n;
    vector<vector<int>>v(n+1);
    for(int i=0; i<n-1; i++){
        cin>>x>>y;
        v[x].emplace_back(y);
        v[y].emplace_back(x);
    }
    // cout<<"hi"<<endl;
    int level[n+1];
    int visited[n+1];
    memset(visited,0,sizeof(visited));
    memset(level,0,sizeof(level));
    cin>>x;
    int mx = BFS(v,level,visited);// since graph is connected;
    int ans[mx+1];
    memset(ans,0,sizeof(ans));
    for(int i=1; i<=n; i++){
        ans[level[i]]++;
    }
    cout<<ans[x]<<endl;
    return 0;
}
