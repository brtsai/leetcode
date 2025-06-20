class Solution {
public:
    int numberOfSpecialChars(string word) {
        std::bitset<26> seenUppers;
        std::bitset<26> seenLowers;

        for (string::iterator itor = word.begin(); itor != word.end(); ++itor) {
            char ch = *itor;
            if (islower(ch)) {
                short index = ch - 'a';
                seenLowers[index] = not seenUppers[index];
            } else {
                seenUppers[ch - 'A'] = true;
            }
        }

        int specialCharCount = 0;
        for (short index = 0; index < 26; ++index) {
            if (seenLowers[index] and seenUppers[index]) ++specialCharCount;
        }

        return specialCharCount;
    }
};
