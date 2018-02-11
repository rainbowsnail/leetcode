class Solution {
public:
    int reverse(int x) {
        int tmp = x;
        int neg = 1;
        if(tmp < 0){tmp = 0 - tmp; neg = -1;}
        long long result = 0;
        while(tmp != 0){
            if (result > (INT_MAX - tmp % 10) / 10){
                result = 0;
                break;
            }
            result = result*10 + tmp%10;
            tmp /= 10;
        }
        result = result * neg;
        return result;
    }
};
