class Solution {
public:
    static bool heapCompare(const std::pair<int, int>& left, const std::pair<int, int>& right) {
        return left.second < right.second;
    }
    
    std::vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> numCount;
        for(std::vector<int>::iterator itor = nums.begin(); itor != nums.end(); ++itor) {
            int& num = *itor;
            if (numCount.find(num) == nullptr) {
                numCount[num] = 0;
            }
            ++numCount[num];
        }

        auto entryHeap = std::vector<std::pair<int, int>>(numCount.begin(), numCount.end());
        std::make_heap(entryHeap.begin(), entryHeap.end(), Solution::heapCompare);

        std::vector<int> kFrequent;
        for (int i = 0; i < k; ++i) {
            kFrequent.push_back(entryHeap[0].first);
            std::pop_heap(entryHeap.begin(), entryHeap.end(), Solution::heapCompare);
            entryHeap.pop_back();
        }

        return kFrequent;        
    }
};
