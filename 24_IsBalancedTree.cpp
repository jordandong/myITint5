/*
给定一棵二叉树的根结点，树中每个结点包含左右儿子结点指针left, right，判断该树是否为平衡二叉树。

平衡二叉树的定义：树中任意结点的左，右子树的高度之差不超过1。

*/

/*
树结点的定义(请不要在代码中定义该结构)
struct TreeNode {
  TreeNode *left;
  TreeNode *right;
}*/

bool isBST(TreeNode *root, int &height){
    if(root==NULL){
        height = 0;
        return true;
    }
    
    int left_h=0;
    int right_h=0;
    bool left = isBST(root->left, left_h);
    bool right = isBST(root->right, right_h);
    height = 1 + max(left_h, right_h);
    return left&&right&&(abs(left_h-right_h)<=1);
}

bool isBalancedTree(TreeNode *root) {
    if(!root)
        return true;
    int left_h=0;
    int right_h=0;
    bool left = isBST(root->left, left_h);
    bool right = isBST(root->right, right_h);
    return left&&right&&(abs(left_h-right_h)<=1);    
}
