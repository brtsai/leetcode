class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t total = nums1.size() + nums2.size();
        size_t half = (total + 1) / 2;
        bool isEven = total % 2 == 0;

        if (nums2.size() < nums1.size()) {
            std::swap(nums1, nums2);
        }

        size_t left = 0;
        size_t right = nums1.size();
        while (true) {
            size_t aMid = (left + right) / 2;
            size_t bMid = half - aMid;

            int nums1Left = aMid > 0 ? nums1[aMid - 1] : std::numeric_limits<int>::min();
            int nums1Right = aMid < nums1.size() ? nums1[aMid] : std::numeric_limits<int>::max();
            int nums2Left = bMid > 0 ? nums2[bMid - 1] : std::numeric_limits<int>::min();
            int nums2Right = bMid < nums2.size() ? nums2[bMid] : std::numeric_limits<int>::max();

            if (nums1Left <= nums2Right && nums2Left <= nums1Right) {
                if (isEven) return (std::max(nums1Left, nums2Left) + std::min(nums1Right, nums2Right)) / 2.0;
                return std::max(nums1Left, nums2Left);
            } else if (nums1Left > nums2Right) {
                right = aMid - 1;
            } else {
                left = aMid + 1;
            }
        }
    }
};
