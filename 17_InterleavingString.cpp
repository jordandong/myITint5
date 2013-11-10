/*
如果字符串str3能够由str1和str2中的字符按顺序交替形成，那么称str3为str1和str2的交替字符串。例如str1="abc"，str2="def"，那么"adbecf", "abcdef", "abdecf", "abcdef", "adefbc"等等都为str1和str2的交替字符串。更形式化的，str3的生成算法如下：

str3=""
while str1不为空 or str2不为空:
  把str1或str2的首字符加入到str3,并从str1或str2中删除相应的字符
end
给定str1, str2,和str3，判断str3是否为str1和str2的交替字符串。

*/

/*
bool isInterleaving(string &str1, string &str2, string &str3) {
    int n1 = str1.size();
    int n2 = str2.size();
    int n3 = str3.size();
    if(n1+n2!=n3)
        return false;
    
    int i1=0, i2=0, dup =0;
    for(int i3=0;i3<n3;){
        if(i1==n1&&dup){
            i2-=dup;
            dup=0;
            continue;
        }
        if(i2==n2&&dup){
            i1-=dup;
            dup=0;
            continue;
        }
        
        if(i1<n1 && i2<n2 && str3.at(i3)==str1.at(i1) && str3.at(i3)==str2.at(i2)){
            i1++;
            i2++;
            i3++;
            dup++;
            continue;
        }
            
        if(i1<n1 && str3.at(i3)==str1.at(i1)){
            if(dup){
                if(str1.at(i1)==str1.at(i1-1))
                    i1-=dup;
                else
                    i2-=dup;
                dup=0;
            }
            i1++;
            i3++;    
            continue;
        }
        if(i2<n2 && str3.at(i3)==str2.at(i2)){
            if(dup){
                if(str2.at(i2)==str2.at(i2-1))
                    i2-=dup;
                else
                    i1-=dup;
                dup=0;
            }
            i2++;
            i3++;    
            continue;
        }
        if(i3>0 && str3.at(i3)==str3.at(i3-1) && dup){
            i3++;
            dup--;
            continue;
        }
            
        return false;
    }
    return true;
}
*/


bool isInterleaving(string &str1, string &str2, string &str3) {
    int n1=str1.size();
    int n2=str2.size();
    int n3=str3.size();
    if(n1 + n2 != n3)
        return false;
	vector<vector<int> > match(2,vector<int>(n2+1,0));
	match[0][0]=1;
	for(int i=1;i<=n2;i++)
		match[0][i]=match[0][i-1]&&str2[i-1]==str3[i-1]?1:0;
	for(int k=1;k<=n1;k++){
		int i=k&1,i_1=(k+1)&1;
		match[i][0]=match[i_1][0]&&str1[k-1]==str3[k-1]?1:0;
		for(int j=1;j<=n2;j++){
			match[i][j]=(match[i_1][j]&&str1[k-1]==str3[k+j-1])
				||(match[i][j-1]&&str2[j-1]==str3[k+j-1])?1:0;
		}
	}
	return match[n1&1][n2]==1;
}
