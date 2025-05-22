class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);  // Initialize all with -1

        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                int index = (i + j) % n;  // circular traversal
                if (nums[index] > nums[i]) {
                    result[i] = nums[index];
                    break;
                }
            }
        }

        return result;
    }
};
