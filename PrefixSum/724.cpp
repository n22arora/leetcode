// APPROACH 1 - O(n) - lesser allocations
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        int total_sum = 0;
        int curr_sum = 0; 

        for (auto num : nums) {
            total_sum += num;
        }

        for (int i = 0 ; i < n ; i++) {
            curr_sum += nums[i];

            if (curr_sum - nums[i] == (total_sum - curr_sum)) {
                return i;
            }
        }

        return -1;
    }
};


// APPROACH 2 - O(n) but more memory space used
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n, 0);
        vector<int> right(n, 0);
        vector<int> ans(n, 0);

        for (int i = 1 ; i < n ; i++) {
            left[i] = left[i-1] + nums[i-1];
        }

        for (int i = n - 2; i >= 0 ; i--) {
            right[i] = right[i+1] + nums[i+1];
        }

        for (int i = 0 ; i < n ; i++) {
            if (left[i] == right[i]) return i;
        }

        return -1;
    }
};