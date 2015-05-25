#include <stdio.h>
#include <malloc.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
}TNode, *TreeNode;

typedef enum {false, true}bool;

TreeNode createTree();
bool isSameTree(TreeNode p, TreeNode q);


int main(int argc, const char*argv[])
{
    TreeNode p, q;
    p = createTree();
    q = createTree();
    printf("%s\n", isSameTree(p, q) ? "same" : "not same");
    return 0;
}

TreeNode createTree()
{
    TreeNode T;
    int val;
    scanf("%d", &val);
    if (val == -1) {
        T = NULL;
    } else {
        T = (TreeNode)malloc(sizeof(TNode));
        T->val = val;
        T->left = createTree();
        T->right = createTree();
    }
    return T;
}

bool isSameTree(TreeNode p, TreeNode q)
{
    if (p == NULL && q == NULL)
       return true;
    if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
    {
        return false;
    }
    if (p && q)
    {
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
