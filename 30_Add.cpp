/*
给定两个字符串表示的非负整数a和b，计算它们的和a+b，结果也用字符串表示。
*/

//返回a+b的结果


string add(const string& a, const string& b) {
    int la = a.length()-1;
    int lb = b.length()-1;
    string s = "";
    int carry = 0;
    while(la>=0||lb>=0){
        if(la>=0&&lb>=0){
            int sum = (a.at(la)-'0')+(b.at(lb)-'0')+carry;
            carry = sum/10;
            char t= '0'+ sum%10;
            s = (t + s);
            la--;
            lb--;
        }
        else if(la<0&&lb>=0){
            int sum = (b.at(lb)-'0') + carry;
            carry = sum/10;
            char t ='0' + sum%10;
            s = (t + s);
            lb--;
        }else if(la>=0&&lb<0){
            int sum = (a.at(la)-'0') + carry;
            carry = sum/10;
            char t ='0' + sum%10;
            s = (t + s);
            la--;
        }
    }
    return carry?('1'+s):s;
}

/*
//exceed memory limits
string addSub(string a, string b, int carry){
    int la = a.size();
    int lb = b.size();
    if(la>0&&lb>0){
        int sum = (a.at(la-1)-'0') + (b.at(lb-1)-'0')+carry;
        carry = sum/10;
        char t= '0'+ sum%10;
        return addSub(a.substr(0,la-1), b.substr(0, lb-1), carry)+ t;
    }
    else if(la==0&&lb!=0){
        int sum = (b.at(lb-1)-'0') + carry;
        carry = sum/10;
        char t ='0' + sum%10;
        if(carry)
            return addSub("", b.substr(0, lb-1), carry)+ t;
        else
            return b.substr(0, lb-1) + t;
             
    }
    else if(la!=0&&lb==0){
        int sum = (a.at(la-1)-'0') + carry;
        carry = sum/10;
        char t ='0' + sum%10;
        if(carry)
            return addSub(a.substr(0, la-1), "" , carry)+ t;
        else
            return a.substr(0, la-1) + t;
    }
    else{
        return carry?"1":"";
    } 
}


string add(const string& a, const string& b) {
    return addSub(a, b, 0);
}
*/
