/*
给定一个表达式字符串，其中只包含非负整数，加法，减法以及乘法符号，例如7+3*4*5+2+4-3-1。请写程序计算该表达式的值。

提示：可以尝试使用递归算法，程序将非常简洁易写，很适用于面试场合。
*/

//返回表达式expr的值
int getNum(const string &s, int &i) {
    int n=0;
    for(; i<s.size(); ++i){
        if(s[i]<'0'||s[i]>'9')
            break;
        n = 10*n+s[i]-'0';
    }
    return n;
}

int helper(const string &s, int m, int i) {
    int n = getNum(s, i);
    if (i>=s.size())
        return m*n;
    if (s[i]=='*')
        return helper(s, m*n, i+1);
    else
        return m*n+helper(s, s[i]=='+'?1:-1, i+1);
}

int evaluate(const string& expr) {
    return helper(expr, 1, 0);
}

/*
int getNum(const string &s, int &i) {
    int n=0;
    for(; i<s.size(); ++i){
        if(s[i]<'0'||s[i]>'9')
            break;
        n = 10*n+s[i]-'0';
    }
    return n;
}

int helper(const string &s, int prev, int i) {
    if (i >=s.size())
        return prev;
    int op = s[i++];
    int n = getNum(s, i);

    switch(op) {
        case '+':
            return prev + helper(s, n, i);
        case '-':
            return prev + helper(s, -n, i);
        case '*':
            return helper(s, prev*n, i);
    }
    return helper(s, prev/n, i);
}

int evaluate(const string &expr) {
    int i = 0;
    int n = getNum(expr, i);
    return helper(expr, n, i);
}
*/
