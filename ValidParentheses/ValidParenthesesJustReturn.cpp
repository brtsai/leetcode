class Solution {
public:
    bool isValid(string s) {
        std::vector<char> openParenStack;

        for (std::string::iterator itor = s.begin(); itor != s.end(); ++itor) {
            char& paren = *itor;
            if (paren == '[' or paren == '(' or paren == '{') {
                openParenStack.insert(openParenStack.end(), paren);
                continue;
            }

            if (openParenStack.size() == 0) return false;

            char& openParen = openParenStack.back();
            openParenStack.pop_back();
            if (openParen == '(' and paren == ')') continue;
            if (openParen == '[' and paren == ']') continue;
            if (openParen == '{' and paren == '}') continue;
            
            return false;
        }

        if (openParenStack.size() > 0) return false;

        return true;
    }
};
