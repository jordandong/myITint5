/*
有一个n*m的2维矩阵matrix，矩阵每一行，每一列都是有序的（升序）。判断矩阵中是否存在元素target。

提示：时间复杂度O(n+m)，空间复杂度O(1)。
*/

bool exists(vector<vector<int> > &matrix, int target) {
    int row = matrix.size();
    if(!row)
        return false;
    int col = matrix[0].size();
    if(!col)
        return false;
    
    int i=0;
    int j=col-1;
    while(i<row && j>=0){
        if(matrix[i][j]==target)
            return true;
        else if(matrix[i][j] < target)
            i++;
        else
            j--;
    }
    return false;
    
}
