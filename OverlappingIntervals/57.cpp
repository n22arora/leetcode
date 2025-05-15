class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;

        sort(intervals.begin(), intervals.end());

        for (auto interval: intervals) {

            if (result.empty() || interval[0] > result.back()[1]) {
                result.push_back(interval);
            }
            else {
                result.back()[1] = max(interval[1], result.back()[1]);
            }
        }

        return result;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        vector<vector<int>> result = merge(intervals);
        return result;
    }
};