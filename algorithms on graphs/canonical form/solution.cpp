#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n;
    fin >> n;
    vector <int> k(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        fin >> u >> v;
        k[v] = u;
    }
    for (int j = 1; j <= n; j++)
        fout << k[j] << " ";
    fin.close();
    fout.close();
}