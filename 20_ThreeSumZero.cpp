/*
有一个长度为n的整型数组arr，从中选出3个数a,b,c，使得a+b+c=0，找出所有满足条件的三元组(a,b,c)。重复的三元组只算一次。

样例：数组[2, 1, -3, -3, 0, -1]，满足条件的三元组有2个：(2, 1, -3)和(1, 0, -1)。

提示：本题存在空间复杂度O(1)的算法(不使用任何辅助空间)，没必要利用set等数据结构消除重复的三元组。
*/

typedef tuple<int, int, int> ABC; //存放a,b,c三元组
//返回所有满足条件的(a,b,c)三元组
vector<ABC> threeSumZero(vector<int> &arr) {
    vector<ABC> result;
    int size = arr.size();
    if(size<3)
        return result;
    
    sort(arr.begin(), arr.end());
    for(int i=0;i<size-2;i++){
        if(arr[i]>0)
            return result;
        if((i!=0) && (arr[i]==arr[i-1]))
            continue;
        
        int j=i+1;
        int k=size-1;
        while(j<k){
            if((j!=i+1) && (arr[j]==arr[j-1])){
                j++;
                continue;
            }
            if((k!=size-1) && (arr[k]==arr[k+1])){
                    k--;
                    continue;
            }
            if(arr[j]+arr[k] + arr[i]== 0)  
                result.push_back(make_tuple(arr[i], arr[j++], arr[k--]));
            else
                arr[j]+arr[k] + arr[i]<0?j++:k--;
        }//end while
    }//end for
    return result;
}
