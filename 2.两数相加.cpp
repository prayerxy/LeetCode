/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
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
//  struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //结果链表
        ListNode*res=new ListNode;
        ListNode*tmp=nullptr;
        ListNode*head=res;
        int val=0;
        int add=0;
        while(l1&&l2){
            val=(l1->val+l2->val+add)%10;
            add=(l1->val+l2->val+add)/10;
            res->val=val;
            if(tmp){
                tmp->next=res;
            }
            tmp=res;
            res=new ListNode;
            //更新l1与l2
            l1=l1->next;
            l2=l2->next;
        }
        //如果l1与l2的长度不相同
        while(l1){

            res->val=(l1->val+add)%10;
            add=(l1->val+add)/10;
            l1=l1->next;
            tmp->next=res;
            tmp=res;
            res=new ListNode;
        }
        while(l2){

            res->val=(l2->val+add)%10;
            add=(l2->val+add)/10;
            l2=l2->next;
            tmp->next=res;
            tmp=res;
            res=new ListNode;
        }
        if(add){
            //最后的高位进位
            res->val=add;
            tmp->next=res;
        }
        return head;
    
    }
};
// @lc code=end

