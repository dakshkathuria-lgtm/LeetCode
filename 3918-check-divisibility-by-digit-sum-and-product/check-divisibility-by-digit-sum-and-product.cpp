class Solution {
public:
    int product(int x){
        int pro = 1;
        while(x>0){
            int ld = x%10;
            pro *= ld;
            x=x/10;
        }
        return pro;
    }

    int sum(int x){
        int sum = 0;
        while(x>0){
            int ld = x%10;
            sum+=ld;
            x=x/10;
        }
        return sum;
    }

    bool checkDivisibility(int n) {
        int final = sum(n) + product(n);
        if(n%final==0){
            return true;
        } 
        return false;
    }
};