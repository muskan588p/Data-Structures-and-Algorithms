#include <vector>
using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int freq[101] = {0}; // Frequency array (assuming nums contains values in the range [1, 100])
        int sum = 0;

        // Count the frequency of each element
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        // Calculate the sum of unique elements
        for (int i = 0; i < nums.size(); i++) {
            if (freq[nums[i]] == 1) {
                sum += nums[i];
            }
        }

        return sum;
    }
};
