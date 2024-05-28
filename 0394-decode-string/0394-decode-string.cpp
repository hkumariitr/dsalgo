#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<char> stack;
        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ']') {
                stack.push(s[i]);
            } else {
                // Retrieve the substring inside the brackets
                string substr = "";
                while (!stack.empty() && stack.top() != '[') {
                    substr = stack.top() + substr;
                    stack.pop();
                }
                // Remove the '[' from the stack
                if (!stack.empty() && stack.top() == '[') {
                    stack.pop();
                }
                
                // Retrieve the repeat count k
                string k_str = "";
                while (!stack.empty() && isdigit(stack.top())) {
                    k_str = stack.top() + k_str;
                    stack.pop();
                }
                int k = stoi(k_str);
                
                // Repeat the substring k times and push back to the stack
                string repeatedStr = "";
                for (int j = 0; j < k; ++j) {
                    repeatedStr += substr;
                }
                for (char ch : repeatedStr) {
                    stack.push(ch);
                }
            }
        }
        
        // Build the final result from the stack
        string result = "";
        while (!stack.empty()) {
            result = stack.top() + result;
            stack.pop();
        }
        return result;
    }
};
