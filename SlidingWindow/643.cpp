class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if (k > nums.size()) return 0;

        double sum = 0;

        for (int i = 0 ; i < k ; i++) {
            sum += nums[i];
        }

        double max_avg = sum/k;

        for (int i = k ; i < nums.size() ; i++) {
            sum += nums[i];
            sum -= nums[i-k];
            max_avg = max(max_avg, sum/k);
        }

        return max_avg;
    }
};