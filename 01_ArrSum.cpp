/*
有一个包含n个整数的数组arr，请计算出数组中所有元素之和。（假设中间结果以及最终结果都不会超出32位有符号整型的范围）。
*/

//返回arr中所有元素之和
//不需要main函数!
int arrSum(const vector<int> &arr) {
    int size = arr.size();
    int sum = 0;
    for(int i=0; i<size; i++)
        sum += arr[i];
    return sum;
}
