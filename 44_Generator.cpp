/*
生成所有包含n对括号的合法的括号序列。合法的括号序列指'('和')'正确匹配。

样例：

n=3
包含3对括号的合法的括号序列有：
((()))
(()())
(())()
()(())
()()()

因此函数应返回数组（数组内元素顺序无所谓）：
["((()))",
"(()())",
"(())()",
"()(())",
"()()()"]
*/

void gen(int l, int r, string s, vector<string> &rs){
    
    if(l==0&&r==0)
        rs.push_back(s);
    
    if(l>0)
        gen(l-1, r, s+'(', rs);
    if(r>l)
        gen(l, r-1, s+')', rs);
}

vector<string> generate(int n) {
    vector<string> rs;
    gen(n, n , "", rs);
    return rs;
}
