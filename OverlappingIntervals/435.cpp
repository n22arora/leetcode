class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int count = 0;

        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) { 
            return a[1] < b[1]; 
        });

        for (auto interval: intervals) {

            if (result.empty() || interval[0] >= result.back()[1]) {
                result.push_back(interval);
            }
            else {
                count++;
            }
        }

        return count;
    }
};