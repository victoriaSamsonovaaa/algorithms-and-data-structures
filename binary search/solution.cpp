#include <iostream>
#include <vector>
using namespace std;

int Binary(int x, vector<int> &arr) {
    int left = 0;
    int right = arr.size();
    while (left < right) {
        int mid = (left + right)/2;
        if (x == arr[mid])
            return 1;
        else if (x < arr[mid])
            right = mid;
        else
            left = mid + 1;
    }
    return 0;
}
int LowerBound(int x, vector<int> &arr) {
    int left = 0;
    int right = arr.size();
    while (left < right) {
        int mid = (left + right)/2;
        if (x <= arr[mid])
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int UpperBound(int x, vector<int> &arr) {
    int left = 0;
    int right = arr.size();
    while (left < right) {
        int mid = (left + right)/2;
        if (x < arr[mid])
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int main() {
  int n;
  cin >> n;
  vector <int> Elem(n);
  for (int i = 0; i < n; i++) {
      cin >> Elem[i];
  }
  int k;
  int el;
  cin >> k;
  for (int i  = 0; i < k; i++) {
      cin >> el;
      int b = Binary(el, Elem);
      int l = LowerBound(el, Elem);
      int r = UpperBound(el, Elem);
      cout << b << " " << l << " " << r << endl;
  }
}