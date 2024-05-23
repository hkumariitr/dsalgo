class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        vector<int> result(len1 + len2, 0);

        // Reverse the strings to make the calculation easier
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        // Perform multiplication
        for (int i = 0; i < len1; ++i) {
            for (int j = 0; j < len2; ++j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = result[i + j] + mul;
                result[i + j] = sum % 10;
                result[i + j + 1] += sum / 10;
            }
        }

        // Remove leading zeros
        while (result.size() > 1 && result.back() == 0) {
            result.pop_back();
        }

        // Convert result vector back to string
        string resultStr;
        for (int i = result.size() - 1; i >= 0; --i) {
            resultStr.push_back(result[i] + '0');
        }

        return resultStr;
    }
};
