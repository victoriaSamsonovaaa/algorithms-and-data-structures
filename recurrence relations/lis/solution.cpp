#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int UpperBound(const int &x, const vector<int> &arr) {
    int left = 0;
    int right = arr.size() - 1;
    while (left < right) {
        int mid = right - (right - left)/2;
        if (arr[mid] <= x)
            left = mid;
        else
            right = mid - 1;
    }
    return left + 1;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n;
    fin >> n;

    vector<int> sequence(n);
    vector<int> dp(n+1);
    for (int i = 0; i < n; i++)
        fin >> sequence[i];

    dp[0] = -2e9;

    for (int i = 1; i <= n; i++) {
        dp[i] = 2e9;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int j = UpperBound(sequence[i], dp);
        if (dp[j-1] < sequence[i] && sequence[i] < dp[j]) {
            dp[j] = sequence[i];
            ans = max(ans, j);
        }
    }
    fout << ans;
    fin.close();
    fout.close();
    return 0;

}