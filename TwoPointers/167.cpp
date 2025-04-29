class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> map;

        for (int i = 0 ; i < numbers.size() ; i++) {
            int diff = target - numbers[i];

            if (map.contains(diff)) {
                if ((i+1) < (map[diff] + 1)) return {i+1, map[diff] + 1};
                else return {map[diff] + 1, i+1};
            } else {
                map.insert({numbers[i], i});
            }
        }

        return {-1, -1};
    }
};