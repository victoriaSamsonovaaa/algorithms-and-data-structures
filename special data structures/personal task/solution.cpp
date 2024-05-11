#include <fstream>
#include <vector>
#include <iostream>
#include <set>
#include <queue>
using namespace std;

vector< vector <int> > graph(101, vector<int>(101));

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int u, v, val;
    while (fin >> u >> v >> val)
        //while (cin >> u >> v >> val)
    {
        graph[u][v] = val;
    }

    for (int i = 1; i <= 100; ++i) {
        vector<int> used(101);
        queue<int> q;
        for (int j = 1; j <= 100; ++j)
            if (graph[i][j] > 50) {
                q.push(j);
                used[j] = true;
            }

        used[i] = true;
        while (!q.empty()) {
            int cur = q.front();
            used[cur] = true;
            q.pop();
            for (int j = 1; j <= 100; ++j) {
                if (i != j && !used[j]) {
                    graph[i][j] += graph[cur][j];
                    if (graph[i][j] > 50)
                    {
                        q.push(j);
                        used[j] = true;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= 100; ++i) {
        for (int j = 1; j <= 100; ++j)
            if (graph[i][j] > 50)
                fout << i << ' ' << j << '\n';
        //cout << i << ' ' << j << '\n';
    }
    fin.close();
    fout.close();
}