#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int ind = 1;

void bfs(int start, int n, vector<vector<int>>& s, vector<bool>& vis, vector<int>& r) {
    queue<int> q;
    r[start] = ind;
    ind += 1;
    vis[start] = true;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        
        for (int u = 0; u < n; u++) {
            if (s[v][u] && !vis[u]) {
                vis[u] = true;
                r[u] = ind;
                ind++;
                q.push(u);
            }
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
    vector<bool> viseted(n, false);
    vector<int> result(n, 0);

    for (int i = 0; i < n; i++) {
        if (!viseted[i]) {
            bfs(i, n, smez, viseted, result);
        }
    }
    
    for (int i = 0; i < n ; i++) {
        fout << result[i] << ' ';
        cout << result[i] << ' ';
    }

    fin.close();
    fout.close();
    return 0;
}