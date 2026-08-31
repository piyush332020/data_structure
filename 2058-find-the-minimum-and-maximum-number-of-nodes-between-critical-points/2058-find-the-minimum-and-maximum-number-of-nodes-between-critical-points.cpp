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
        ListNode* curr=head->next;
        ListNode* left=head;
        ListNode* right=head->next->next;
        vector<int>ans;
        int count=2;
        while(right){
            if((left->val<curr->val && curr->val>right->val) || (left->val>curr->val && curr->val<right->val)){
                ans.push_back(count);
            }
            count++;
            left=curr;
            curr=right;
            right=right->next;
        }
        int mindist=INT_MAX;
        int maxdist=0;
        int n=ans.size();
        if(ans.size()>=2){
            for(int i=1;i<ans.size();i++){
                mindist=min(mindist,ans[i]-ans[i-1]);
            }
            maxdist=ans[n-1]-ans[0];
            return {mindist,maxdist};
        }
        return {-1,-1};
    }
};