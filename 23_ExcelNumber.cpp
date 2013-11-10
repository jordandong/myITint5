/*
Excel中的行列数用A~Z 26个字母表示，A, B, C, D, …, Z, AA, AB, …, AZ, BA, BB, … 分别表示10进制数1, 2, 3, 4, …, 26, 27, 28, …, 52, 53, 54…。

请实现2个函数decToExcel和excelToDec，将10进制数转换为Excel数，以及将Excel数转换为10进制数。
*/

//将十进制数转换为excel数
string decToExcel(int decNum) {
    if(!decNum)
        return "";
    char t = 'A'+((decNum-1)%26);
    return decToExcel((decNum-1)/26) + t;
}


//将excel数转换为十进制数
int excelToDec(string excelNum) {
    string &s = excelNum;
    int len = s.length();
    int sum = 0;
    for(int i=0; i<len; i++){
        sum*=26;
        sum+=((s.at(i)-'A')+1);
    }
    return sum;
    
}
