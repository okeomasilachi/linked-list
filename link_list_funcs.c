#include "llist.h"

/**
 * list_dup - Duplicates a linked list
 * @node: The head of the linked list to duplicate
 *
 * Return: A pointer to the duplicated linked list
 */
Node *list_dup(Node *node)
{
	if (node == NULL) return NULL;
	Node *new = malloc(sizeof(Node));
	new->value = node->value;
	new->next = list_dup(node->next);
	return(new);	
}

/**
 * add_list_value_recursive - Adds corresponding values of two linked lists recursively
 * @l1: The first linked list
 * @l2: The second linked list
 *
 * Return: void
 */
void add_list_value_recurecive(Node *l1, Node *l2)
{
	if (l1 == NULL || l2 == NULL) return;
	l1->value = l1->value + l2->value;
	add_list_value_recurecive(l1->next, l2->next);
}

/**
 * add_lists_value - Adds corresponding values of two linked lists iteratively
 * @list1: The first linked list
 * @list2: The second linked list
 *
 * Return: A pointer to the modified first linked list
 */
Node *add_lists_value(Node *list1, Node *list2)
{
	if (list1 == NULL && list2 == NULL) return NULL;
	if (list1 == NULL && list2 != NULL) return list2;
	if (list2 == NULL && list1 != NULL) return list1;

	Node *cur = malloc(sizeof(Node));
	Node *oth = malloc(sizeof(Node));
	cur = list1;
	oth = list2;
	while (cur->next != NULL && oth->next != NULL)
	{
		cur->value = cur->value + oth->value;
		cur = cur->next;
		oth = oth->next;
	}
	cur->value = cur->value + oth->value;
	return (list1);
}

/**
 * merge_sorted_list - Merges two sorted linked lists into a single sorted linked list
 * @l1: The first sorted linked list
 * @l2: The second sorted linked list
 *
 * Return: A pointer to the merged sorted linked list
 */
Node *merge_sorted_list(Node *l1, Node *l2)
{
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;
	
	Node *l1cur = l1, *l2cur = l2;
	Node *new_h, *new_cur;

	if (l1cur->value <= l2cur->value)
	{
		new_h = l1cur;
		l1cur = l1cur->next;
	}
	else
	{
		new_h = l2cur;
		l2cur = l2cur->next;
	}
	new_cur = new_h;
	while (l1cur != NULL && l2cur != NULL)
	{
		if(l1cur->value <= l2cur->value)
		{
			new_cur->next = l1cur;
			new_cur = l1cur;
			l1cur = l1cur->next;
		}
		else
		{
			new_cur->next = l2cur;
			new_cur = l2cur;
			l2cur = l2cur->next;
		}
	}
	if (l1cur == NULL)
		new_cur->next = l2cur;
	else if (l2cur == NULL)
		new_cur->next = l1cur;
	
	return (new_h);	
}

/**
 * delete_list - Deletes a linked list
 * @node: The head of the linked list to delete
 *
 * Return: Always returns NULL
 */
Node *delete_list(Node *node)
{
	if (node != NULL)
	{
		delete_list(node->next);
		free(node);
	}
	return (NULL);
}


/**
 * insert_after - Inserts a new node with a given value after the first occurrence of another value in a linked list
 * @head: The head of the linked list
 * @after_value: The value after which the new node should be inserted
 * @insert_value: The value to be inserted
 *
 * Return: A pointer to the modified linked list
 */
