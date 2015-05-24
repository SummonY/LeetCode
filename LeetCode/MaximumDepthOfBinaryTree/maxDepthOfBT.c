#include <stdio.h>
#include <malloc.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
}TNode, *TreeNode;


TreeNode createTree();
int maxDepth(TreeNode root);

int main(int argc, const char *argv[])
{
    TreeNode T;
    T = createTree();
    printf("maximum depth = %d\n", maxDepth(T));
    return 0;
}

TreeNode createTree()
{
    TreeNode T;
    int val;
     scanf("%d", &val);
     if (val != -1) {
        T = (TreeNode)malloc(sizeof(TNode));
        T->val = val;
        T->left = createTree();
        T->right = createTree();
     } else {
         T = NULL;
     }
     return T;
}

int maxDepth(TreeNode root)
{
    int l, r;
    if (NULL == root)
        return 0;
    l = maxDepth(root->left);
    r = maxDepth(root->right);
    return (l > r) ? l + 1 : r + 1;
}
