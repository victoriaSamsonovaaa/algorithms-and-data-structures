#include <iostream>
#include <fstream>
#include <vector>

#define int long long
using namespace std;

struct node
{
    int value;
    int minval;
    int maxval;
};

signed main()
{

    ifstream fin("bst.in");
    ofstream fout("bst.out");

    int n;
    fin >> n;
    vector <node> tree(n+1);
    int root;
    fin >> root;
    tree[1].value = root;
    tree[1].minval = -1e18;
    tree[1].maxval = 1e18;
    int m, p;
    char c;

    for (int i = 2; i <= n; i++)
    {
        fin >> m >> p >> c;
        tree[i].value = m;

        if (c == 'L') {
            tree[i].minval = tree[p].minval;
            tree[i].maxval = tree[p].value;
        }
        else {
            tree[i].minval = tree[p].value;
            tree[i].maxval = tree[p].maxval;
        }

        if (
                (m < tree[p].minval || m >= tree[p].maxval) ||
                (c == 'R' && m < tree[p].value) ||
                (c == 'L' && m >= tree[p].value)
                ) {
            fout << "NO";
            return 0;
        }
    }
    fout << "YES";
    return 0;
}