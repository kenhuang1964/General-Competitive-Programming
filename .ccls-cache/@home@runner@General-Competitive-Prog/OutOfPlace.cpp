#include <bits/stdc++.h>
using namespace std;

int N;
vector<int>original;
vector<int>sorted;
int ans = -1;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    cin >> N;
    for (int i = 0; i < N; i++){
        int a; cin >> a;
        original.push_back(a);
        sorted.push_back(a);
    }
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < N; i++){
        if (sorted[i] != original[i]) ans += 1;
    }
    cout << ans;
    return 0;
}