#include <iostream>

const long long mod = 1e9 + 7;
using namespace std;
long long a[10000];

int main() {
  long long n, k;
  cin >> n >> k;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long sum = 0;
  for (long long i = 0; i < n; ++i) {
    long long before_i = 0, after_i = 0;
    for (long long j = 0; j < n; ++j) {
      if (i == j)
        continue;
      else {
        if (a[i] > a[j]) {
          if (j < i)
            before_i++;
          else
            after_i++;
        }
      }
    }
    sum += (after_i % mod) * (k * (k + 1) / 2 % mod) % mod;
    sum += (before_i % mod) * (k * (k - 1) / 2 % mod) % mod;
  }
  cout << sum % mod << endl;
  return 0;
}