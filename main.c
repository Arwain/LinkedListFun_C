/*
 * main.c
 *
 * @author - Arwain Giannini-Karlin
 * @date - 2/16/2017
 */


#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void testDeleteAll() {

    printf("\nTESTING DELETE ALL\n");
    printf(".......................\n\n");
    struct node *intlist = NULL;
    int i;
    // Head removal case below.
    for (i = 0; i < 10; i++) {
        intlist = add_to_list(intlist, i);

    }
    intlist = add_to_list(intlist, 5);
    intlist = add_to_list(intlist, 5);
    intlist = add_to_list(intlist, 5);
    intlist = add_to_list(intlist, 5);
    printf("Here is our list to test the head removal:\n");
    printAll(intlist);
    intlist = deleteAll(intlist, 5);
    printf("We call our function and it removes the 5's from the head and the body of our list:\n");
    printAll(intlist);
    printf("Now we remove the 0 which is our other edge case:\n");
    intlist = deleteAll(intlist, 0);
    printAll(intlist);
    printf("Now we remove the rest begining at 9\n");
    for (i = 9; i > 0; i--) {
        intlist = deleteAll(intlist, i);
        printAll(intlist);

    }


}

void testDoubleAll() {

    printf("\nTESTING DOUBLE ALL\n");
    printf(".......................\n\n");

    struct node *intlist = NULL;
    int i;
    // Head removal case below.
    for (i = 0; i < 10; i++) {
        intlist = add_to_list(intlist, i);

    }
    printf("Here is our original list:\n");
    printAll(intlist);
    printf("Now we call our function...\n");
    intlist = doubleAll(intlist);
    printf("Here is our new list:\n");
    printAll(intlist);
    printf("Now we set our list to NULL to test the NULL catch...\n");
    intlist = NULL;
    intlist = doubleAll(intlist);
    printf("Only edge case is the head digit which we've covered so only one test needed.\n");

}

void testMerge() {

    printf("\nTESTING MERGE\n");
    printf(".......................\n\n");

    struct node *list1 = NULL;
    struct node *list2 = NULL;
    struct node *list3 = NULL;
    int i;
    list1 = add_to_list(list1, 11);
    list1 = add_to_list(list1, 9);
    list1 = add_to_list(list1, 7);
    list1 = add_to_list(list1, 5);
    list1 = add_to_list(list1, 3);
    list1 = add_to_list(list1, 1);
    list2 = add_to_list(list2, 12);
    list2 = add_to_list(list2, 10);
    list2 = add_to_list(list2, 8);
    list2 = add_to_list(list2, 6);
    list2 = add_to_list(list2, 4);
    list2 = add_to_list(list2, 2);

    printf("Here is list 1:\n");
    printAll(list1);
    printf("Here is list 2:\n");
    printAll(list2);

    list3 = merge(list2, list1);
    printf("Here is our merged list:\n");
    printAll(list1);


}

void testNodupdata() {

    printf("\nTESTING NO DUP DATA\n");
    printf(".......................\n\n");

    struct node *intlist = NULL;
    int i;
    // Head removal case below.
    for (i = 0; i < 10; i++) {
        intlist = add_to_list(intlist, i);

    }
    printf("First we test on our data without duplicates...\n");
    printAll(intlist);
    printf("Our function returns : %d\n", nodupdata(intlist));
    printf("Now we add a duplicate...\n");
    intlist = add_to_list(intlist, 3);
    printAll(intlist);
    printf("Our function returns : %d\n", nodupdata(intlist));
    printf("Our edge case is finding duplicates at the head so we are done here.\n");

}

void testlooplesslength() {


    printf("\nTESTING LOOPLESS LENGTH\n");
    printf(".......................\n\n");
    struct node *list1 = NULL;
    int value;

    list1 = add_to_list(list1, 12);
    list1 = add_to_list(list1, 11);
    list1 = add_to_list(list1, 10);
    list1 = add_to_list(list1, 9);
    list1 = add_to_list(list1, 8);
    list1 = add_to_list(list1, 7);
    list1 = add_to_list(list1, 6);
    list1 = add_to_list(list1, 5);
    list1 = add_to_list(list1, 4);
    list1 = add_to_list(list1, 3);
    list1 = add_to_list(list1, 2);
    list1 = add_to_list(list1, 1);

    printf("Here is our list:\n");
    printAll(list1);
    printf("Before we link it, we call our function...\n");
    value = looplesslength(list1);
    printf("Length is %d\n", value);

    printf("Now we link it tail to head and call our function...\n");
    // Below links tail to the head of the list
    list1->next->next->next->next->next->next->next->next->next->next->next->next = list1->next->next;

    value = looplesslength(list1);
    printf("Length is %d\n", value);
}

int main(void) {

    testDeleteAll();
    testDoubleAll();
    testMerge();
    testNodupdata();
    testlooplesslength();


    return 0;
}
