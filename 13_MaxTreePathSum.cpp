/*
给定一棵树的根结点，树中每个结点都包含一个整数值val。我们知道树中任意2个结点之间都存在唯一的一条路径，路径值为路径上所有结点值之和。请计算最大的路径值（允许路径为空）。

样例：

      -10
     /  |  \
    2   3   4
       / \
      5  -1
         /
        6
       /
      -1
最大的路径值为13，相应的路径为5到6之间的路径。
扩展：此题算法也可用来解决另一个非常常见的面试题“树的直径”（求树中任意两结点路径的长度的最大值）。可以认为树中每个结点的val值为1，那么求最长路径相当于求路径值最大的路径。
*/

/*
树结点的定义(请不要在代码中定义该类型)
struct TreeNode {
    int val;
    vector<TreeNode*> children;  //该结点的儿子结点
 };
*/
#include<limits.h>

//return val is the biggest child val
int preOrder(TreeNode *root, int &global_max){
    if(!root)
        return 0;
    vector<TreeNode*> cld = root->children; 
    int size = cld.size();
    int max1 = 0, max2 = 0;
    for(int i=0; i<size; i++){
        int tmp = preOrder(cld[i], global_max);
        if(tmp>max1){
            max2=max1;
            max1=tmp;
        }
        else if(tmp>max2)
            max2=tmp;
    }
    global_max = global_max> max1 + max2 + root->val?global_max:max1+ max2+root->val;
    return max1 + root->val;    
}

int maxTreePathSum(TreeNode *root) {
    if(!root)
        return 0;
    
    int global_max = INT_MIN;
    preOrder(root, global_max);
    return global_max>0?global_max:0;
}
