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
        p[x] = FindSet(p, p[x]);
        return p[x];
    }
}

//функция объединения
void Union(vector<int>& p, int a, int b) {
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
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n, m, q;
    fin >> n >> m >> q;
    vector<int> parent(n + 1, -1);
    components = n;
    vector<pair<int, int>> cities;
    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        cities.push_back({u, v});
    }
    vector<bool> deleted(m + 1);
    vector<int> earthquakes(q);
    for (int i = 0; i < q; i++) {
        int x;
        fin >> x;
        earthquakes[i] = x;
        deleted[x] = true;
    }

    for (int i = 0; i < m; i++) {
        if (!deleted[i + 1]) {
            Union(parent, cities[i].first, cities[i].second);
        }
    }

    vector<int> final(q);
    for (int i = q - 1; i >= 0; i--) {
        if (components == 1)
            final[i] = 1;
        else {
            final[i] = 0;
            Union(parent, cities[earthquakes[i] - 1].first, cities[earthquakes[i] - 1].second); 
        }
    }

    for (int i = 0; i < q; i++) {
        fout << final[i];
    }

    fin.close();
    fout.close();
}