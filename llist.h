#ifndef LLIST_H
#define LLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node
{
	int value;
	struct node *next;
} Node;

/* Print functions */
void print_node(Node *head);

/* Insertion functions */
Node *insert_at_head(Node *head, int value);
Node *insert_at_tail(Node *head, int value);

/* Deletion functions */
Node *delete_at_head(Node *head);
Node *delete_at_tail(Node *head);
Node *delete_first_match(Node *head, int delete_value, bool *was_deleted);
Node *delete_all_match(Node *head, int delete_value, int *num_deleted);
Node *efficient_delete_match(Node *head, int del_value, int *num_del);
Node *delete_list(Node *node);

/* Length functions */
int length(Node *head);
int R_length(Node *node);

/* Search functions */
bool is_member(Node *head, int f_value);
int count_matches(Node *node, int f_value);

/* Replacement function */
void replace_matches(Node *node, int f_value, int r_value);

/* List manipulation functions */
Node *append_list(Node *head1, Node *head2);
Node *reverse_list(Node *head);
Node *sort_list(Node *head);
Node *array_to_list(int arr[], int n);
void delete_duplicates(Node *head);
Node *insert_after(Node *head, int after_value, int insert_value);
Node *merge_sorted_list(Node *head1, Node *head2);
Node *add_lists_value(Node *list1, Node *list2);
void add_list_value_recursive(Node *l1, Node *l2);
Node *list_dup(Node *head);

/* environmental variable manipulation */

typedef struct env_list
{
	char *NAME;
	char *value;
	struct env_list *next;
} env_list;

env_list *list_from_env(char **env);
void free_list(env_list *head);
void free_list_recursive(env_list *head);
bool is_value(env_list *head, const char *value);
bool is_NAME(env_list *head, const char *NAME);
void print(env_list *head);
env_list *insert_env(env_list *head, char *NAME, char *value);
env_list *delete_match(env_list *head, char *delete_NAME);
char *get_env(env_list *env, const char *NAME);
void delete_duplicate(env_list *head);

#endif /* LLIST_H */