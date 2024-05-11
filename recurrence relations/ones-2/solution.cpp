#include <iostream>
#include <vector>
using namespace std;

const long long mod = 1e9 + 7;

long long binaryPow(long long base, long long rate) {
    if (rate == 1)
        return base;
    else if (rate % 2 == 0) {
        long long ans = binaryPow(base, rate / 2);
        return ans * ans % mod;
    }
    else
        return binaryPow(base, rate - 1) * base % mod;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<long long> dp(K + 1);
    dp[0] = 1;
    for (int i = 1; i <= K; i++) {
        dp[i] = ((dp[i - 1] * (N - i + 1)) % mod) * binaryPow(i, mod - 2) % mod;
    }

    cout << dp[K];
    return 0;
}