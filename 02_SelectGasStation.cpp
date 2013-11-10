/*
有一个环形公路上有n个加油站，第i个加油站的油量为ai。假设有一辆邮箱体积无穷大的汽车，初始邮箱是空的，汽车从加油站i行驶到加油站i+1需耗油g[i]。

问是否能够选出某个加油站作为起点，使汽车能够绕环形公路行驶一圈返回到该加油站。

实现函数int selectGasStation(int a[], int g[], int n)，如果存在满足条件的加油站，返回该加油站的序号(0-based)。否则返回-1。

提示：n可能达到10^6，O(n^2)的枚举算法会超出时间限制。
*/


#include <vector>
using namespace std;

int selectGasStation(const vector<int> &a, const vector<int> &g) {
    int size = a.size();
    int start = 0;
    do{
        int left = 0;
        int k = start;
        int end = start;
        int flag = 0;
        do{
            if(0 <= left + a[k]- g[k]){
                left = left + a[k]-g[k];
                k=(k+1)%size;
                flag = 1;
            }else{
                start = k>=start ? k+1:size;
                break;
            }
        }while(k!=end);
        if((k==end) && flag)
            return start;
    }while(start<size);
    return -1;    
}
