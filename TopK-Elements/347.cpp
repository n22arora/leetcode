class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        auto compare = [](pair<int, int> a, pair<int, int> b) {
            return a.second > b.second;
        };
        priority_queue<pair<int,int>, vector<pair<int, int>>, decltype(compare)> pq(compare);

        unordered_map<int,int> map;
        vector<int> result;

        for (auto num : nums) {
            map[num]++;
        }

        for (auto key : map) {
            pq.push({key.first, key.second});

            if (pq.size() > k) pq.pop();
        }

        while (pq.size() > 0) {
            result.push_back(pq.top().first);
            pq.pop();
        }

        return result;
    }
};