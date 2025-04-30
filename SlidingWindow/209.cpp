class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_len = INT_MAX;
        long long sum = 0;
        int left = 0, right = 0;

        while (right < nums.size()) {
            if (nums[right] == target) return 1;

            if (sum < target) {
                sum += nums[right];
                right++;
            }

            while (sum >= target) {
                min_len = min(min_len, right - left);
                sum -= nums[left];
                left++;
            }
        }

        if (min_len == INT_MAX) return 0;

        return min_len;
    }
};