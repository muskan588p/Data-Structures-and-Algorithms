class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> ans; 
        int size = arr.size(); 
        int i = 0; 
        
        sort(arr.begin(), arr.end());

        //Count occurrences of each unique number
        while (i < size) {
            int count = 1; // Initialize the count for the current number
            for (int j = i + 1; j < size; j++) {
                if (arr[i] == arr[j]) {
                    count++; 
                } else {
                    break; 
                }
            }
            ans.push_back(count);
            i = i + count; 
        }
        //Check if the counts are unique
        size = ans.size(); // Update the size to the number of unique counts
        sort(ans.begin(), ans.end()); 
        for (int i = 0; i < size - 1; i++) {
            if (ans[i] == ans[i + 1]) {
                return false; 
            }
        }
        return true; // All frequencies are unique
    }
};