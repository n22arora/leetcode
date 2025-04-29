// Remove duplicates inplace

// APPROACH 1 - O(n)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        if (n < 2) return n;

        int read = 1, write = 0;
        int count = 1;

        for (int read = 1 ; read < n ; read++) {
            if (nums[read] != nums[write]){
                write++;
                nums[write] = nums[read];
                count++;
            }
        }

        return count;
    }
};

// APPROACH 2 - O(n^2)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.size() < 2) return nums.size();

        int left = 0; 
        int right = left + 1;

        bool found = true;

        while (found) {
            found = false; 

            for (int i = 0 ; i < nums.size() - 1 ; i++) {
                if (nums[i] == nums[i+1]) {
                    found = true;
                    nums.erase(nums.begin() + i);
                }
            }
        }

        return nums.size();
    }
};