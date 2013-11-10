/*
复制一个有向图。输入是有向图中的一个结点指针，返回复制的图中对应的结点指针。有向图中结点的定义为：

C++
struct GraphNode {
    int data;
    vector<GraphNode*> neighbors;
    GraphNode(int data) : data(data) {}
};
*/

GraphNode* cloneSub(GraphNode* node, unordered_map<GraphNode*, GraphNode*> &map){
    if(!node)
        return NULL;
    
    if(map.find(node)!=map.end())
        return map.find(node)->second;
    
    GraphNode* new_node = new GraphNode(node->data);
    map.insert(make_pair(node, new_node));
    
    int size = node->neighbors.size();
    for(int i=0; i<size; i++){
        GraphNode* tmp = cloneSub(node->neighbors[i], map);
        if(tmp)
            new_node->neighbors.push_back(tmp);
    }
    return new_node;
}



GraphNode *cloneGraph(GraphNode *node) {
    if(!node)
        return NULL;
    unordered_map<GraphNode*, GraphNode*> map;
    return cloneSub(node, map);
}
