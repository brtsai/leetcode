class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        std::vector<int> toReturn;
        int i;
        
        i = 0;
        for(int x: nums)
        {
            std::pair<int, int> entry;
            entry.first = x;
            entry.second = i;
            map.insert(entry);
            ++i;
        }
        
        i=0;
        for(int x: nums){
            std::unordered_map<int, int>::iterator check;
            check = map.find(target - x);
            if(check != map.end() && check->second != i){
                toReturn.push_back(i);
                toReturn.push_back(check->second);
                return toReturn;
            }
            ++i;
        }
        
        
        
        return toReturn;
    }
};
