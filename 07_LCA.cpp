/*
有一颗树，给定树中任意两个结点，计算出这两个结点的最近公共祖先（查看定义）。

树结点的定义为（请不要在代码中再次定义该结构）：

C/C++
struct TreeNode {
    TreeNode *parent;
}
*/

//返回结点node1和node2的最近公共祖先
TreeNode *getLCA(TreeNode *node1, TreeNode *node2) {
    
    int c1 = 0;
    int c2 = 0;
    TreeNode *n1 = node1;
    TreeNode *n2 = node2;
    while(n1 || n2){
        if(n1){
            c1++;
            n1=n1->parent;
        }
        if(n2){
            c2++;
            n2=n2->parent;
        }
    }
    
    if(c1>c2){
        while(c1!=c2){
            node1 = node1->parent;
            c1--;
        }
    }
    if(c1<c2){
        while(c1!=c2){
            node2 = node2->parent;
            c2--;
        }        
    }
    
    while(node1){
        if(node1 == node2)
            return node1;
        else{
            node1=node1->parent;
            node2=node2->parent;
        }
    }
    
    return NULL;
}
