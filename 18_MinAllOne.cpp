/*
给定一个非负整数a（不超过106），是否存在整数b，使得a和b的乘积全为1。如果存在，返回最小的乘积的位数。如果不存在，返回-1。

样例：a=3，存在b=37，使得3*37=111，则函数应返回3（111的位数）。
*/

/*
这题是利用余数定理：  如果 x 是这个全为1的数， 那么应当有  x % a ==0 ,即有个b能满足 a * b ==x (全1）,关键是我们的这个x会很大，远远会超过int的表示范围，那么我们在枚举x  的时候就会超出范围，有什么办法不真正去枚举这个x 吗？ 可以的！

这就是余数定理，我们令 当前的 x % a== b ，如果b==0,那么x就是满足要求的数了，我们有记录它的位数，返回就好了；

如果 b!=0 呢？ 我们原本要枚举下一个 x' = x * 10 +1 对吧， 那么由  x = na +b , 那么 x' = (na +b ) * 10 + 1 = 10 n a + b * 10 +1 ，

那么 x' % a == (10 n a + b * 10 + 1 ) % a = (b*10+1 )% a， 是吧，所以我们枚举下一个x 其实就等价于枚举下一个 余数 b*10 +1 ；
*/

int findMinAllOne(int a) {
   if(a==0)
       return -1;
   int num = 1;
   int count = 1;
   int r = num%a;
   int t = 0;
   while(r && t < a){
       num = r*10+1;
       r = num%a;
       t++;
       count++;
   }
   if(r)
       return -1;
   return count;
}

int findMinAllOne(int a) {
    static const int M[] = {-1,1,-1,1,-1,-1,-1,1,-1,1};
    if (a<0 || M[a%10]==-1)
        return -1;
    if ( a==1 )
        return 1;
    int ans=1;
    for (int p=1; p; p%=a)
        p=10*p+1, ++ans;
    return ans;
}
