/*
给定一棵完全二叉树（查看定义）的根结点，统计该树的结点总数。

树结点类型名为TreeNode，您没必要知道该类型的定义，请使用下面的方法得到某个结点的左，右儿子结点，以及判断某结点是否为NULL。

C/C++
//获得结点node的左儿子结点
TreeNode getLeftChildNode(TreeNode node);
//获得结点node的右儿子结点
TreeNode getRightChildNode(TreeNode node);
//判断结点node是否为NULL
int isNullNode(TreeNode node);
*/

//使用getLeftChildNode(TreeNode)获得左儿子结点
//使用getRightChildNode(TreeNode)获得右儿子结点
//使用isNullNode(TreeNode)判断结点是否为空

int depth(TreeNode root){
    int d = 0;
    while(!isNullNode(root)){
        root = getLeftChildNode(root);
        d++;
    }
    return d;
}

int count_complete_binary_tree_nodes(TreeNode root){
    if(isNullNode(root))
        return 0;
    int dl = depth(getLeftChildNode(root));
    int dr = depth(getRightChildNode(root));
    return dl==dr?(1<<dl)+count_complete_binary_tree_nodes(getRightChildNode(root)):(1<<dr)+count_complete_binary_tree_nodes(getLeftChildNode(root));
}
