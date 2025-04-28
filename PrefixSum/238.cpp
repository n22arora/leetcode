// APPROACH 1 - O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size(), 1);
        vector<int> right(nums.size(), 1);
        vector<int> result(nums.size(), 1);

        for (int i = 1 ; i < nums.size() ; i++) {
            left[i] = left[i-1] * nums[i-1];
        }

        for (int i = nums.size() - 2 ; i >= 0 ; i--) {
            right[i] = right[i+1] * nums[i+1]; 
        }

        for (int i = 0 ; i < nums.size() ; i++) {
            result[i] = left[i] * right[i];
        }

        return result;
    }
};


// APPROACH 2 - O(n^2)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, 1);

        for (int i = 0 ; i < n ; i++) {
            int prod = 1;
            for (int j = 0 ; j < n ; j++) {
                if (i == j) continue;

                prod *= nums[j];
            }

            ans[i] = prod;
        }

        return ans;
    }
};