/*
 File:         linkedlist.c
 Purpose:      Implements the linked list functions whose prototypes
               are declared in the linked_list.h header file
 Author:       Your names
 Student #s:   12345678 and 12345678
 CS Accounts:  a1a1 and b2b2
 Date:         Add the date here
 */

/* Preprocessor directives */
#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/******************************************************************
 PLEASE EDIT THIS FILE

 Comments that start with // should be replaced with code
 Comments that are surrounded by * are hints
 ******************************************************************/

/*
 Returns a pointer to a new, empty linked list of struct node.
 PRE:       NULL (no pre-conditions)
 POST:      NULL (no side-effects)
 RETURN:    A pointer to a new, empty linked list of struct node (NULL)
 */
struct node *create_linked_list() {
    return NULL;
}

/*
 Returns a dynamically allocated struct node that contains the specified
 struct airplane.  The node's next pointer doesn't point to anything
 e.g., it is equal to NULL.
 PARAM:     plane, a struct airplane
 PRE:       NULL (no pre-conditions)
 POST:      NULL (no side-effects)
 RETURN:    A pointer to a dynamically allocated struct node a) that contains
            the specified struct airplane, and b) whose next pointer points to
 NULL
 */
struct node *create_node(struct airplane plane) {
    // Insert your code here

    // replace this line with something appropriate
    return NULL;
}

/*
 Prepends a struct node passed as a parameter to the list passed as a
 parameter, and returns a pointer to the result.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     new_node is a pointer to a struct node
 PRE:       new_mode is not null
 POST:      The specified struct node is added to the beginning of the list
            and its next pointer points to the node that used to be first
 RETURN:    A pointer to a linked list which contains all of the nodes
            of the list passed as a parameter, plus a prepended node
 */
struct node *prepend_node(struct node *list, struct node *new_node) {
    // Insert your code here

    // replace this line with something appropriate
    return NULL;
}

/*
 Deletes the first struct node in the specified list, and returns a pointer to
 the shortened list.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL
 POST:      The list passed as a parameter has one fewer node, and the
 dynamically allocated memory which contained that removed node has been freed
 RETURN:    IF the list is empty
            THEN NULL
            ELSE a pointer to the shortened list
 */
struct node *delete_node(struct node *list) {
    if (list == NULL) {
        return NULL; // do nothing
    }
    struct node *next = list->next;
    free(list);
    return next;
}

/*
 Returns the number of nodes in the specified linked list of struct node.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL (no pre-conditions)
 POST:      NULL (no side-effects)
 RETURN:    The length of the specified list, an int
 */
int get_length(struct node *list) {
    // Insert your code here
    int len = 0;
    while (list != NULL) {
        ++len;
        list = list->next;
    }

    return len;
}

/*
 Deletes an entire list.  This function iterates along a list and deallocates
 the memory containing each struct node. PARAM:     list is a pointer to a
 (possibly empty) linked list of struct node PRE:       NULL (no pre-conditions)
 POST:      The memory containing all of the nodes in the list has been freed
 RETURN:    an empty list (NULL)
 */
struct node *delete_list(struct node *list) {
    while (list != NULL) {
        struct node *tmp = list->next;
        free(list);
        list = tmp;
    }

    return NULL;
}

/*
 Prints the data stored in a node.  For the struct airplane in the node,
 prints the fields on separate lines.  For each field, prints the field name
 and the field value.  For the pointer, prints "Link = NULL\n" if the pointer
 points to null, else prints "Link points to address xxx\n", where xxx is the
 pointer address in hexademical. If node_to_print is NULL, prints "The node is
 empty\n". PARAM:     node_to_print is a pointer to a (possibly null) struct
 node PRE:       NULL (no pre-conditions) POST:      Information about
 node_to_print has been printed to standard output RETURN:    NULL
 */
void print_node(struct node *node_to_print) {
    if (node_to_print == NULL) {
        printf("Link = NULL\n");
        return;
    }
    printf("Link points to address %p", node_to_print);
    // struct airplane plane = node_to_print->data;
    // printf("");
}

