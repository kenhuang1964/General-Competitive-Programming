#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll INF = 1e18;

ll n, m, q;

int main() {
    cin >> n >> m >> q;
    vector<vector<ll>>dist(n+1, vector<ll>(n+1, INF));
    
    for (int i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(c, dist[a][b]);
        dist[b][a] = min(c, dist[b][a]);
    }
    for (int i = 1; i <= n; i++){
        dist[i][i] = 0;
    }
    
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    while(q--){
        int a, b; cin >> a >> b;
        cout << (dist[a][b]>=INF ? -1 : dist[a][b]) << endl;
    }
    
    return 0;
}