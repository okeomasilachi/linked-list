#include "llist.h"

/**
 * list_from_env - Builds a linked list from the environmental variable
 * @env: pointer to the environmental list
 *
 * Return: Returns pointer to the linked list 
*/
env_list *list_from_env(char **env)
{
	env_list *head = NULL, *current = NULL, *new_node = NULL;
	char *variable, *separator, *name, *value;
	int i = 0, name_len;

	while (env[i] != NULL)
	{
		variable = env[i];
		separator = strchr(variable, '=');
		
		if (separator != NULL)
		{
			/* Extract the variable name */
			name_len = separator - variable;
			name = (char *)malloc((name_len + 1) * sizeof(char));
			strncpy(name, variable, name_len);
			name[name_len] = '\0';
			
			value = strdup(separator + 1);	/* Extract the variable value */
			/* Create a new env_list for the variable */
			new_node = (env_list *)malloc(sizeof(env_list));
			new_node->NAME = name;
			new_node->value = value;
			new_node->next = NULL;
			if (head == NULL) /* First env_list in the list */
			{
				head = new_node;
				current = new_node;
			}
			else /* Append the env_list to the end of the list */
			{
				current->next = new_node;
				current = new_node;
			}
		}
		i++;
	}
	return (head);
}


/**
 * free_list - free's memory allocated by list_from_env
 * @head: pointer to the head of the linked list
 *
 * Return: Void
*/
void free_list(env_list *head)
{
	env_list *current = head, *temp = NULL;
	
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp->NAME);
		free(temp->value);
		free(temp);
	}
}