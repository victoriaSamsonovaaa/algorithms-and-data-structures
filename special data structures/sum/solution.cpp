#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void Add(vector<long long>& a, vector<long long>& b, long long i, long long x, long long k) {
    a[i] += x;
    b[i / k] += x;
}

long long FindSum(vector<long long>& a, vector<long long>& b, long long l, long long r, long long k) {
    long long sum = 0;
    long long jl = l / k;
    long long jr = r / k;
    if (jl == jr) {
        for (int i = l; i < r; i++) {
            sum += a[i];
        }
    }
    else {
        for (int i = l; i < (jl + 1) * k; i++)
            sum += a[i];
        for (int i = jl + 1; i < jr; i++)
            sum += b[i];
        for (int i = jr * k; i < r; i++)
            sum += a[i];
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   long long n;
   cin >> n;
   vector<long long> elem(n);
   for (int i = 0; i < n; i++)
       cin >> elem[i];
   long long k = sqrt(n);
   vector<long long> b(n / k + 1, 0);
   for (int i = 0; i < n; i++) {
       b[i / k] += elem[i];
   }

   long long q;
   cin >> q;
    for (int i = 0; i < q; i++) {
        string query;
        cin >> query;
        if (query == "Add") {
            long long index, value;
            cin >> index >> value;
            Add(elem, b, index, value, k);
        } else if (query == "FindSum") {
            long long l, r;
            cin >> l >> r;
            long long sum = FindSum(elem, b, l, r, k);
            cout << sum << endl;
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очистка буфера ввода
    }
    return 0;
}