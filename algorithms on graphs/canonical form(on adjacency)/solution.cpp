#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n;
    fin >> n;
    vector <int> k(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int b;
            fin >> b;
            if (b == 1) {
                k[j] = i;
            }
        }
    }
    for (int j = 1; j <= n; j++)
        fout << k[j] << " ";
    fin.close();
    fout.close();
}