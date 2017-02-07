class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combos;
        queue<int> convertedDigits;
        
        for (char c : digits) {
            fprintf(stdout, "%c\n", c);
            convertedDigits.push(c - '0');
        }
        
        return letterCombinationsRecursive(combos, convertedDigits);
    }
    
    vector<string> letterCombinationsRecursive (vector<string> combos, queue<int> digits) {
        if (digits.size() == 0){
            return combos;
        }
        
        vector<string> newCombos;
        int digit = digits.front();
        vector<char> letters;
        
        digits.pop();
        
        if(combos.size()==0){
            for (char c : digitToLetterSet(digit)) {
                string str;
                str += c;
                newCombos.push_back(str);
            }
            return letterCombinationsRecursive(newCombos, digits);
        }
        
        newCombos = setCrossProduct (combos, digitToLetterSet(digit));

        return letterCombinationsRecursive(newCombos, digits);
        
    }
    
    vector<string> setCrossProduct (vector<string> combos, vector<char> letters) {
        vector<string> toReturn;
        
        for (string str : combos) {
            for (char c : letters) {
                toReturn.push_back(str + c);
            }
        }
        
        return toReturn;
    }
    
    vector<char> digitToLetterSet(int digit) {
        vector<char> letters;
        
        switch (digit){
            case 1:
            break;
                    
            case 2:
            letters = {'a', 'b', 'c'};
            break;
                    
            case 3:
            letters = {'d', 'e', 'f'};
            break;
                    
            case 4:
            letters = {'g', 'h', 'i'};
            break;
                    
            case 5:
            letters = {'j', 'k', 'l'};
            break;
                    
            case 6:
            letters = {'m', 'n', 'o'};
            break;
                    
            case 7:
            letters = {'p', 'q', 'r', 's'};
            break;
                    
            case 8:
            letters = {'t', 'u', 'v'};
            break;
                    
            case 9:
            letters = {'w', 'x', 'y', 'z'};
            break;
                    
            default:
            fprintf(stderr, "Error: %i not a valid keybad number.\n", digit);
            break;
        }
        
        return letters;
    }
};
