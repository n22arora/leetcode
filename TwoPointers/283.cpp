class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        if ( nums.size() >= 2 ) {
            int write = 0, read = 0;

            while (read <= nums.size() - 1) {
                if (nums[read] != 0) {
                    if (nums[write] == 0) {
                        nums[write] = nums[read];
                        nums[read] = 0;
                    }
                    write++;
                }
                read++;
            }
        }

    }
};