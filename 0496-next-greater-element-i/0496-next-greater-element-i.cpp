class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;

        for (int i = 0; i < nums1.size(); ++i) {
            int index = -1;

            // Find the index of nums1[i] in nums2
            for (int j = 0; j < nums2.size(); ++j) {
                if (nums2[j] == nums1[i]) {
                    index = j;
                    break;
                }
            }
            // Find the next greater element in nums2
            int nextGreater = -1;
            for (int j = index + 1; j < nums2.size(); ++j) {
                if (nums2[j] > nums1[i]) {
                    nextGreater = nums2[j];
                    break;
                }
            }
            result.push_back(nextGreater);
        }
        return result;
    }
};
