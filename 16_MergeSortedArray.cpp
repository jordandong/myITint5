/*
有2个长度为n和m的有序的整型数组arr1和arr2，请将他们合并为一个n+m的有序数组。

注意：数组arr1包含足够的空间存放下n+m个元素，请直接将结果合并到数组arr1中。

提示：不要使用任何辅助数组，辅助空间。

样例：

n=3
m=2
arr1: [1,4,8,x,x]
arr2: [-1,5]
算法运行后arr1应该为[-1,1,4,5,8]
*/

void mergeSortedArray(int arr1[], int arr2[], int n, int m) {
    int size = m + n;
    for(int i=size-1, a1=n-1, a2=m-1; i>=0; i--){
        if(a1<0){
            arr1[i] = arr2[a2--];
            continue;
        }
        if(a2<0)
            break;
        
        if(arr1[a1]>=arr2[a2]){
            arr1[i] = arr1[a1--];
        }else{
            arr1[i] = arr2[a2--];
        }
    }
}
