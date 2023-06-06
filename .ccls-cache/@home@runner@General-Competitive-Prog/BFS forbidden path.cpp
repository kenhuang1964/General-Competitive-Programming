#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<int>> adj(n+1);
    vector<vector<int>> forbidden(k+1);
    
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for (int i = 0; i < k; i++){
        int a, b, c; 
        cin >> a >> b >> c;
        forbidden[i] = {a, b, c};
    }
    
    queue<int>q;
    vector<bool> visited(n+1, false);
    vector<int> dist(n+1, 0);
    vector<int> path(n+1, -1);
    
    q.push(1);
    visited[1] = true;
    path[1] = -1;
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        
        int a = path[v];
        int b = v;
        for (auto u : adj[v]) {
            if (!visited[u]) {
                bool w = true;
                vector<int>currentTriplet = {a, b, u};

                for (int i = 0; i < k; i++){
                    if (currentTriplet == forbidden[i]) {
                        w = false;
                    }
                }
                
                if (w){
                    visited[u] = true;
                    path[u] = v;
                    dist[u] = dist[v] + 1;
                    q.push(u);
                }
            }
        }
    }
    
    if (!visited[n]) {
        cout << -1 << endl;
    } else {
        cout << dist[n] << endl;
        vector<int> p;
        for (int v = n; v != -1; v = path[v]) {
            p.push_back(v);
        }
        reverse(p.begin(), p.end());
        for (int v : p) {
            cout << v << " ";
        }
    }
    
    return 0;
}