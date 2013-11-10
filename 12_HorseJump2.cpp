/*
有一个无限大的棋盘，棋盘上有一匹马，马可以从长宽分别为p和q的矩形一个角移动到对角。即假设马当前的位置为(x,y)，那么下一步可以移动到(x+p,y+q)，(x+p,y-q)，(x-p,y+q)，(x-p,y-q)，(x+p,y+q)，(x+p,y-q)，(x-p,y+q)或者(x-p,y-q)这8个位置。

问马是否能从坐标(x,y)按照上述移动规则移动到坐标(x2,y2)。
*/

int gcd(int a, int b){
    return b? gcd(b, a%b) : a;
}

bool canJump(int p, int q, int x, int y, int x2, int y2) {
    if(p==0 && q==0)
        return (x==x2)&&(y==y2);
    int g1 = gcd(p, q);
    int x1 = abs(x2-x), y1 = abs(y2-y);

    if(x1 % g1 || y1 %g1)
        return false;
    x1 = x1/g1;
    y1 = y1/g1;
    int p1 = p/g1;
    int q1 = q/g1;
    //int g2 = gcd(p1*p1-q1*q1, 2);
    int g2 = gcd(p1-q1, p1+q1);
    if((x1-y1) % g2)
        return false;
    return true;
}
/*
bool canJump(int p, int q, int x, int y, int x2, int y2) {
    if(p==0 && q==0)
        return (x==x2)&&(y==y2);
    int x1 = x2 - x, y1 = y2 - y;
    int g1 = gcd(p, q);
    if( x1 % g1 || y1 % g1)
        return false;
    p = p/g1;
    q = q/g1;
    x1 = x1/g1;
    y1 = y1/g1;
    if((p-q)%2 )
        return true;
    else
        return (x1-y1)%2 == 0;
}
*/
