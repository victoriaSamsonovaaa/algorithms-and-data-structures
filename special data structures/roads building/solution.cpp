#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int components;
// функция найти родителя
int FindSet(vector<int>& p, int x) {
    if (p[x] < 0)
        return x;
    else {
        p[x] = FindSet (p, p[x]);
        return p[x];
    }
}

//функция объединения
int Union(vector<int>& p, int a, int b) {
    a = FindSet(p, a);
    b = FindSet(p, b);
    if (a != b) {
        if (p[a] < p[b]) {
            p[a] += p[b];
            p[b] = a;
        } else {
            p[b] += p[a];
            p[a] = b;
        }
        --components;
    }
    return components;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n, q;
    fin >> n >> q;
    //cin >> n >> q;
    vector<int> parent(n, -1);
    components = n;
    vector<int> comp;
    int u, v;
    for (int i = 0; i < q; i++) {
        fin >> u >> v;
        //cin >> u >> v;
        comp.push_back(Union(parent, --u, --v));
    }
    for (int i = 0; i < comp.size(); i++)
        //cout << comp[i] << '\n';
        fout << comp[i] << '\n';

    fin.close();
    fout.close();
}