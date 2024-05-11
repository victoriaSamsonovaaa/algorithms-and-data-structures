#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n;
    fin >> n;
    //cin >> n;
    vector<long long> heapElem(n + 1);
    for (int i = 1; i <= n; i++) {
        fin >> heapElem[i];
        //cin >> heapElem[i];
    }

    for (int i = 1; i <= n / 2; i++) {
        int j = i * 2;
        int k = i * 2 + 1;
        if (j <= n && heapElem[i] > heapElem[j]) {
            //cout << "No";
            fout << "No";
            return 0;
        }
        if (k <= n && heapElem[i] > heapElem[k]) {
            //cout << "No";
            fout << "No";
            return 0;
        }
    }
    fout << "Yes";
    //cout << "Yes";
    fin.close();
    fout.close();
}