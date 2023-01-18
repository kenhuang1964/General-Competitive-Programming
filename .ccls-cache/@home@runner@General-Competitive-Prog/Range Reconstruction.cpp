#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    vector<vector<ll>>constraints(N, vector<ll>(N));
    vector<ll>ans(N);
    for (int i = 0; i < N; i++){
        for (int j = i; j < N; j++){
            cin >> constraints[i][j];
        }
    }
    for (int i = N-2; i >= 0; i--){
        //we can start at N-2 because we assume 0 for N-1

        //let's first test the previous value + constraints[i][i+1] to see if it works
        //it has to be previous value + constraints[i][i+1]
        // or previous value - constraints[i][i+1]
        //because constraints[i][i+1] is the absolute difference between the current value and the previous value
        ans[i] = ans[i+1] + constraints[i][i+1];

        //now let's see if ans[i] works by getting the difference between the min and max value in this range
        ll current_min = INT32_MAX;
        ll current_max = INT32_MIN;
        bool works = true;
        for (int j = i; j < N; j++){
            //we loop through from the current number to the rest of the numbers and check if the range matches
            current_min = min(current_min, ans[j]);
            current_max = max(current_max, ans[j]);
            if (current_max - current_min != constraints[i][j]){
                works = false;
                break;
            }
        }
        if (!works){
            ans[i] = ans[i+1] - constraints[i][i+1];
        }
    }
    for (int i = 0; i < ans.size()-1; i++){
        cout << ans[i] << " ";
    }
    cout << ans[N-1] << endl;
}