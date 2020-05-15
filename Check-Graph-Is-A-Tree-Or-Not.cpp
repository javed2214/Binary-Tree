// Program to Check Whether the Given Graph is Tree or Not
// An Undirected Graph is Tree if it has Following Properties
// => There is No Cycle
// => The Graph is Connected

#include<bits/stdc++.h>
using namespace std;

#define MAX 1001

vector <int> g[MAX];
vector <int> vis(MAX, 0);
vector <int> parent(MAX, -1);


// BFS to Check Whether the Graph is Cyclic or Not

bool isCycle(int root, int n){

    queue <int> q;
    q.push(root);
    vis[root] = 1;

    while(!q.empty()){

        int temp = q.front();
        q.pop();

        for(auto it: g[temp]){

            if(!vis[it]){
                vis[it] = 1;
                parent[it] = temp;
                q.push(it);
            }
            else if(parent[temp] != it){
                return true;
            }
        }
    }
    return false;
}

// DFS to Check Whether the Graph is Cyclic or Not

bool dfs(int u){

    vis[u] = 1;
    for(auto it: g[u]){
        if(!vis[it]){
            parent[it] = u;
            if(dfs(it)) return true;
        }
        else if(parent[u] != it) return true;
    }
    return false;
}

int main(){

    int n, m;
    cin >> n >> m;

    for(int i=0;i<m;i++){
        
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    if(isCycle(0, n)) return !printf("Graph is Not a Tree! (It is Cyclic)");
    for(int i=0;i<n;i++) if(!vis[i]) return !printf("Graph is Not a Tree! (It has Multiple Components)");

    printf("Graph is a Tree!");

    return 0;
}