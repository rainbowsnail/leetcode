class Solution {
public:
    bool isPalindrome(int x) {
        if(x == INT_MIN) return false;
        if(x < 0) return false;
        int len = 1;
        int tmp = 10;
        while(x/tmp != 0){
            ++len;
            if(tmp > INT_MAX/10) break;
            tmp *= 10; 
        }
        int left = len - 1,right = 0;
        while(true){
            if(left <= right) return true;
            if(int(x/pow(10,left))%10 != int(x/pow(10,right))%10) return false;
            left--;
            right++;
        }
        return true;
    }
};
