/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */    

 #include <stdio.h>
 
bool palindrome_check(struct ListNode* head)
{       
    struct ListNode* fast_node = head;
    struct ListNode* slow_node = head;

    // Find middle element using Fast-Slow Node Approach. 
    while(fast_node!=NULL && fast_node->next!=NULL)
    {
        fast_node = fast_node->next->next;
        slow_node=slow_node->next;
    }

    // Reverse 2nd half linked list
    struct ListNode* prev_node = NULL;
    struct ListNode* current_node = slow_node; // slow_node points to middle element
    struct ListNode* next_node = NULL;
    while(current_node!=NULL)
    {
        next_node = current_node->next;
        current_node->next = prev_node; 
        prev_node = current_node;
        current_node = next_node;
    }

    // Check Palindrome
    struct ListNode* left_node = head;
    struct ListNode* right_node = prev_node; // prev_node points to the start of the reversed list
    while(right_node != NULL){
        if (left_node->val != right_node->val){
            return false;
        }
        left_node=left_node->next;
        right_node=right_node->next;
    }
    return true;
}