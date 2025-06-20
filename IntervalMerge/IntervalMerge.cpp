class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& leftInterval, const std::vector<int>& rightInterval){ return leftInterval[0] < rightInterval[0]; });

        std::vector<std::vector<int>>::iterator itor = intervals.begin();
        if (itor == intervals.end()) return {};

        std::vector<std::vector<int>> mergedIntervals;
        std::vector<int> currentIntervalMerge = *itor++;
        for (; itor != intervals.end(); ++itor) {
            std::vector<int>& currentInterval = *itor;
            int begin = currentInterval[0], end = currentInterval[1];
            if (begin <= currentIntervalMerge[1]) {
                currentIntervalMerge[1] = std::max(currentIntervalMerge[1], end);
            } else {
                mergedIntervals.push_back(currentIntervalMerge);
                currentIntervalMerge = *itor;
            }
        }
        mergedIntervals.push_back(currentIntervalMerge);

        return mergedIntervals;
    }
};
