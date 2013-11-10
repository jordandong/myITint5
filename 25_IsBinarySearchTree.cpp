/*
给定一棵二叉树的根结点，树中每个结点包含一个整数值val以及左右儿子结点指针left, right，判断该树是否为二叉搜索数(Binary Search Tree)。

二叉搜索树的简单定义：对于树中任意一棵以T为根结点的子树，T的val值大于等于其左子树中任意结点的val值，小于其右子树中任意结点的val值。
*/

/*
树结点的定义(请不要在代码中定义该结构)
struct TreeNode {
  int val;
  TreeNode *left, *right;
}*/
#include<limits.h>

bool isBSTHelper(TreeNode *root, int min, int max){
    if(!root)
        return true;
    if(min<root->val && root->val<=max)
        return isBSTHelper(root->left, min, root->val) && isBSTHelper(root->right, root->val, max);
    else
        return false;
}

bool isBST(TreeNode *root) {
    return isBSTHelper(root, INT_MIN, INT_MAX);
}
