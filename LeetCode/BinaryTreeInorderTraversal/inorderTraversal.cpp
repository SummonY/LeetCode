#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {

    }
};

class Solution {
    public:
        TreeNode* createBinaryTree() {
            TreeNode *T;
            int val;
            scanf("%d", &val);
            if (val != -1) {
                T = (TreeNode *)malloc(sizeof(TreeNode));
                T->val = val;
                T->left = createBinaryTree();
                T->right = createBinaryTree();
            }
            else {
                T = NULL;
            }
            return T;
        }

        vector<int> inorderTraversal(TreeNode *root) {
            vector<int> ivec;
            stack<TreeNode*> Tstack;
            TreeNode *p = root;

            while (p || !Tstack.empty()) {
                if (p) {
                    Tstack.push(p);
                    p = p->left;
                }
                else {
                    p = Tstack.top();
                    Tstack.pop();
                    ivec.push_back(p->val);
                    p = p->right;
                }
            }
            return ivec;
        }
};

int main(int argr, const char *argv[])
{
    TreeNode *T;
    Solution s;
    vector<int> ivec;
    
    T = s.createBinaryTree();
    ivec = s.inorderTraversal(T);
    for (auto i = 0; i < ivec.size(); ++i) {
        cout << ivec[i] << " ";
    }
    cout << endl;

    return 0;
}
