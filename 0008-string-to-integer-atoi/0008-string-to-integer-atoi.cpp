class Solution {
public:
    int myAtoi(string s) {
        if(s.empty()){
            return 0;
        }
        int i =0;
        int zero = 0;
        bool sign = 1;
        while(s[i]== ' '){
            i++;
        }
        if(i == s.size()){ return 0;}
        while(s[i]== 0){
            i++;
            zero++;
        }
        
        if(s[i]=='+' && zero ==0){
            sign = 1;
            i++;
        }else if(s[i]=='-'&& zero ==0){
            sign = 0;
            i++;
        }
        int start = i;
        while(s[i]>='0' && s[i]<='9'){
            i++;
        }
        int end = i;
        string digit = s.substr(start,end-start);
        cout<<digit;
        if (!digit.empty()) {
            try {
                long long num = std::stoll(digit); // Use long long to handle overflow

                if (!sign) {
                    num = -num;
                }

                // Clamping to the 32-bit signed integer range
                if (num > INT_MAX) {
                    return INT_MAX;
                } else if (num < INT_MIN) {
                    return INT_MIN;
                } else {
                    return static_cast<int>(num);
                }
            } catch (std::out_of_range& e) {
                // If std::stoll throws an out_of_range exception, it means the number is out of long long range
                return sign ? INT_MAX : INT_MIN;
            }
        } else {
            return 0;
        }
        
    }
};