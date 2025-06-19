/**
Leetcode: https://leetcode.com/problems/reorder-list/?envType=problem-list-v2&envId=oizxjoit

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    struct ListNode* asc_node=head; // Fast Node
    struct ListNode* des_node=head; // Slow Node
    
    // Creating a Dummy Node and Pointer to it
    struct ListNode dummy_node;
    struct ListNode* dummy_ptr = &dummy_node;

    // Find Middle Element based on fast&slow pointer approach. des_node will point to the middle element.
    while(asc_node!=NULL && asc_node->next!=NULL)
    {
        asc_node=asc_node->next->next;
        des_node=des_node->next;
    }

    // Reverse 2nd half of the List. pre_node will point to the start of the Reversed List.
    struct ListNode* pre_node=NULL;
    struct ListNode* curr_node=des_node; // des_node is pointing to the Middle element
    struct ListNode* next_node=NULL;
    while(curr_node!=NULL)
    {
        next_node = curr_node->next;
        curr_node->next = pre_node; 
        pre_node = curr_node;
        curr_node = next_node;
    }

    // Form the Answer List
    struct ListNode* left_node=head;   
    struct ListNode* right_node=pre_node; // pre_node is the start of the Reversed 2nd half
    
    /* 1st half of the list ascending till Middle Element and 
       2nd half of the list descending till NULL */ 
    while(left_node!=des_node && right_node!=NULL)
    {
        // Add the Ascending value (left_node) to the Answer List
        dummy_ptr->next=left_node;
        dummy_ptr=dummy_ptr->next;
        left_node=left_node->next;
        
        // Add the Descending value (right_node) to the Answer List
        dummy_ptr->next=right_node;
        dummy_ptr=dummy_ptr->next;
        right_node=right_node->next;
    }

    // Display the Answer List which starts with dummy_node.next
    struct ListNode* print_ll=dummy_node.next;
    while(print_ll!=NULL)
    {
        printf("%d ", print_ll->val);
        print_ll=print_ll->next;
    }
}
