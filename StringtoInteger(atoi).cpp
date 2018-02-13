class Solution {
public:
    int myAtoi(string str) {
        string num = "0123456789";
        string strNum = "";
        int i = 0;
        while(i < str.size() && str[i] == ' ')
            ++i;
        int neg = 1;
        
        if(str[i] == '-'){
            neg = -1;
            ++i;
        }else if(str[i] == '+'){
            ++i;
        }
        while(i < str.size() && str[i] <= '9' && str[i] >= '0'){
            strNum += str[i];
            ++i;
        }
        int result = 0;
        if(strNum.size() == 0)return 0;
        for(int i = 0; i < strNum.size(); ++i){
            int curNum = strNum[i] - '0';
            if(neg == 1){
                if((INT_MAX -curNum) / 10 >= result)
                    result = result*10 + curNum;
                else return INT_MAX;
            }else{
                if((INT_MIN + curNum) / 10 <= 0 - result)
                    result = result*10 + curNum;
                else return INT_MIN;
            }
        }
        result = result * neg;
        return result;
    }
};
