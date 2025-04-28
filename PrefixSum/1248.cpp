// 1248. Count Number of Nice Subarrays
// Variant of subarray sum equals K - replace all even with 0 and odd with 1 

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 0 ; i < n ; i++) {
            nums[i] = (nums[i] % 2 == 0) ? 0 : 1;
        }

        int sum = 0;
        int result = 0;
        unordered_map<int, int> map;

        for (int i = 0 ; i < n ; i++) {
            sum += nums[i];

            if (sum == k) {
                result++;
            }

            if (map.contains(sum - k)) {
                result += map[sum-k];
            }

            if (map.contains(sum)) {
                map[sum]++;
            } else {
                map.insert({sum, 1});
            }
        }

        return result;
    }
};
