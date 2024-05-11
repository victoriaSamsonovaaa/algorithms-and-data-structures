#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int m, c, n, x;
    //cin >> m >> c >> n;
    fin >> m >> c >> n;
    vector<int> hash(m, -1);
    for (int j = 0; j < n; j++) {
        //cin >> x;
        fin >> x;
        for (int i = 0; i <= m - 1; i++) {
            int h = ((x % m) + c * i) % m;
            if (hash[h] == -1) {
                hash[h] = x;
                break;
            }
            if (hash[h] == x) {
                break;
            }
        }
        /* while (true) {
            int h = ((x % m) + c * i) % m;
            if (hash[h] == -1) {
                hash[h] = x;
                break;
            }
            i++;
        }
*/
    }
    for (int i = 0; i < m; i++) {
        //cout << hash[i] << ' ';
        fout << hash[i] << ' ';
    }
    fin.close();
    fout.close();
}