Node *insert_after(Node *head, int after_value, int insert_value)
{
	Node *new_node = malloc(sizeof(Node));
	new_node->value = insert_value;

	if (head == NULL) return (new_node);
	else
	{
		Node *current = head;

		while (current->next != NULL)
		{
			if (current->value == after_value)
			{
				new_node->next = current->next;
				current->next = new_node;
				return(head);
			}
			else current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;

		return (head);
	}
}


/**
 * delete_duplicate - Deletes duplicate nodes from a linked list
 * @head: The head of the linked list
 *
 * Return: void
 */
void delete_duplicate(Node *head)
{
	if (head == NULL)
		return;

	Node *cur1 = head;

	while (cur1 != NULL && cur1->next != NULL)
	{
		Node *cur2 = cur1;

		while (cur2->next != NULL)
		{
			if (cur1->value == cur2->next->value)
			{
				Node *dup = cur2->next;
				cur2->next = cur2->next->next;
				free(dup);
			}
			else
			{
				cur2 = cur2->next;
			}
		}
		cur1 = cur1->next;
	}
}

/**
 * sort_list - Sorts a linked list in ascending order
 * @head: The head of the linked list
 *
 * Return: A pointer to the sorted linked list
 */
Node *sort_list(Node *head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}

	bool swapped;
	Node *current;
	Node *last_swapped = NULL;

	do
	{
		swapped = false;
		current = head;

		while (current->next != last_swapped)
		{
			if (current->value > current->next->value)
			{
				int temp = current->value;
				current->value = current->next->value;
				current->next->value = temp;
				swapped = true;
			}
			current = current->next;
		}
		last_swapped = current;
	} while (swapped);

	return head;
}

/**
 * revers_list - Reverses a linked list
 * @head: The head of the linked list
 *
 * Return: A pointer to the reversed linked list
 */
Node *revers_list(Node *head)
{
	if (head == NULL) return NULL;
	if (head->next == NULL) return head;

	Node *current = head;
	Node *next = head->next;

	current->next = NULL;

	while (next != NULL)
	{
		Node *tmp = next->next;
		next->next = current;
		current = next;
		next = tmp;
	}
	return (current);	
}

/**
 * append_list - Appends one linked list at the end of another linked list
 * @head1: The head of the first linked list
 * @head2: The head of the second linked list
 *
 * Return: A pointer to the modified first linked list
 */
Node *append_list(Node *head1, Node *head2)
{
	if (head1 == NULL) return head2;
	Node *current = head1;
	while (current->next != NULL) current = current->next;
	current->next = head2;
	return (head1);
}

/**
 * efficient_delete_match - Deletes all nodes with a given value from a linked list efficiently
 * @head: The head of the linked list
 * @del_value: The value to be deleted
 * @num_del: Pointer to the variable that stores the number of deleted nodes
 *
 * Return: A pointer to the modified linked list
 */
Node *efficient_delete_match(Node *head, int del_value, int *num_del)
{
	*num_del = 0;

	if (head == NULL) return (NULL);

	Node *cur, *tmp, *new_head;

	cur = head;
	while (cur != NULL && cur->value == del_value)
	{
		tmp = cur;
		cur = cur->next;
		free(tmp);
		*num_del = *num_del + 1;
	}
	new_head = cur;
	while (cur != NULL && cur->next != NULL)
	{
 		if (cur->next->value == del_value)
		{
			tmp = cur->next;
			cur->next = cur->next->next;
			free(tmp);
			*num_del = *num_del + 1;
		}
		else cur = cur->next;
	}
	return (new_head);
}

/**
 * delete_all_match - Deletes all nodes with a given value from a linked list
 * @head: The head of the linked list
 * @delete_value: The value to be deleted
 * @num_deleted: Pointer to the variable that stores the number of deleted nodes
 *
 * Return: A pointer to the modified linked list
 */
Node *delete_all_match(Node *head, int delete_value, int *num_deleted)
{
	Node *current = head;
	bool deleted = false;
	*num_deleted = 0;

	do
	{
		current = delete_first_match(current, delete_value, &deleted);
		if (deleted) *num_deleted = *num_deleted + 1;
	} while (deleted);
	
	return (current);
}

/**
 * delete_first_match - Deletes the first node with a given value from a linked list
 * @head: The head of the linked list
 * @delete_value: The value to be deleted
 * @was_deleted: Pointer to the variable that indicates if a node was deleted
 *
 * Return: A pointer to the modified linked list
 */
Node *delete_first_match(Node *head, int delete_value, bool *was_deleted)
{
	if (head == NULL)
	{
		*was_deleted = false;
		return (NULL);
	}
	if (head->value == delete_value)
	{
		Node *temp = head->next;
		free(head);
		*was_deleted = (true);
		return (temp);
	}
	Node *current = head->next;
	Node *prev = head;
	while (current != NULL)
	{
		if (current->value == delete_value)
		{
			prev->next = current->next;
			free(current);
			*was_deleted = true;
			return (head);
		}
		prev = current;
		current = current->next;
	}
	*was_deleted = false;
	return (head);
}

