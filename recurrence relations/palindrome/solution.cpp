#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main() {
        ifstream fin("input.txt");
        ofstream fout("output.txt");
        string S, revS;
        fin >> S;
        revS = S;
        reverse(revS.begin(), revS.end());
        int len = S.length();

        vector<vector<int>> dp(len + 1, vector<int>(len + 1, 0));

        for (int i = 1; i <= len; i++) {
            for (int j = 1; j <= len; j++) {
                if (S[i - 1] == revS[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else if (S[i - 1] != revS[j - 1]) {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        fout << dp[len][len] << '\n';
        //int amount = dp[n][n];

        vector<char> subS;
        vector<char> subRevS;
        int i = len;
        int j = len;
        while (i > 0 && j > 0) {
            if (S[i - 1] == revS[j - 1]) {
                subS.push_back(S[i - 1]);
                subRevS.push_back(revS[j - 1]);
                i--;
                j--;
            }
            else if (S[i - 1] != revS[j - 1]) {
                if (dp[i][j] == dp[i - 1][j])
                    i--;
                else if (dp[i][j] == dp[i][j - 1])
                    j--;
            }
        }

        reverse(subS.begin(), subS.end());
        for (int i = 0; i < subS.size(); i++)
            fout << subS[i];
        fout << '\n';
        fin.close();
        fout.close();
        return 0;
    }