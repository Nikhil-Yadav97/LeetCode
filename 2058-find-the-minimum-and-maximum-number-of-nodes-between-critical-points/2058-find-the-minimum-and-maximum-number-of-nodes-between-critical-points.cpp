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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> criticalpoints;
        if (head == NULL || head->next == NULL)
            return {-1, -1};

        ListNode* temp = head;
        ListNode* prev = head;
        temp = temp->next;
        int i = 1;
        while (temp) {
            ListNode* next = temp->next;

            if (next != NULL) {
                if (temp->val > next->val && temp->val > prev->val ||
                    temp->val < next->val && prev->val > temp->val)
                    criticalpoints.push_back(i);
            }

            i++;
            prev = temp;
            temp = temp->next;
        }

        sort(begin(criticalpoints), end(criticalpoints));
        if (criticalpoints.size() <= 1)
            return {-1, -1};

        int minDist = INT_MAX;

        for (int i = 1; i < criticalpoints.size(); i++) {
            minDist = min(minDist, criticalpoints[i] - criticalpoints[i - 1]);
        }

        int maxDist = criticalpoints.back() - criticalpoints.front();

        return {minDist, maxDist};
    }
};