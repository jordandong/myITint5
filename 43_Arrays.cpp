/*
有2个大小为n和m的有序数组（升序）a和b，实现2个函数arrayUnion和arrayIntersect计算它们的并集和交集，结果也必须有序。

提示：时间复杂度O(n+m)，空间复杂度O(1)。
*/

vector<int> arrayUnion(vector<int> &a, vector<int> &b) {
    int size_a = a.size(), ia = 0;
    int size_b = b.size(), ib = 0;
    vector<int> res;
    while(ia<size_a || ib<size_b){
        if(ib==size_b){
            if(res.empty() || res.back()!=a[ia])
                res.push_back(a[ia]);
            ia++;
            continue;
        }
        if(ia==size_a){
            if(res.empty() || res.back()!=b[ib])
                res.push_back(b[ib]);
            ib++;
            continue;
        }
        
        
        if(a[ia]==b[ib]){
            if(res.empty() || res.back()!=a[ia])
                res.push_back(a[ia]);
            ia++, ib++;
        }
        else if (a[ia]<b[ib]){
            if(res.empty() || res.back()!=a[ia])
                res.push_back(a[ia]);     
            ia++;
        }else{
            if(res.empty() || res.back()!=b[ib])
                res.push_back(b[ib]); 
            ib++;
        }
    }
    return res;
}

vector<int> arrayIntersect(vector<int> &a, vector<int> &b) {
    int size_a = a.size(), ia = 0;
    int size_b = b.size(), ib = 0;
    vector<int> res;
    while(ia<size_a && ib<size_b){
        if(a[ia]==b[ib]){
            if(res.empty() || res.back()!=a[ia])
                res.push_back(a[ia]);
            ia++, ib++;
        }
        else if (a[ia]<b[ib])
            ia++;
        else
            ib++;
    }
    return res;
}
