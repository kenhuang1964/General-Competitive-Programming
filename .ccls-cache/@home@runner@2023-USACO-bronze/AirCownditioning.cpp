#include <bits/stdc++.h>
using namespace std;

int solve_air_conditioning(int n, int m, int cows[][3], int air_conditioners[][4]) {
    int min_cost = INT32_MAX;
    for (int i = 0; i < (1 << m); i++) {
        int cost = 0;
        int temp[100];
        memset(temp, 0, sizeof(temp));
        for (int j = 0; j < m; j++) {
            if (i & (1 << j)) {
                cost += air_conditioners[j][3];
                for (int k = air_conditioners[j][0]-1; k < air_conditioners[j][1]; k++) {
                    temp[k] += air_conditioners[j][2];
                }
            }
        }
        bool satisfied = true;
        for (int j = 0; j < n; j++) {
            if (*min_element(temp + cows[j][0] - 1, temp + cows[j][1]) < cows[j][2]) {
                satisfied = false;
                break;
            }
        }
        if (satisfied && cost < min_cost) {
            min_cost = cost;
        }
    }
    return min_cost;
}

int main() {
    int n, m;
    cin >> n >> m;
    int cows[n][3];
    for (int i = 0; i < n; i++) {
        cin >> cows[i][0] >> cows[i][1] >> cows[i][2];
    }
    int air_conditioners[m][4];
    for (int i = 0; i < m; i++) {
        cin >> air_conditioners[i][0] >> air_conditioners[i][1] >> air_conditioners[i][2] >> air_conditioners[i][3];
    }
    cout << solve_air_conditioning(n, m, cows, air_conditioners);
    return 0;
}