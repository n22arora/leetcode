class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int left = 0, right = 0;

        unordered_map<int, int> seen;

        while (right < nums.size()) {
            while (seen.contains(nums[right])) {
                if (nums[right] == nums[left] && (right-left) <= k) {
                    return true;
                }
                seen.erase(nums[left]);
                left++;
            }

            if (!seen.contains(nums[right])) {
                seen.insert({nums[right], right});
                right++;
            }
        }

        return false;
    }
};