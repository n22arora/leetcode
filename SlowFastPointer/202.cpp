// APPROACH 1
class Solution {
public:
    int square(int num) {
        int ans = 0;

        while (num > 0) {
            int rem = num % 10;
            ans += (rem * rem);
            num /= 10;
        }

        return ans;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do {
            slow = square(slow);
            fast = square(square(fast));
        } while ((slow != fast) && (fast != 1));

        return fast == 1;
    }
};

// APPROACH 2
class Solution {
public:
    int get_sum(int n) {
        vector<int> nums;

        while (n != 0) {
            nums.push_back(n%10);
            n = n/10;
        }

        int sum = 0;

        for (int i = 0 ; i < nums.size() ; i++) {
            sum += (nums[i] * nums[i]);
        }

        return sum;
    }
    bool isHappy(int n) {

        if (n == 1) return true;

        set<int> seen;
        seen.insert(n);

        int sum = n;

        while (true) {
            sum = get_sum(sum);

            if (sum == 1) return true;

            if (seen.contains(sum)) {
                return false;
            }

            seen.insert(sum);
        }

        return false;
    }
};