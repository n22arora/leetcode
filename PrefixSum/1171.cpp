// APPROACH 1 - linked list to array to linked list

/* 
Things to consider:
1. Reset sum, map with reducing array size
2. Handle the case when sum = 0
3. Handle the case for previously seen sum
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* temp = head;
        vector<int> arr; 

        while (temp != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        bool found = true;

        while (found) {
            int n = arr.size();
            unordered_map<int, int> map;
            int sum = 0;

            cout<<"n: "<<n<<endl;

            found = false;

            for (int i = 0 ; i < n ; i++) {
                sum += arr[i];

                if (sum == 0) {
                    arr.erase(arr.begin(), arr.begin() + i + 1);
                    found = true;
                    break;
                }

                if (map.contains(sum)) {
                    arr.erase(arr.begin() + map[sum] + 1, arr.begin() + i + 1);
                    found = true;
                    break;
                } else {
                    map.insert({sum, i});
                }
            }
        }

        if (arr.size() == 0) return NULL;

        ListNode* result = new ListNode(0);
        temp = result;

        for (int i = 0 ; i < arr.size() ; i++) {
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }
        
        return result->next;
    }
};