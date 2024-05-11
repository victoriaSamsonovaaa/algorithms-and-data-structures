#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#define int long long
using namespace std;

struct Node
{
    int symbol;
    int frequency;
    Node *left, *right;
};

Node* createNode(int symbol, int frequency, Node* left, Node* right)
{
    Node* node = new Node();

    node->symbol = symbol;
    node->frequency = frequency;
    node->left = left;
    node->right = right;

    return node;
}

struct comp
{
    bool operator()(Node* l, Node* r)
    {
        return l->frequency > r->frequency;
    }
};

int ans = 0;

void archivate(Node* root, string str)
{
    if (root == nullptr)
        return;

    if (!root->left && !root->right)
    {
        ans += str.size() * root->frequency;
    }

    archivate(root->left, str + "0");
    archivate(root->right, str + "1");
}

void build(vector <int> frequency)
{
    priority_queue <Node*, vector<Node*>, comp> active;
    for (int i = 1; i < frequency.size(); i++)
    {
        active.push(createNode(i, frequency[i], nullptr, nullptr));
    }

    while (active.size() != 1)
    {
        Node *left = active.top();
        active.pop();
        Node *right = active.top();
        active.pop();

        int sum = left->frequency + right->frequency;

        active.push(createNode(-1, sum, left, right));
    }
    Node* root = active.top();
    archivate(root, "");
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ifstream cin("huffman.in");
    ofstream cout("huffman.out");

    int n;
    cin >> n;
    vector <int> frequency(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> frequency[i];
    }
    build(frequency);
    cout << ans;
    return 0;
}