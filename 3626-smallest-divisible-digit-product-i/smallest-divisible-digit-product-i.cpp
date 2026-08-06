class Solution {
public:
    int product(int x){
        int pro = 1;
        int y = x;
        while(y>0){
            pro = (y%10) * pro;
            y = y/10;
        }
        return pro;
    }

    int smallestNumber(int n, int t) {
        while(product(n)%t!=0){
            n = n+1;
        }
        return n;
    }
};