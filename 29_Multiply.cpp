/*
给定两个字符串表示的整数a和b，计算它们的乘积a*b，结果也用字符串表示。

注意：a和b有可能是负数。对于0，只有一种合法的表示"0"，"-0"是不合法的。
*/

//返回a*b的结果
string multiply(const string& a, const string& b) {
    
    int n1=a.size();
    int n2=b.size();
    bool sign = false;
    if(a[0]=='-'){
        sign=!sign;
    }
    if(b[0]=='-')
        sign=!sign;
    
    int n3=n1+n2;
    int num[n3];
    memset(num, 0, sizeof(int)*(n3));
    for(int i=n1-1; i>=0&&a[i]!='-'; i--){
        int carry = 0;
        int j;
        int t;
        for(j=n2-1; j>=0&&b[j]!='-';j--){
            t = carry + num[i+j+1] + (a[i]-'0') * (b[j]-'0');
            num[i+j+1] = t % 10;
            carry = t / 10;
        }
        num[i+j+1] = carry;
    }
    
    string res="";
    int i = 0;
    while(i<n3-1 && num[i]==0)
        i++;
    if(sign && num[i]!=0)
        res.push_back('-');
    while (i<n3)
        res.push_back('0' + num[i++]);
    return res;
}
