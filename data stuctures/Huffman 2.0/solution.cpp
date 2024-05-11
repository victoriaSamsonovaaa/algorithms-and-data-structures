#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

long long Huff(vector<long long> a) {
    vector<long long> b(a.size());
    int i = 0;
    int j = 0;
    long long ans = 0;
    for (int k = 0;k < b.size(); k++)
        b[k] = 9999999999999999;
    a.resize(a.size() + 2);
    a[a.size() - 1] = b[0];
    a[a.size() - 2] = b[0];
    for (int k = 0; k < b.size() - 1; k++) {
        if (a[i] + a[i + 1] <=a[i] + b[j] && a[i] + a[i + 1] <= b[j] + b[j + 1]) {
            b[k] = a[i] + a[i + 1];
            ans += b[k];
            i +=2;
        }
        else if (a[i] + b[j] <= a[i] + a[i + 1] && a[i] + b[j] <= b[j] + b[j + 1]) {
            b[k] = a[i] + b[j];
            ans += b[k];
            i++;
            j++;
        }
        else if (b[j] + b[j + 1] <= a[i] + a[i + 1] && b[j] + b[j + 1] <= a[i] + b[j]) {
            b[k] = b[j] + b[j + 1];
            ans += b[k];
            j += 2;
        }
    }
    return ans;
}

int main() {
ifstream fin("huffman.in");
ofstream fout("huffman.out");
int n;
fin >> n;
//cin >> n;
vector<long long> a(n);
for (int i = 0; i < n; i++)
    fin >> a[i];
    //cin >> a[i];
long long ans = Huff(a);
fout << ans;
//cout << ans;
fin.close();
fout.close();
return 0;
}