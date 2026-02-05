
class Solution {
public:
    int pivotInteger(int n) {
        const int y = (n*n+n)/2;
        const int x = sqrt(y);
        if(x*x==y){
            return x;
        }else{
            return -1;
        }
    }
};