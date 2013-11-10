/*
给定一个包含n个整数的数组，计算出它的下一个排列（既C++ STL中的next_permutation函数 http://www.cplusplus.com/reference/algorithm/next_permutation/）。

数组以引用的形式传入，请直接将下一个排列写回到该引用数组。

关于函数的返回值，如果存在下一个排列，返回true，否则返回false。
*/
bool next_permutation(vector<int> &arr) {
    int size = arr.size();
    if(size == 1 || size==0)
        return false;
    int s = size -1;
    while(s>0 && arr[s]<=arr[s-1])
        s--;
    if(!s)
        return false;
    
    int t1 = s-1;
    int t2 = s;
    int min_i = t2;
    int min_val = arr[t2];
    while(t2<size){
        if(arr[t2]>arr[t1]){
            if(arr[t2] < min_val && arr[t2] > arr[t1]){
                min_val = arr[t2];
                min_i = t2;
            }
        }
        t2++;
    }
    
    swap(arr[t1], arr[min_i]);
    sort(arr.begin()+s , arr.end());
    return true;
}
