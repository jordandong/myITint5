/*
数组nums中有n个非负整数（整数用字符串表示），将它们以一定的顺序拼接，得到最大的整数。

样例：

n=4
nums: ["54", "546", "548", "60"]

可以拼接得到的最大整数为"6054854654"，因此函数应该返回"6054854654"。
*/

class comp{
public:
    bool operator()(const string &a, const string &b){
        return a+b > b+a;
    }    
};

string biggestNum(vector<string> &nums) {
    if(nums.empty())
        return "";
    
    if(nums.size()==1)
        return nums[0];
    
    sort(nums.begin(), nums.end(), comp());
    string ret;
    for(int i=0; i<nums.size(); i++)
        ret+=nums[i];
    return ret;
}