/**
 * replace_matches - Replaces all occurrences of a value with another value in a linked list
 * @node: The head of the linked list
 * @f_value: The value to be replaced
 * @r_value: The value to replace with
 *
 * Return: void
 */
void replace_matches(Node *node, int f_value, int r_value)
{
	if (node != NULL)
	{
		if (node->value == f_value)
			node->value = r_value;
		replace_matches(node->next, f_value, r_value);
	}
}

/**
 * count_matches - Counts the number of occurrences of a value in a linked list
 * @node: The head of the linked list
 * @f_value: The value to count
 *
 * Return: The number of occurrences of the value
 */
int count_matches(Node *node, int f_value)
{
	if (node == NULL) return (0);
	else if (node->value == f_value)
		return (1 + count_matches(node->next, f_value));
	else return (count_matches(node->next, f_value));

}

/**
 * is_member - Checks if a value is present in a linked list
 * @head: The head of the linked list
 * @f_value: The value to search for
 *
 * Return: true if the value is found, false otherwise
 */
bool is_member(Node *head, int f_value)
{
	if (head == NULL) return false;
	else if (head->value == f_value) return true;
	else return is_member(head->next, f_value);
}

/**
 * R_length - Computes the length of a linked list recursively
 * @node: The head of the linked list
 *
 * Return: The length of the linked list
 */
int R_lenght(Node *node)
{
	if (node == NULL) return (0);
	else return (1 + R_lenght(node->next));
}

/**
 * length - Computes the length of a linked list iteratively
 * @head: The head of the linked list
 *
 * Return: The length of the linked list
 */
int lenght(Node *head)
{
	Node *cur = head;
	int len = 0;
	while (cur != NULL)
	{
		len++;
		cur = cur->next;
	}
	return (len);
}

/**
 * delete_at_head - Deletes the node at the head of a linked list
 * @head: The head of the linked list
 *
 * Return: A pointer to the modified linked list
 */
Node *delete_at_head(Node *head)
{
	if (head == NULL)
		return (NULL);
	else
	{
		Node *to_return = head->next;
		free(head);
		return (to_return);
	}
}

/**
 * delete_at_tail - Deletes the node at the tail of a linked list
 * @head: The head of the linked list
 *
 * Return: A pointer to the modified linked list
 */
Node *delete_at_tail(Node *head)
{
	if (head == NULL)
		return (NULL);
	else if (head->next == NULL)
	{
		free(head);
		return (NULL);
	}
	else
	{
		int i, j = 0;
		Node *current = head;
		Node *ret = NULL;
		while (current->next != NULL)
		{
			ret = current;
			current = current->next;
		}
		ret->next = NULL;
		free(current);
		return (head);
	}
}

/**
 * insert_at_head - Inserts a new node with a given value at the head of a linked list
 * @head: The head of the linked list
 * @value: The value to be inserted
 *
 * Return: A pointer to the modified linked list
 */
Node *insert_at_head(Node *head, int value)
{
	Node *new_node = malloc(sizeof(Node));
	new_node->value = value;
	if (head == NULL)
		return (new_node);
	else
	{
		new_node->next = head;
		return (new_node);
	}

}

/**
 * insert_at_tail - Inserts a new node with a given value at the tail of a linked list
 * @head: The head of the linked list
 * @value: The value to be inserted
 *
 * Return: A pointer to the modified linked list
 */
Node *insert_at_tail(Node *head, int value)
{
	Node *new_node = malloc(sizeof(Node));
	new_node->value = value;
	if (head == NULL)
		return (new_node);
	else
	{
		Node *current = head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
		return (head);
	}
}

/**
 * print_node - Prints the values of a linked list
 * @head: The head of the linked list
 *
 * Return: void
 */
void print_node(Node *head)
{
	int i = 1;
	Node *current;
	current = head;

	while (current != NULL)
	{
		printf("node at %d: = %d\n", i, current->value);
		i++;
		current = current->next;
	}
	
}

 