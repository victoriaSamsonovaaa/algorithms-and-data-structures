#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    int x, y, z;
    fin >> x;
    fin >> y;
    fin >> z;
    string A, B;
    fin >> A;
    fin >> B;
    int lenA = A.size();
    int lenB = B.size();
    vector <vector<int>> dp(lenA + 1, vector<int> (lenB + 1, 0));

    if (lenA == 0)
        fout << lenB * y;
    if (lenB == 0)
        fout << lenA * x;

    for (int i = 0; i <= lenA; i++)
        dp[i][0] = i * x;

    for (int j = 0; j <= lenB; j++)
        dp[0][j] = j * y;

    for (int i = 1; i <= lenA; i++) {
        for (int j = 1; j <= lenB; j++) {
            if (A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else if (A[i - 1] != B[j - 1])
                dp[i][j] = min(dp[i - 1][j - 1] + min(x + y, z), min(dp[i - 1][j] + x, dp[i][j - 1] + y));
        }
    }
    fout << dp[lenA][lenB];
    fin.close();
    fout.close();
    return 0;
}