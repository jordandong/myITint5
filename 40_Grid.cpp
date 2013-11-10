/*
有一个n*m的棋盘网格，机器人最开始在左上角，机器人每一步只能往右或者往下移动。棋盘中有些格子是禁止机器人踏入的，该信息存放在二维数组blocked中，如果blocked[i][j]为true，那么机器人不能踏入格子(i,j)。请计算有多少条路径能让机器人从左上角移动到右下角。

样例：

n=2,m=3
blocked:
[000]
[100]

一共有2条路径：
(0,0)->(0,1)->(0,2)->(1,2)
(0,0)->(0,1)->(1,1)->(1,2)

所以函数应该返回2。
*/

int totalPath(vector<vector<bool> > &blocked) {
    int n = blocked.size();
    int m = blocked[0].size();
    int dp[n+1][m+1];
    
    for(int i=0; i<=n; i++)
        for(int j=0; j<=m; j++)
            dp[i][j] = 0;
    dp[0][1] = 1;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(blocked[i][j])
                dp[i+1][j+1] = 0;
            else
                dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j];
        }
    }
    return dp[n][m];
}
