class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        stack<int> ans;
        int total = 0;
        int sign = 1;
        for(int i =0;i<n;i++){
            if(isdigit(s[i])){
                long long num = 0;
                while(i<n && isdigit(s[i])){
                    num = num*10 + s[i]-'0';
                    i++;
                }

                total += sign*num;
                i--;
            }
            else if(s[i]=='+'){
                sign = 1;
            }
            else if (s[i]=='-'){
                sign = -1;
            }
            else if( s[i]== '('){
                ans.push(total);
                ans.push(sign);
                total =0;
                sign = 1;
            }
            else if( s[i]==')'){
                total *= ans.top();
                ans.pop();

                total += ans.top();
                ans.pop();
            }
        }
        return total;
    }
};