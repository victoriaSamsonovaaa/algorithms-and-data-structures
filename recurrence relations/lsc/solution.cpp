//5 задача
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    vector<int> B(n);
    for (int j = 0; j < n; j++)
        cin >> B[j];

    vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else if (A[i - 1] != B[j - 1]){
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][n] <<'\n';
    //int amount = dp[n][n];

    vector<int> subA(0);
    vector<int> subB(0);
    int i = n;
    int j = n;
    while (i > 0 && j > 0) {
        if (A[i - 1] == B[j - 1]) {
            subA.push_back(i - 1);
            subB.push_back(j - 1);
            i--;
            j--;
        }
        else if (A[i - 1] != B[j - 1]) {
            if (dp[i][j] == dp[i - 1][j])
                i--;
            else if (dp[i][j] == dp[i][j - 1])
                j--;
        }
    }

    reverse(subA.begin(), subA.end());
    for (int i = 0; i < subA.size() ; i++)
        cout << subA[i] << ' ';
    cout << '\n';
    reverse(subB.begin(), subB.end());
    for (int i = 0; i < subB.size() ; i++)
        cout << subB[i] << ' ';
    return 0;
}