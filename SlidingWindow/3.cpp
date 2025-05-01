class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        int left = 0;
        int right = 0;

        set<char> seen;

        while (right < s.size()) {
            if (!seen.contains(s[right])) {
                seen.insert(s[right]);
                int n = seen.size();
                max_len = max(max_len, n);
                right++;
            }

            while (seen.contains(s[right])) {
                seen.erase(s[left]);
                left++;
            }
        }

        return max_len;
    }
};