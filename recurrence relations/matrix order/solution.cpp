#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    int s;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> s;
    vector< pair <int, int> > size(s + 1);
    vector<vector<int>> dp(s + 1, vector<int> (s + 1));
    for( int i = 1; i <= s; i++)
        fin >> size[i].first >> size[i].second;

    for(int i = 1; i <= s; i++)
        dp[i][i] = 0;
    
    for(int i = 1; i < s; i++)
        dp[i][i + 1] = size[i].first * size[i].second * size[i + 1].second;
    for (int j = 2; j < s; ++j)
    {
        for (int i = 1; i <= s - j; i++)
        {
            dp[i][i + j] = 2147483647;
            for(int k = i; k < i + j; k++)
                dp[i][i + j] = min(dp[i][i + j], dp[i][k] + dp[k + 1][i + j] + size[i].first * size[k].second * size[i + j].second);
        }
    }
    fout << dp[1][s];
    return 0;
}