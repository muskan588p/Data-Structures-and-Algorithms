class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> ans; // Stores the frequency of each unique element
        int size = arr.size(); // Get the size of the input array
        int i = 0; // Start pointer for iteration
        
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());

        // Step 2: Count occurrences of each unique number
        while (i < size) {
            int count = 1; // Initialize the count for the current number
            for (int j = i + 1; j < size; j++) {
                if (arr[i] == arr[j]) {
                    count++; // Increment count if the next number is the same
                } else {
                    break; // Stop counting when a different number is encountered
                }
            }
            ans.push_back(count); // Store the count of occurrences
            i = i + count; // Move to the next unique number
        }

        // Step 3: Check if the counts are unique
        size = ans.size(); // Update the size to the number of unique counts
        sort(ans.begin(), ans.end()); // Sort the frequency list
        for (int i = 0; i < size - 1; i++) {
            if (ans[i] == ans[i + 1]) {
                return false; // If two frequencies are the same, return false
            }
        }

        return true; // All frequencies are unique, return true
    }
};
