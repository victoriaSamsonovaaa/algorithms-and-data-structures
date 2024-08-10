#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int m, n;
    fin >> n >> m;
    vector<vector<bool>> sm(n, vector<bool> (n, 0));
    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        sm[u - 1][v - 1] = 1;
        sm[v - 1][u -1] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            fout << sm[i][j] << " ";
        fout << '\n';
    }

    fin.close();
    fout.close();
}