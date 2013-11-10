/*
写程序判断一个9*9的数字盘面是否为合法的数独（查看定义）。

9*9的盘面按照Row-major order表示为一个81维的一维数组。

提示：请直接在一维数组上操作，不要先将一维数组拷贝到9*9的二维数组。

*/

int isValidSudoku(int arr[]) {
	vector<int> row(9,0);
	vector<int> col(9,0);	
	vector<int> grid(9,0);
	for(int i=0;i<81;i++){
		int x=i/9,y=i%9;
		int n=arr[i];
        if(n<1||n> 9)
            return 0;
		if(row[x] & (1<<n)) 
			return 0;
		else
			row[x]|=(1<<n);
		if( col[y] & (1<<n) ) 
			return 0;
		else
			col[y]|=(1<<n);
        
		int kgrid=(x/3)*3+y/3;
		if(grid[kgrid] & (1<<n)) 
			return 0;
		else
			grid[kgrid]|=(1<<n);
	}
	return 1;
}
