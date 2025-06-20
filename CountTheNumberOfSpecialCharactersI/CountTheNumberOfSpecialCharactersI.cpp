class Solution {
public:
    int numberOfSpecialChars(string word) {
        std::set<char> charSet = std::set<char>(word.begin(), word.end());
        int specialNumCount = 0;
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            if (charSet.contains(ch) and charSet.contains(toupper(ch))) ++specialNumCount;
        }

        return specialNumCount;
    }
};
