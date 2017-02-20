/*
 * CSS333 - HW5 - list.c
 *
 * @author - Arwain Giannini-Karlin
 * @date - 2/16/2017
 */

#include <stdio.h>
#include <stdlib.h>

#include "list.h"


void printAll(struct node *list) {
    struct node *curr = list;
    printf("List: ");
    while (curr != NULL) {  // Watch Out: curr->next !=  NULL
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

struct node *add_to_list(struct node *list, int n) {
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = n;
    new_node->next = list;
    return new_node;
}

void add_to_listP2P(struct node **list, int n) {
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = n;
    new_node->next = *list;
    *list = new_node;
}

int inOrder(struct node *list) {
    struct node *curr = list;
    if (curr == NULL)
        return 1;
    while (curr->next != NULL) {  // SAFETY CHECK: curr  != NULL
        if (curr->value > curr->next->value) {  // SAFETY CHECK:  curr->next != NULL
            return 0;
        }
        curr = curr->next;
    }
    return 1;
}

struct node *delete_from_list(struct node *list, int n) {
    struct node *cur, *prev;
    for (cur = list, prev = NULL;
         cur != NULL;
         prev = cur, cur = cur->next) {
        if (cur->value == n) {
            if (prev == NULL)
                list = list->next; /* n is in the first node */
            else
                prev->next = cur->next; /* n is in some other node */
            free(cur);
            break;
        }
    }
    return list;
}

int looplesslength(struct node *list) {

    // Below are some edge case checks.
    if (!list) {
        return 0;
    } else if (!list->next) {
        return 1;
    } else if (list->next == list) {
        return -1;
    }

    struct node *slow = list, *fast = list->next;
    int count = 0;
    while (slow && fast != slow) {
        count++;
        slow = slow->next;
        if (fast && fast->next) {
            fast = fast->next->next;
        } else {
            fast = NULL;
        }
    }

    if (!fast) {
        return count;
    }
    count = 0;
    slow = list;

    // Here is where our loop meets.
    while (slow != fast->next) {
        count++;
        slow = slow->next;
        fast = fast->next;
    }

    while (slow != fast) {
        count++;
        slow = slow->next;
    }

    return -(count + 1);
}

struct node *merge(struct node *list1, struct node *list2) {

    struct node *current1, *current2, *mergeList, *mergeCurrent;
    current1 = list1;
    current2 = list2;
    if (!current1) {
        return current2;
    } else if (!current2) {
        return current1;
    } else {
        if (current1->value <= current2->value) {
            mergeList = current1;
            current1 = current1->next;
        } else {
            mergeList = current2;
            current2 = current2->next;
        }
        mergeCurrent = mergeList;
        while (current1 && current2) {
            if (current1->value >= current2->value) {
                mergeCurrent->next = current2;
                current2 = current2->next;
            } else {
                mergeCurrent->next = current1;
                current1 = current1->next;
            }
            mergeCurrent = mergeCurrent->next;
        }
        if (current1) {
            mergeCurrent->next = current1;
        } else if (current2) {
            mergeCurrent->next = current2;
        }
    }
    return mergeList;
}

int nodupdata(struct node *list) {

    struct node *head, *tail;
    // Loop while head is not NULL
    for (head = list; head; head = head->next) {
        // Loop while tail is not NULL
        for (tail = head->next; tail; tail = tail->next) {
            if (head->value == tail->value) {
                return 0;
            }
        }
    }
    return 1;
}


struct node *doubleAll(struct node *list) {

    struct node *current;
    current = list;
    if (!current) {
        printf("Error : List is NULL, cannot be doubled.\n");
    }
    while (current != NULL) {
        struct node *copy;
        copy = malloc(sizeof(struct node));
        copy->value = current->value;
        copy->next = current->next;
        current->next = copy;
        current = copy->next;
    }
    return list;
}

struct node *deleteAll(struct node *list, int n) {

    struct node *current, *head, *temp;
    current = list;
    head = list;
    /*
     * This loop checks if the head and possibly following values
     * are equal to the target integer. If so we reset the head
     * of the list to the value after the target and free the
     * target memory.
     */
    while (head && head->value == n) {
        head = head->next;
        free(current);
        current = head;
    }
    /*
     * This loop checks if the body of the list contains the
     * target integer. If so we cut the target integer and
     * free the memory.
     */
    while (current && current->next != NULL) {

        if (current->next->value == n) {
            temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
    return head;


}
