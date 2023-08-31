#include <iostream>
#include <vector>
#include <algorithm>

bool isPalindrome(const std::string& str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end])
            return false;
        start++;
        end--;
    }
    return true;
}

int minCutPalindromePartition(const std::string& str) {
    int n = str.length();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    std::vector<int> cuts(n, 0);

    for (int end = 0; end < n; ++end) {
        int minCuts = end;
        for (int start = 0; start <= end; ++start) {
            if (str[start] == str[end] && (end - start <= 1 || dp[start + 1][end - 1])) {
                dp[start][end] = 1;
                minCuts = (start == 0) ? 0 : std::min(minCuts, cuts[start - 1] + 1);
            }
        }
        cuts[end] = minCuts;
    }

    return cuts[n - 1];
}

int main() {
    std::string str = "ababbbabbababa";
    int result = minCutPalindromePartition(str);
    std::cout << "Minimum cuts needed: " << result << std::endl;
    return 0;
}
