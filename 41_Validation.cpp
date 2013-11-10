/*
验证字符串expr是否为合法的算术表达式。expr中只包含：

1.数字'0'-'9'。
2.二元运算符'+', '-'。
3.括号'(', ')'。

样例：

expr="1"  合法的表达式，返回true
expr="10+(2-(31+(4)))"  合法的表达式，返回true
expr="-1"  不合法的表达式，返回false
expr="1+"  不合法的表达式，返回false
提示：此题可使用表达式求值中类似的递归算法。
*/

bool validate(const string& expr) {
    
    int len =expr.length();
    int sum = 0;
    int i = 0;
    
    if(i==0 && (expr[i]=='+' || expr[i]=='-' || expr[i]==')'))
        return false;
    
    while(i<len){
        if(expr[i]=='('){
            i++;
            sum++;
            if(i==len || expr[i]==')' || expr[i]=='+' || expr[i]=='-')
                return false;
            continue;
        }
        
        if(expr[i]==')'){
            i++;
            sum--;
            if(sum<0)
                return false;
            if(i<len && (expr[i]=='(' || isdigit(expr[i])))
                return false;
            continue;
        }
               
        if(expr[i]=='+' || expr[i]=='-'){
            i++;
            if(i==len || expr[i]==')' || expr[i]=='+' || expr[i]=='-')
                return false;
            continue;
        }
        
        if(isdigit(expr[i])){
            int begin = i++;
            while(i<len && isdigit(expr[i]) && expr[begin]!='0')
                i++;
            if(i<len && (expr[i]=='(' || isdigit(expr[i])))
                  return false;
            continue;
        }
    }      
    return sum==0; 
}
