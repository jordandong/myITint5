/*
有n个左右端点都为整数的区间，判断每个区间是否有与其它某个区间相交（区间端点重合也算相交）。
*/

/*
struct Interval {
    int start;   //区间左端点
    int end;   //区间右端点
};
*/

// intervals包含n个区间
// 结果存放到isIntersected中(已分配空间,不需要push_back)
// isIntersected[i]表示第i个区间是否与其它区间相交

bool a_less_b(const pair<Interval, int> &r, const pair<Interval, int> &s){
    return r.first.start < s.first.start;
}

void intersected(vector<Interval> &intervals, vector<bool> &isIntersected) {
    int size = intervals.size();
    if(!size)
        return;
    
    vector<pair<Interval, int> > data;
    for(int i=0;i<size;i++)
        data.push_back(make_pair(intervals[i], i));
    
    sort(data.begin(), data.end(), a_less_b);
    
    int last_intval_id = 0;
    for(int i=1; i<size; i++){
        if(data[i].first.start<=data[last_intval_id].first.end){
            isIntersected[data[i].second] = true;
            isIntersected[data[last_intval_id].second] = true;
        }
        if(data[i].first.end >= data[last_intval_id].first.end)
            last_intval_id = i;
    }
}
