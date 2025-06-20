class Solution {
public:
    int numberOfSpecialChars(string word) {
        std::set<char> seenChars;
        std::set<char> seenUppers;
        std::set<char> notSpecialChar;
        for (size_t index = 0; index < word.size(); ++index) {
            char ch = word[index];
            seenChars.insert(ch);
            if (isupper(ch)) {
                seenUppers.insert(tolower(ch));
            } else if (seenUppers.contains(ch)) {
                notSpecialChar.insert(ch);
            }
        }

        int specialCharCount = 0;
        for (std::set<char>::iterator itor = seenUppers.begin(); itor != seenUppers.end(); ++itor) {
            char ch = tolower(*itor);
            if (not seenChars.contains(ch)) continue;
            if (notSpecialChar.contains(ch)) continue;
            ++specialCharCount;
        }
        return specialCharCount;
    }
};
