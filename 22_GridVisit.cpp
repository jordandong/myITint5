/*
有一个n*m（n和m都不超过50）的棋盘，有k个目标格子需要访问。需要访问的格子的横纵坐标存放在数组x[]和y[]中(0<=x[i]<n, 0<=y[i]<m)。

遍历的规则为：
每一步只能从一个目标格子水平或者竖直跳跃移动到另一个目标格子。
连续的两步必须形成直角。即如果前一步是水平移动，那么下一步只能竖直移动。
问是否存在一种遍历顺序，使得每个目标格子有且仅被访问一次。

样例：k=8, x=[0, 0, 0, 0, 2, 2, 4, 4], y=[0, 2, 4, 6, 4, 6, 2, 4],对应于下图中A, B, C, D, F, E, G, H 8个目标格子，存在满足条件的遍历A->D->E->F->C->B->G->H。
A _ B _ C _ D
_ _ _ _ _ _ _
_ _ _ _ F _ E
_ _ _ _ _ _ _
_ _ G _ H _ _ 

*/


//如果存在满足条件的遍历,返回true,否则返回false
bool existPath(vector<int> &x, vector<int> &y) {
    int size = x.size();
    if(!size)
        return true;
    
    unordered_map<int, int> mapx, mapy;
    int xcount =0;
    int ycount =0;
    for(int i=0; i<size; i++){
        unordered_map<int, int>::const_iterator it=mapx.find(x[i]);
        if(it==mapx.end()){
            xcount++;
            mapx.insert(make_pair(x[i], 1));
        }else{
            if(it->second==2){
                xcount++;
                mapx.erase(x[i]);
                mapx.insert(make_pair(x[i], 1));
            }else{
                xcount--;
                mapx.erase(x[i]);
                mapx.insert(make_pair(x[i], 2));
            }
        }
        
        it=mapy.find(y[i]);
        if(it==mapy.end()){
            ycount++;
            mapy.insert(make_pair(y[i], 1));
        }else{
            if(it->second==2){
                ycount++;
                mapy.erase(y[i]);
                mapy.insert(make_pair(y[i], 1));
            }else{
                ycount--;
                mapy.erase(y[i]);
                mapy.insert(make_pair(y[i], 2));
            }
        }
    }
    
    if(xcount+ycount!=2 && xcount+ycount!=0)
        return false;
    
    //above practise unordered_map usage
    //below check the connectivity
    
    mapx.clear();
    mapy.clear();
    mapx.insert(make_pair(x[0], 0));
    mapy.insert(make_pair(y[0], 0));
    int last = size-1;
    int i=0;
    for(i=1; i<=last;){
        if(mapx.find(x[i])!=mapx.end() || mapy.find(y[i])!=mapy.end()){
            mapx.insert(make_pair(x[i], 0));
            mapy.insert(make_pair(y[i], 0));
            last = size-1;
            i++;
        }else{
            swap(x[i], x[last]);
            swap(y[i], y[last]);
            last--;
        }
    }    
    return i==size;
    
}

/*
bool existPath(vector<int> &x, vector<int> &y) {
    if(x.size()==0) return true;
    bool axis[100] = {false};
    for(int i = 0; i < x.size(); i++){
        axis[x[i]] = !axis[x[i]];
    }
    for(int i = 0; i < y.size(); i++){
        axis[50+y[i]] = !axis[50+y[i]];
    }
    int count = 0;
    for(int i = 0; i < 100; i++){
        if(axis[i]) count++;
    }
    if(count > 2) return false;

    //判断连通性
    bool xa[50] = {false};
    bool ya[50] = {false};
    xa[x[0]] = true;
    ya[y[0]] = true;
    int i = 1, j = x.size()-1;
    while(i <= j){
        if(xa[x[i]] || ya[y[i]]){
            xa[x[i]] = true;
            ya[y[i]] = true;
            i++;
            j = x.size()-1;
        }
        else{
            int xt = x[j], yt = y[j];
            x[j] = x[i];
            y[j] = y[i];
            x[i] = xt;
            y[i]= yt;
            j--;
        }
    }
    return i==x.size();
}
*/

/*
bool existPath(vector<int> &x, vector<int> &y) {
    if(x.size()==0) return true;
    bool axis[100] = {false};
    for(int i = 0; i < x.size(); i++){
        axis[x[i]] = !axis[x[i]];
    }
    for(int i = 0; i < y.size(); i++){
        axis[50+y[i]] = !axis[50+y[i]];
    }
    int count = 0;
    for(int i = 0; i < 100; i++){
        if(axis[i]) count++;
    }
    if(count !=2 && count != 0) return false;

    //判断连通性    
    unordered_map<int, unordered_set<int>> graph;
    unordered_set<int> needVisit;
    for(int i = 0; i < x.size(); i++) {        
        graph[x[i]].insert(50 + y[i]);
        graph[50 + y[i]].insert(x[i]);
        needVisit.insert(x[i]);
        needVisit.insert(50 + y[i]);
    } 

    unordered_set<int> visited; 

    queue<int> toVisit;
    toVisit.push(x[0]);    
    while(toVisit.size() > 0){
        int current = toVisit.front();
        toVisit.pop();
        visited.insert(current);
        for (unordered_set<int>::const_iterator itr = graph[current].begin();
             itr != graph[current].end(); ++itr)
        {
             if (visited.count(*itr) == 0)
                toVisit.push(*itr); 
        }
    }        
    return visited.size() == needVisit.size();
}
*/
