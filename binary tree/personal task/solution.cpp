#include <iostream>
#include <fstream>

using namespace std;

class Node {
public:
    int Key;
    Node *Left = nullptr;
    int LeftCnt = 0;
    Node *Right = nullptr;
    int RightCnt = 0;

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

    void PostTraversal(Node *node)
    {
        if(node != nullptr)
        {
            PostTraversal(node->Left);
            PostTraversal(node->Right);
            if(node->Left && node->Right)
            {
                node->LeftCnt = node->Left->LeftCnt + node->Left->RightCnt + 1;
                node->RightCnt = node->Right->LeftCnt + node->Right->RightCnt + 1;
            }
            else
                if(node->Left)
                    node->LeftCnt = node->Left->LeftCnt + node->Left->RightCnt + 1;
                else
                    if (node->Right)
                        node->RightCnt = node->Right->LeftCnt + node->Right->RightCnt + 1;
        }
    }

    void FindMaxNode(Node* node, int& maxDiff, int& maxDiffNode)
    {
        if (node != nullptr)
        {
            FindMaxNode(node->Right, maxDiff, maxDiffNode);
            if (abs(node->RightCnt - node->LeftCnt) > maxDiff)
            {
                maxDiff = abs(node->RightCnt - node->LeftCnt);
                maxDiffNode = node->Key;
            }
            FindMaxNode(node->Left, maxDiff, maxDiffNode);
        }
    }

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
    ifstream fin("tst.in");
    ofstream fout("tst.out");
    int k;
    BinTree tree;
    while (fin >> k)
        tree.Insert(k);
    fin.close();
    tree.PostTraversal(tree.Root); ///найти кол-во потомков для каждой вершины

    int maxDiff = -1;
    int maxDiffNode = 0;
    tree.FindMaxNode(tree.Root, maxDiff, maxDiffNode); ///найти макс. вершину с макс. разницей
    ///удалить её
    tree.Root = tree.deleteNode(tree.Root, maxDiffNode);
    tree.PreOrderTraversal(tree.Root, fout);
    fout.close();
}