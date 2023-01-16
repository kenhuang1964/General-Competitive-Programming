#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, Q;
bool visited[5002];
ll relevancy[5002][5002];
vector<ll>adj[5002];
ll counter = 0;
ll current_K = 0;

void DFS(ll current_Ki, ll current_min_K, ll node, ll prev_node){
    visited[node] = true;
    current_min_K = min(current_min_K, relevancy[prev_node][node]);
    ll temp = current_min_K;
    if (current_min_K < current_K) return;
    counter++;
    for (auto neighbor : adj[node]){
        current_min_K = temp;
        if (!visited[neighbor]) DFS(current_Ki, current_min_K, neighbor, node);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    cin >> N >> Q;
    for (int i = 0; i < N-1; i++){
        int p, q; cin >> p >> q;
        ll r; cin >> r;
        relevancy[p][q] = r; relevancy[q][p] = r;
        relevancy[p][p] = INT32_MAX; relevancy[q][q] = INT32_MAX;
        adj[p].push_back(q);
        adj[q].push_back(p);
    }
    for (int i = 0; i < Q;  i++){
        int Ki, Vi; cin >> Ki >> Vi;
        counter = 0;
        current_K = Ki;
        for (int i = 0; i < 5002; i++){
            visited[i] = false;
        }
        DFS(current_K, current_K, Vi, Vi);
        cout << counter-1 << endl;
    }
    return 0;
}