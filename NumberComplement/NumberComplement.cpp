class Solution {
public:
    int findComplement(int num) {
        int toReturn = 0;
        std::vector<int> vec;
        while(num != 0) {
            vec.push_back(num%2);
            num = num >> 1;
        }
        
        for(;vec.size() > 0; vec.pop_back()) {
            toReturn *= 2;
            toReturn += 1 - vec.back();
        }
        return toReturn;
    }
};
