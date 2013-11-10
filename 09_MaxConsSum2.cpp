/*
有一个包含n个元素的首尾相连的环形数组arr，计算最大的子段和（允许空段）。

样例：数组[1, 3, -2, 6, -1]，最大子段和应该为9，对应的子段为[6, -1, 1, 3]。

*/

int maxConsSum2(const vector<int> &arr) {
    int size = arr.size();
    
    if(!size)
        return 0;
    
    int start = 0;
    int last = 0;
    int sum = 0;
    int max = arr[0];
    do{
        if(sum+arr[last]>0){
            sum+=arr[last];
            max = max>sum?max:sum;
            last = (last+1)%size;
            if(last==start){
                start++;
                sum=0;
                while(start<size&&arr[start]>=0)
                    start++;
                last=start;
            }
        }else{
            sum = 0;
            max = max>arr[last]?max:arr[last];
            last = (last+1)%size;            
            if(last<=start)
                break;
            else{
                start=last;
            }
        }
    }while(start<size);
    return max>0?max:0;
}
