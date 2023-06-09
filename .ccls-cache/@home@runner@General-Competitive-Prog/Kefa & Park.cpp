#include <bits/stdc++.h>

using namespace std;

int n, m;
const int mxN = 1e5+5 ;

int cats[mxN];
bool visited[mxN];
vector<int>adj[mxN];
int consec[mxN];

int ans = 0;

void DFS(int v, int prev, int m) {
    if (consec[prev] + cats[v] > m) return;
    
    visited[v] = true;
    if (cats[v] == 0) consec[v] = 0;
    else consec[v] = consec[prev] + cats[v];
    
    if (adj[v].size() == 1 && v != 1) ans++;
    
    for (auto u : adj[v]) {
        if (!visited[u]) {
            DFS(u, v, m);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> cats[i];
    }
    
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    DFS(1, 0, m);
    cout << ans << endl;
    
    return 0;
}