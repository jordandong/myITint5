/*
有一个无限大的棋盘，棋盘上有一匹马，马移动的方式为日字型。即假设马当前的位置为(x,y)，那么下一步可以移动到(x+1,y+2)，(x+1,y-2)，(x-1,y+2)，(x-1,y-2)，(x+2,y+1)，(x+2,y-1)，(x-2,y+1)或者(x-2,y-1)这8个位置。

问马是否能从坐标(x,y)按照上述移动规则移动到坐标(x2,y2)。
*/

/*
c1 *p + c2 *q + c3 *q + c4 *p = x2 - x,
c1 *q + c2 *p - c3 *p - c4 *q = y2 - y.
未知数是c1, c2, c3, c4.
需要用到的数学结论就是下面的: ax+by = c 有整数解(x,y)当且仅当a,b的最大公约数整除c.
*/
#include<cmath>

int gcd(int a, int b){
    return b?gcd(b, a%b):a;
}

bool canJump(int x, int y, int x2, int y2) {
    int p =1, q =2;
    int g1 = gcd(p, q);
    int x1 = abs(x2-x), y1 = abs(y2-y);
    if(x1 % g1 || y1 % g1)
        return false;
    x1 = x1/g1;
    y1 = y1/g1;
    int p1 = p/g1;
    int q1 = q/g1;
    int g2 = gcd(p1*p1-q1*q1, 2);
    if((x1-y1) % g2)
        return false;
    return true;
}
