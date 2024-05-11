#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> mosq(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> mosq[i];
    }
    vector <int> dp(n+2);
    dp[0] = 0;
    dp[1] = mosq[1];
    dp[2] = -1;
    for (int i = 3; i <= n; i ++) {
        dp[i] = max(dp[i-2],dp[i-3]);
        if (dp[i] != -1)
            dp[i] += mosq[i];
    }
    cout << dp[n] << "\n";
    if (dp[n] == -1)
        return 0;
    vector <int> seq;
    seq.push_back(n);
    int cur = n;
    while (cur != 1) {
        if (dp[cur] - dp[cur-2] == mosq[cur]) {
            cur -= 2;
            seq.push_back(cur);
        }
        else {
            cur -= 3;
            seq.push_back(cur);
        }
    }
    for (int i = seq.size() - 1; i >= 0; i--)
        cout << seq[i] << " ";
}