/*
 Prints the data stored in all nodes in the specified list to print.
 For each node, prints the data inside the node the same way that it
 is printed by print_node.  If the list is empty, a suitable message
 is printed to standard output.
 PARAM:     node_to_print is a pointer to a (possibly empty) linked list of
            struct node
 PRE:       NULL (no pre-conditions)
 POST:      Information about list_to_print has been printed to standard output
 RETURN:    NULL
 */
void print_list(struct node *list_to_print) {
    if (list_to_print == NULL) {
        printf("List is empty!\n");
        return;
    }
    int number = 1;
    while (list_to_print != NULL) {
        printf("Node # %i ===================\n", number);
        print_node(list_to_print);
        printf("\n");
        list_to_print = list_to_print->next;
        ++number;
    }
}

/*
 Reverses a list.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL (no pre-conditions)
 POST:      The order of the nodes in the list passed as a parameter has been
            reversed
 RETURN:    a list of struct node that is the reverse of the list passed as a
            parameter
 */
struct node *reverse(struct node *list) {
    node *prev = NULL;
    node *next;
    while (list != NULL) {
        // complete this iteration
        next = list->next;
        list->next = prev;

        // prepare for next iteration
        prev = list;
        list = next;
    }
    // prev = list, just before it was set to its next value. So conveniently it
    // holds the return value.
    return prev;
}

/*
 Removes every node from the list which contains an airplane destined for
 the city name passed in the second parameter.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     destination_city is a pointer to a null-terminated array of char
 PRE:       NULL (no pre-conditions)
 POST:      Any struct node in the list which contains an airplane struct
            destined for the destination_city is removed from the list, and
            the memory deallocated
 RETURN:    a list of struct node that does not contain any struct node that
            has an airplane destined for the destination_city
 */
struct node *remove_from_list(struct node *list, char *destination_city) {
    // Insert your code here

    // replace this line with something appropriate
    return NULL;
}

/*
 Returns a reference to the nth node (but does not remove it ) in the
 specified list.  If the list is too short, returns NULL.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     ordinality is an integer
 PRE:       ordinality > 0
 POST:      NULL (no side-effects)
 RETURN:    IF ordinality <= length of list
            THEN a pointer to the nth node
            ELSE NULL
 */
struct node *retrieve_nth(struct node *list, int ordinality) {
    while (ordinality > 1 && list != NULL) {
        list = list->next;
        ordinality--;
    }

    return list;
}

/*
 Inserts the specified node into the specified list of nodes at the specified
 ordinality.  For example, if ordinality = 1, this is a simple prepend_node
 operation.  If ordinality = 3, then when this function is finished, the third
 node in the list will be the node_to_insert.  If the ordinality = the length
 of the list + 1, then the node_to_insert is appended to the end of the list.
 If the ordinality > 1 + length of the list, the function returns a pointer
 to the unchanged list.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     ordinality is an integer
 PRE:       ordinality > 0
 PRE:       node_to_insert is NEVER a null (it is always a correct node pointer)
 POST:      NULL (no side-effects)
 RETURN:    IF ordinality <= length of list + 1
            THEN a pointer to the list which contains the node_to_insert in the
            correct location
            ELSE a pointer to the unchanged list
 */
struct node *insert_nth(struct node *list, struct node *node_to_insert,
                        int ordinality) {
    if (list == NULL) { // empty list
        node_to_insert->next = NULL;
        return node_to_insert;
    }
    if (ordinality == 1) {
        // special case since nothing needs to point to inserted node
        node_to_insert->next == list;
        return node_to_insert;
    }

    node *start = list; // save this for returning
    while (ordinality > 2 && list->next != NULL) {
        ordinality--;
        list = list->next;
    }
    if (ordinality > 2) { // list too short
        return start;
    }
    node_to_insert->next = list->next;
    list->next = node_to_insert;
    return start;
}
