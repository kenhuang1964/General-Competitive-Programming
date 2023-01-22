/* General Idea:
1) We start at a position with 0 (there has to be a position with 0 unless the numbers are all 1).
2) We loop counter clockwise until we find a non-zero number. We need a count to count the number of doors we went through to get to this number. Once we get this number, we simply subtract one from that number, add one to the position with zero, and then we add counter^2 to ans.
3) We then move to the next counter-clockwise number all the way until we reach the beginning position to terminate. We repeat the same steps for all of them.
Note: we have to start at the last occuring 0 position.
*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int ans = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    cin >> N;
    int position_last_zero = INT32_MAX;
    vector<int>circular_arr;

    for (int i = 0; i < N; i++){
        int num; cin >> num;
        circular_arr.push_back(num);
        if (num == 0)position_last_zero = i;
    }

    //consider the edge case where everything is already 1, then position_last_zero hasn't changed at all.
    if (position_last_zero == INT32_MAX){
        cout << 0;
        return 0;
    }

    int temp = position_last_zero;
    bool keep_loop = true;
    //we terminate once our pointer reaches temp
    while (keep_loop){
        int pointer = position_last_zero;
        int num_doors = 0;
        while (true){
            pointer--;
            if (pointer < 0) pointer = N-1;
            num_doors++;
            //run until we found a non-zero number
            if (circular_arr[pointer] > 0){
                circular_arr[pointer]--;
                circular_arr[position_last_zero]++;
                break;
            }
        }
        ans += num_doors*num_doors;
        while (circular_arr[position_last_zero] != 0){
            position_last_zero--;
            if (position_last_zero < 0) position_last_zero = N-1;
            if (position_last_zero == temp){
                keep_loop = false;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}