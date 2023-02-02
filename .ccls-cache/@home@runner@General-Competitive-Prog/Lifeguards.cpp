#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Cows {
    int time;
    int cow_id;
    bool starting;
};

bool operator<(const Cows& a, const Cows& b) {
    return a.time < b.time;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("lifeguards.in", "r", stdin);
    
    int n; cin >> n;
    vector<Cows> cows;

    for (int i = 0; i < n; i++){
        int start, end; cin >> start >> end;
        cows.push_back({start, i, true});
        cows.push_back({end, i, false});
    }

    sort(cows.begin(), cows.end());

    vector<int>cows_alone(n);
    set<int>working_cows;
    int total_time = 0;
    int previous_time = 0;

    for (const Cows& c : cows){
        int current_time = c.time;

        if (working_cows.size() > 0){
            total_time += current_time - previous_time;
        }

        if (working_cows.size() == 1) {
            cows_alone[*working_cows.begin()] += current_time - previous_time;
        }

        if (c.starting){
            working_cows.insert(c.cow_id);
        } else{
            working_cows.erase(c.cow_id);
        }

        previous_time = current_time;
    }
    
    int min_cow_alone_time = *min_element(cows_alone.begin(), cows_alone.end());

    freopen("lifeguards.out", "w", stdout);
    cout << total_time - min_cow_alone_time;
    return 0;
}