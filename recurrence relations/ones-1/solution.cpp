#include <iostream>
#include <vector>
using namespace std;


int main() {
    int N, K;
    cin >> N >> K;
    vector<vector <int>> dp(N + 1);
    for (int i = 0; i <= N; i++) {
        dp[i].resize(i + 1);
        dp[i][i] = 1;
        dp[i][0] = 1;
    }
        ;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % int((1e9 + 7));
        }
    }

    cout << dp[N][K];
    return 0;
}