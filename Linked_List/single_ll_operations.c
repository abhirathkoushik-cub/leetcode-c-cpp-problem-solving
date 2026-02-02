#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

void display_ll(struct ListNode* ptr)
{
    struct ListNode* temp_ptr = ptr;
    while(temp_ptr != NULL)
    {
        printf("%d->", temp_ptr->val);
        temp_ptr = temp_ptr->next;
    }
    printf("NULL\n");
}

struct ListNode* create_node(int data)
{
    struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->val = data;
    new_node->next = NULL;
    return new_node;
}

void ll_enqueue(struct ListNode* head, int num)
{
    // enqueue at the tail
    struct ListNode *next_node = create_node(num);
    struct ListNode *temp_ptr = head;
    while(temp_ptr->next != NULL)
    {
        temp_ptr = temp_ptr->next;
    }
    temp_ptr->next = next_node;
}

void ll_add_after(struct ListNode* ptr, int tar_num, int new_data)
{
    // enqueue in the middle
    struct ListNode *next_node = create_node(new_data);
    
    struct ListNode *temp_ptr = ptr;
    while(temp_ptr != NULL)
    {   
        if (temp_ptr->val == tar_num)
        {
            struct ListNode *temp_store = temp_ptr->next;
            temp_ptr->next = next_node;
            next_node->next = temp_store;
        }
        temp_ptr = temp_ptr->next;
    }
}

// pointer to the head pointer required here
void ll_add_start(struct ListNode** head_ptr, int new_data)
{
    // enqueue in the start
    struct ListNode *next_node = create_node(new_data);
    next_node->next = *head_ptr;
    *head_ptr = next_node;
}

// pointer to the head pointer required here
void ll_dequeue(struct ListNode** head_ref)
{
    // dequeue at the head
    if (*head_ref == NULL)
        return;
    
    struct ListNode* temp_ptr = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp_ptr);
}

// pointer to the head pointer required here
void dequeue_end(struct ListNode** head_ref)
{
    // dequeue from the end 
    
    if (*head_ref == NULL) return;

    // Only 1 Node
    if ((*head_ref)->next == NULL) {
        free(*head_ref); 
        *head_ref = NULL;   // Set the actual head variable in main to NULL
        return;
    }

    struct ListNode* ptr = *head_ref;
    
    while (ptr->next->next != NULL) {
        ptr = ptr->next;
    }

    free(ptr->next); 
    ptr->next = NULL;
}

// pointer to the head pointer required here
void dequeue_middle(struct ListNode** head_ref, int tar_num)
{
    struct ListNode* curr = *head_ref;
    struct ListNode* prev = NULL;

    while(curr != NULL)
    {
        if(curr->val == tar_num)
        {
            // If head needs to be deleted
            if (prev == NULL) {
                *head_ref = curr->next; // Update head in main
            }
            // If any middle or tail node needs to be deleted
            else {
                prev->next = curr->next; 
            }
            
            free(curr);
            return;
        }
        
        // Advance pointers
        prev = curr;
        curr = curr->next;
    }
}

int main()
{
    struct ListNode *head_node = create_node(10);
    ll_enqueue(head_node, 20);
    ll_enqueue(head_node, 30);
    display_ll(head_node);
    
    ll_dequeue(&head_node);
    display_ll(head_node);
    
    ll_add_after(head_node, 20, 50);
    display_ll(head_node);
    
    ll_add_start(&head_node, 70);
    display_ll(head_node);
    
    dequeue_end(&head_node);
    display_ll(head_node);
    
    dequeue_middle(&head_node, 20);
    display_ll(head_node);
    
    return 0;
}
