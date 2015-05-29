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

        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> ivec;
            stack<TreeNode*> tStack;
            TreeNode *p = root;

            while (p || !tStack.empty()) {
                if (p) {
                    tStack.push(p);
                    ivec.push_back(p->val);
                    p = p->left;
                }
                else {
                    p = tStack.top();
                    tStack.pop();
                    p = p->right;
                }
            }
            return ivec;
        }

        vector<int> inorderTraversal(TreeNode *root) {
            vector<int> ivec;
            stack<TreeNode*> tStack;
            TreeNode *p = root;

            while (p || !tStack.empty()) {
                if (p) {
                    tStack.push(p);
                    p = p->left;
                }
                else {
                    p = tStack.top();
                    tStack.pop();
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
    
    cout << "create binary tree :" << endl;  
    T = s.createBinaryTree();
    cout << "preorder traversal :" << endl;  
    ivec = s.preorderTraversal(T);
    for (auto i = 0; i < ivec.size(); ++i) {
        cout << ivec[i] << " ";
    }
    cout << endl;

    cout << "inorder traversal : " << endl;
    ivec = s.inorderTraversal(T);
    for (auto i = 0; i < ivec.size(); ++i) {
        cout << ivec[i] << " ";
    }
    cout << endl;
    return 0;
}
