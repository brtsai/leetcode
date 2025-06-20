class Solution {
public:
    void reverseString(vector<char>& s) {
        size_t sLength = s.size();
        for(size_t index = 0; index < sLength / 2; ++index) {
            size_t mirrorIndex = sLength - 1 - index;
            char original = s[index];
            s[index] = s[mirrorIndex];
            s[mirrorIndex] = original;
        }
    }
};
