#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int m, n;
    fin >> n >> m;
    vector<vector<int>> sm(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        sm[v - 1].push_back(u);
        sm[u - 1].push_back(v);
    }

    for (int i = 0; i < n; i++) {
        fout << sm[i].size() << " ";
        for (int j = 0; j < sm[i].size(); j++)
            fout << sm[i][j] << " ";
        fout << '\n';
    }
    fin.close();
    fout.close();
}