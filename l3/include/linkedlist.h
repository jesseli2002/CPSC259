/*
 File:         linkedlist.h
 Purpose:      Prototypes for a linked list implementation
 Author:       Your names
 Student #s:   12345678 and 12345678
 CS Accounts:  a1a1 and b2b2
 Date:         Add the date here
 */

#pragma once

/******************************************************************
 Here lies the CPU cache. Rest in peace.
 ******************************************************************/

/* Insert your airplane structure here.  Use the correct types and names for the
 * elements! */
struct airplane {
    // Add your member elements here
};
typedef struct airplane airplane;
/* Insert your node structure here.  Use the correct types and names for the
 * elements! */
struct node {
    // Add your member elements here
    airplane plane;
    struct node *next;
};

typedef struct node node;

/* Prototypes for in-lab functions (do not add anything here) */
struct node *create_linked_list();
struct node *create_node(struct airplane plane);
struct node *prepend_node(struct node *list, struct node *new_node);
struct node *delete_node(struct node *list);

/* Prototypes for take-home functions (do not add anything here) */
int get_length(struct node *list);
struct node *delete_list(struct node *list);
void print_node(struct node *node_to_print);
void print_list(struct node *list_to_print);
struct node *reverse(struct node *list);
struct node *remove_from_list(struct node *list, char *destination_city);
struct node *retrieve_nth(struct node *list, int ordinality);
struct node *insert_nth(struct node *list, struct node *node_to_insert,
                        int ordinality);
