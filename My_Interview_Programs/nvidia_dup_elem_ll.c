#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};


void removeDuplicates(struct Node* head) {
    struct Node* current = head;
    
    while (current != NULL && current->next != NULL) {
        if (current->value == current->next->value) { // Comparing adjacent nodes as sorted ll
            // Duplicate found, delete next node
            struct Node* temp = current->next;
            current->next = current->next->next; // Point to the node after skipping the next node
            free(temp);
        } else {
            current = current->next;
        }
    }
}
