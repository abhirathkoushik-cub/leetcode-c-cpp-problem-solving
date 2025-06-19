/**
Leetcode: https://leetcode.com/problems/merge-two-sorted-lists/?envType=problem-list-v2&envId=oizxjoit
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* head1=list1;
    struct ListNode* head2=list2;
    
    struct ListNode new_list; // Creating a Dummy Node to start a Answer List
    struct ListNode* new_list_tr = &new_list; // Creating a pointer to traverse the Answer List

    // As long as both the LLs are not NULL, add the smaller of the values to the Answer List
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->val < head2->val)
        {
            new_list_tr->next=head1;
            head1=head1->next;
        }
        else
        {
            new_list_tr->next=head2;
            head2=head2->next;
        }
        new_list_tr=new_list_tr->next; // Move the Answer List forward after each addition
    }

    while(head1!=NULL) // Add the remaining nodes (if any) of LL-1 to the Answer List
    {
        new_list_tr->next=head1;
        head1=head1->next;
        new_list_tr=new_list_tr->next;
    }

    while(head2!=NULL) // Add the remaining nodes (if any) of LL-2 to the Answer List
    {
        new_list_tr->next=head2;
        head2=head2->next;
        new_list_tr=new_list_tr->next;
    }
    return new_list.next; // Returning the head of the Answer list, from the dummy node
}
