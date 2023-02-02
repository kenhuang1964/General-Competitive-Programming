#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_INT = 1000000;
ll N;
map<ll,ll>adj;
bool visited[MAX_INT];
ll ans= 0;
bool work = false;

void DFS(ll node){
    if (node == 2){
        work = true;
        return;
    }
    visited[node]= true;
    ans++;
    if (!visited[adj[node]]) DFS(adj[node]);
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++){
        int num; cin >> num;
        adj[i] = num;
    }
    DFS(1);
    if (work) cout << ans;
    else cout << -1;
    return 0;
}