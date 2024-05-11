#include <iostream>
#include <vector>

using namespace std;

int main() {


    const long long mod = 1e9 + 7;
    int m, n;
    cin >> n >> m;

    vector<long long> prev(m);
    for (int i = 0; i < m; i++)
        prev[i] = 1;
    vector<long long> curr(m);
    for (int i = 1; i < n; i++) {
        curr[0] = 1;
        for (int j = 1; j < m; j++) {
            curr[j] = (curr[j - 1] + prev[j - 1] + prev[j]) % mod;
        }
        prev = curr;
    }
    cout << curr[m-1];
    return 0;
}