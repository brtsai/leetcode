class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        std::unordered_map<char, int> charToIndexMap;
        int longestLength = 0;

        int right = 0;
        for (; right < s.size(); ++right) {
            char currChar = s[right];
            std::unordered_map<char, int>::iterator searchResult = charToIndexMap.find(currChar);
            if (searchResult != nullptr and searchResult->second >= left) {
                longestLength = std::max(longestLength, right - left);
                left = charToIndexMap[currChar] + 1;
            }
            charToIndexMap[currChar] = right;
        }

        return std::max(longestLength, right - left);
    }
};
