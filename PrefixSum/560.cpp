class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hmap;

        int sum = 0; 
        int result = 0;

        for (auto num : nums) {
            sum += num; 

            if (hmap.contains(sum - k)) {
                result += hmap[sum-k];
            }

            if (hmap.contains(sum)) {
                hmap[sum]++;
            } else {
                hmap.insert({sum, 1});
            }

            if (sum == k) {
                result++;
            }
        }

        return result;
    }
};