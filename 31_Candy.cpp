/*
有n个小朋友站成一排（编号从0到n-1)，每个小朋友有一个rating值，存放在ratings数组中。老师需要给他们分配糖果，每个小朋友至少需要一颗糖果，对于任意相邻的两个小朋友i和i+1，rating值大的必须比rating值小的分配的糖果多（rating相同的没必要分配一样多的糖果）。

请计算最少需要多少颗糖果，才能完成上述分配。

提示：本题存在O(n)的算法。
*/

//返回最少需要的糖果数
long long minimalCandies(vector<int> &ratings) {
    int size = ratings.size();
    vector< long long > assign (size, 1);
    
    for(int i = 1; i<size; i++){
        if(ratings[i]>ratings[i-1])
            assign[i] = assign[i-1]+1;
    }
    
    
    for(int i = size-2; i>=0; i--){
        if(ratings[i]>ratings[i+1]){
            if(assign[i] <= assign[i+1])
                assign[i] = assign[i+1]+1;
        }
    }
    
    long long sum = 0;
    for(int i = 0; i<size; i++)
        sum+=assign[i];
    return sum;
}
