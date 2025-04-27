// ACTUAL SOLUTION
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hmap;
        int maxlen = 0, count = 0;

        for (int i = 0 ; i < nums.size() ; i++) {
            count += (nums[i] == 1) ? 1 : -1;

            if (count == 0) {
                maxlen = max(maxlen, i+1);
            }

            if (hmap.contains(count)) {
                maxlen = max(maxlen, i - hmap[count]);
            } else {
                hmap.insert({count, i});
            }
        }

        return maxlen;
    }
};


// EXTRA - A case where it has to be 11110000 or 00001111 and no intermixing and number of 0 has to be equal to number of 1s

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hmap;
        int result = 0;
        int sum = 0;

        hmap.insert({0, 0});
        hmap.insert({1,0});

        if (nums[0] == 0) {
            hmap[0]++;
        } else {
            hmap[1]++;
        }

        int max_count = 0;

        for (int i = 1 ; i < nums.size() ; i++) {
            hmap[nums[i]]++;

            if (nums[i] != nums[i-1]) {
                max_count = max(max_count, 2 * min(hmap[0], hmap[1]));
            }

            if (i != nums.size() - 1) {
                if (nums[i + 1] != nums[i]) {
                    hmap[nums[i+1]] = 0;
                }

                
            }
        }

        max_count = max(max_count, 2 * min(hmap[0], hmap[1]));

        return max_count;
    }
};

