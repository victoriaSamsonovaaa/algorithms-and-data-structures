#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> s(n, vector<int>(n));
vector<bool> visited(n, false);
vector<int> res(n, 0);

int ind = 1;

void dfs(int v, int n, vector<vector<int>>& s) {
    visited[v] = true;
    res[v] = ind++;
    for (int u = 0; u < n; u++) {
        if (s[v][u] && !visited[u]) {
            dfs(u, n, s);
        }
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n;
    fin >> n;
    cin >> n;
    vector<vector<int>> smez(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin >> smez[i][j];
            cin >> smez[i][j];
        }
    }
    visited = vector<bool>(n, false);
    res = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n, smez);
        }
    }
    
    for (int i = 0; i < n ; i++) {
        fout << res[i] << ' ';
        cout << res[i] << ' ';
    }

    fin.close();
    fout.close();
    return 0;
}