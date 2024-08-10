#include <iostream>
#include <fstream>

using namespace std;

class Node {
public:
    int Key;
    Node *Left = nullptr;
    Node *Right = nullptr;

    Node(int key) {
        this -> Key = key;
    }
};

class BinTree {
public:
    BinTree() {
        this->Root = nullptr;
    }

    ~BinTree() {
        DestroyNode(Root);
    }
    
    void Insert(int x) {
        Node **cur = &Root;
        while (*cur) {
            Node &node = **cur;
            if (x < node.Key) {
                cur = &node.Left;
            } else if (x > node.Key) {
                cur = &node.Right;
            } else return;
        }
        *cur = new Node(x);
    };

    void PreOrderTraversal(Node *node, ofstream &file) {
        if (node != nullptr) {
            file << node->Key << "\n";
            PreOrderTraversal(node->Left, file);
            PreOrderTraversal(node->Right, file);
        }
    }
    Node *Root;

private:
    static void DestroyNode(Node *node) {
        if (node) {
            DestroyNode(node->Left);
            DestroyNode(node->Right);
            delete node;
        }
    }
};

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int k;
    BinTree tree;
    while (fin >> k ) {
        tree.Insert(k);
    }
    fin.close();
    tree.PreOrderTraversal(tree.Root, fout);
    fout.close();
}