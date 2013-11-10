/*
有一个包含n个元素的数组arr，计算最大的子段和（允许空段），即max(0,max(sum_i_j(arr_k)) 0<=i<=k<j<n。
*/

int maxConsSum(const vector<int> &arr) {
    int size = arr.size();
    int max = 0;
    int subTotal = 0;
    for(int i=0; i<size; i++){
        if(subTotal+arr[i]<0){
            subTotal = 0;
        }else{
            subTotal+=arr[i];
            max=subTotal>max?subTotal:max;
        }
    }
    return max;
}
