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

    static Node* deleteNode(Node* node, int x) {
        if (node == nullptr)
            return node;
        if (x < node->Key) {
            node->Left = deleteNode(node->Left, x);
            return node;
        }
        else if (x > node->Key) {
            node->Right = deleteNode(node->Right, x);
            return node;
        }
        else {
            if (node->Left == nullptr)
                return  node->Right;
            else if (node->Right == nullptr)
                return  node->Left;
            else {
                int min_key = findMinNode(node->Right)->Key;
                node->Key = min_key;
                node->Right = deleteNode(node->Right, min_key);
                return node;
            }
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

    static Node* findMinNode(Node* node) {
        if (node->Left != nullptr)
            return findMinNode(node->Left);
        return node;
    }
};

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int necKey, k;
    BinTree tree;
    fin >> necKey;
    while (!fin.eof()) {
        fin >> k;
        tree.Insert(k);
    }
    fin.close();
    tree.Root = tree.deleteNode(tree.Root, necKey);
    tree.PreOrderTraversal(tree.Root, fout);
    fout.close();
}