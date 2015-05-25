#include <iostream>

using namespace std;

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
}TNode, *TreeNode;


class Solution {
    public:
        TreeNode createTree() {
            TreeNode T;
            int val;
            cin >> val;
            if (-1 != val) {
                T = new TNode;
                T->val = val;
                T->left = createTree();
                T->right = createTree();
            } else {
                T = nullptr;
            }
            return T;
        }
        bool isSameTree(TreeNode p, TreeNode q) {
            if (p == nullptr && q == nullptr)
                return true;
            if (p == nullptr || q == nullptr)
                return false;
            if (p && q) {
                bool bl;
                if (p->val != q->val)
                    return false;
                bl = isSameTree(p->left, q->left);
                if (bl == false)
                    return false;
                bl = isSameTree(p->right, q->right);
                if (bl == false)
                    return false;
                return true;
            }
        }
};



int main(int argc, const char*argv[])
{
    Solution s;
    TreeNode p, q;
    p = s.createTree();
    q = s.createTree();

    cout << (s.isSameTree(p, q) ? "same" : "not same") << endl; 
    return 0;
}
