
/*
Leetcode: https://leetcode.com/problems/linked-list-cycle/?envType=problem-list-v2&envId=oizxjoit

This uses a 2 pointer (Slow and Fast) approach.
Fast Pointer moves twice as fast (node->next->next) compared to  the slow pointer (node->next).

If there is a cycle in the linked list, then at some point, 
the fast pointer will point to the same node as the slow pointer. 
*/
bool hasCycle(struct ListNode *head) {
    struct ListNode* slow_ptr = head;
    struct ListNode* fast_ptr = head;
	
	// Here, we check if fast_ptr->next!=NULL as we are accessing fast_ptr->next->next to traverse the fast pointer
    while(fast_ptr !=NULL && fast_ptr->next!=NULL)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        
        if(slow_ptr==fast_ptr)
        {
            return true;
        }
    }
    return false;
}