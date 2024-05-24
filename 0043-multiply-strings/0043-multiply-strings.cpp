class Solution {
public:
    string multiply(string num1, string num2) {
        // Check if either input is "0", if yes, then result is "0"
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        // Initialize the sizes of the input numbers
        int length1 = num1.size(), length2 = num2.size();

        // Create a vector to store the multiplication result
        vector<int> result(length1 + length2, 0);

        // Multiply each digit of num1 with each digit of num2
        for (int i = length1 - 1; i >= 0; --i) {
            int digit1 = num1[i] - '0'; // Convert char to integer
            for (int j = length2 - 1; j >= 0; --j) {
                int digit2 = num2[j] - '0'; // Convert char to integer
                // Add to the corresponding position in the result vector
                result[i + j + 1] += digit1 * digit2;
            }
        }

        // Handle carrying over the value for digits greater than 9
        for (int i = result.size() - 1; i > 0; --i) {
            result[i - 1] += result[i] / 10; // Carry over
            result[i] %= 10; // Remainder stays at current position
        }

        // Skip any leading zeros in the result vector
        int startIndex = result[0] == 0 ? 1 : 0;

        // Convert the result vector to a string
        string resultStr;
        for (int i = startIndex; i < result.size(); ++i) {
            resultStr += '0' + result[i]; // Convert integer to char and append to resultStr
        }

        // Return the final product as a string
        return resultStr;
    }
};