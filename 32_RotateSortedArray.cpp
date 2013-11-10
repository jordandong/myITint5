/*
有一个长度为n的数组arr，它是将一个有序数组在某个位置前后翻转得到的。例如有序数组[1, 2, 3, 4]，在第3个位置前后翻转得到数组[3, 4, 1, 2]。请在数组arr中搜索目标元素target，返回目标元素的下标（0-based, 如果没有找到，返回-1）。数组arr中不包含重复元素。

样例：

arr: [3, 4, 1, 2]
当target=4时，返回1。
当target=5时，返回-1。
提示：1. 使用O(logn)的算法；2. 如果数组中包含重复元素呢？

*/


int search(vector<int> &arr, int target) {
    
    int len = arr.size();
    if(len <= 0)
        return -1;

    int l = 0, h = len - 1;
    while(l <= h){
        int mid = (h + l)/2;
        if(arr[mid] == target) {
            return mid;
        }else if(arr[l] <= arr[mid]) {
            if(target < arr[mid] && target >= arr[l]) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        } else if(arr[mid] < arr[h]){
            if(target > arr[mid] && target <= arr[h]) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        } 
    }

    return -1;
}
