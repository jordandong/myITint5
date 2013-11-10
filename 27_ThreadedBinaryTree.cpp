/*
将一棵普通二叉树转换为一棵线索二叉树（查看定义）。

详细说明：树结点除了包含left, right指针外，还包含isLeftThread和isRightThread，初始时isLeftThread和isRightThread都为false。对于left为null的结点，请将left设置为中序遍历该结点的前驱结点，并将isLeftThread设置为true。对于right为null的结点，请将right设置为中序遍历该结点的后继结点，并将isRightThread设置为true。

提示：请尝试使用非递归算法。
*/

/*树结点的定义(请不要在代码中定义该结构)
struct TreeNode {
  TreeNode *left, *right;
  bool isLeftThread, isRightThread;
}*/

void helper(TreeNode* root, TreeNode* p, TreeNode* s){
    
    if(!root)
        return;
    
    helper(root->left, p, root);
     
    if(p && !root->left){
        root->left = p;
        root->isLeftThread = true;
    }
    TreeNode* tmp = root->right;
    if(s && !root->right){
        root->right = s;
        root->isRightThread = true;
    }
    
    helper(tmp, root, s);
}

void convertToThreadedTree(TreeNode *root) {
    helper(root, NULL, NULL);
}

/*
#include<stack>
void convertToThreadedTree(TreeNode *root) {
    stack<TreeNode*> stk;
    TreeNode* last = NULL;
    while (root != NULL || !stk.empty()){
        //deal with leftsubtree
		while (root){
			stk.push(root);
			root = root->left;
		}
		//visit value of node
		root = stk.top();
		stk.pop();
        if(last && !last->right){
            last->right = root;
            last->isRightThread = true;
        }
        if(last && !root->left){
            root->left = last;
            root->isLeftThread = true;
        }
        last = root;
		//deal with right subtree
		root = root->right;
	}  
}
*/
