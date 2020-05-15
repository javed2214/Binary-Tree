// Check if Node 'x' is Ancestor of Node 'y' in a Tree (Not Applicable for Graph)
// 'x' is Ancestor of 'y' only id there is a Path from 'x' to 'y'
// https://www.youtube.com/watch?v=G0N7j-x3YT4&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=12

#include<bits/stdc++.h>
using namespace std;

#define MAX 1001

vector <int> g[MAX];
vector <int> vis(MAX);

int timer = 1;
int in[MAX], out[MAX];

void dfs(int u){

    vis[u] = 1;
    in[u] = timer++;

    for(auto it: g[u]){
        if(!vis[it])
            dfs(it);
    }
    out[u] = timer++;
}

int main(){

    int n, m;
    cin >> n >> m;

    for(int i=0;i<m;i++){

        int u, v;
        cin >> u >> v;

        g[u].push_back(v);      // Tree
    }

    dfs(1);

    int q;
    cin >> q;

    while(q--){

        int x, y;
        cin >> x >> y;

        if(in[x] < in[y] and out[x] > out[y]) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}