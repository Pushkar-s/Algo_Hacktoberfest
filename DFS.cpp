#include <iostream>
#include <vector>
#include <stack>
using namespace std;


vector<int>adj[10];
bool visited[10];
stack<int>stk;

void DFS(int s){
    cout<<s<<" ";
    visited[s] = true;
    for(int i=0; i<adj[s].size();i++){
        if(visited[adj[s][i]]==false){
            DFS(adj[s][i]);
        }
    }
}

void DFS_iterative(int s){
    int v;
    stk.push(s);
    visited[s] = true;
    while(!stk.empty()){
        v = stk.top();
        cout<<v<<" ";
        stk.pop();
        for(int i=0; i<adj[v].size(); i++){
            if(visited[adj[v][i]]==false){
                stk.push(adj[v][i]);
                visited[adj[v][i]] = true;
            }
        }
    }
}

int main() {

    int nodes,edges,x,y;
    cout<<"Enter number of nodes and edges\n";
    cin>>nodes>>edges;
    cout<<"now enter pair of edges";
    for(int i=0; i<edges; i++){
        cin>>x>>y;
        adj[x].push_back(y);
    }
    cout<<endl;
    DFS(1);
    
    for(int i=0; i<10; i++){
        visited[i] = false;
    }
    cout<<endl;
    DFS_iterative(1);
    cout<<endl;
    for(int i=1; i<=nodes; i++){
        cout<<"Adjency list of "<<i<<":";
        for(auto e: adj[i])cout<<e<<"->";cout<<endl;
    }


    return 0;
}
