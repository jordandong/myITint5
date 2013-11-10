/*
请将字符串str中的空格全部转换为"%20"，str有足够的空间可以存放转换后的结果。

提示：不要使用任何辅助空间。
*/

void escapeSpace(char *str) {
    if(!str)
        return;
    
    int size = strlen(str);
    int nspace = 0;
    int i = 0;
    while(*(str+i)!='\0'){
        if(*(str+i)==' ')
            nspace++;
        i++;
    }
    
    int size1 = size + 2*nspace;
    *(str + size1)='\0';
    i=size-1;
    while(i>=0){
        if(*(str+i)==' '){
            *(str+size1-3)='%';
            *(str+size1-2)='2';
            *(str+size1-1)='0';
            size1-=3;
        }else{
            *(str+size1-1)=(*(str+i));
            size1--;
        }
        i--;
    }
}
