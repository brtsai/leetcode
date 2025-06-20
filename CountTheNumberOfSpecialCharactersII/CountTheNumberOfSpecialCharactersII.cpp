class Solution {
public:
    int numberOfSpecialChars(string word) {
        std::unordered_map<char, size_t> charMap;
        for (size_t index = 0; index < word.size(); ++index) {
            char ch = word[index];
            if (isupper(ch) and charMap.contains(ch)) continue;
            charMap[ch] = index;
        }

        int specialCharCount = 0;
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            if (not charMap.contains(ch)) continue;
            if (not charMap.contains(toupper(ch))) continue;
            if (charMap[ch] > charMap[toupper(ch)]) continue;

            specialCharCount += 1;
        }

        return specialCharCount;
    }
};
