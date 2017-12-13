/**
 * @file linked_list.h
 * @author Miroslav Tichavský
 * @brief One-way linked list
 */

#include "linked_list.h"

void f_list_init(pt_list list)
{
    list->first = NULL;
    list->act = NULL;
}

int f_insert_first(pt_list list,pt_element element)
{
    if(list == NULL)
    {
        return 1;
        fprintf(stderr,"List wasn't initialized");
    }
    else if(list->first == NULL)
    {
        list->first = element;
        return 0;
    }
    else if(list->first != NULL)
    {
        element->next = list->first;
        list->first = element;

        return 0;
    }
    else
    {
        return 1;
    }
}

t_element f_copy_first(pt_list list)
{
	pt_element temp;

	if(list == NULL)
    {
        temp = NULL;
        fprintf(stderr,"List wasn't initialized");
    }
    else if(list->first == NULL)
    {
        temp = NULL;
		fprintf(stderr,"List is empty");
    }
    else if(list->first != NULL)
    {
        temp = list->first;
    }
    else
    {
        temp = NULL;
    }

	return *temp;
}

int f_first(pt_list list)
{
	int result;

	if(list == NULL)
    {
        result = 1;
        fprintf(stderr,"List wasn't initialized");
    }
    else if(list->first == NULL)
    {
        result = 1;
		fprintf(stderr,"List is empty");
    }
    else if(list->first != NULL)
    {
        list->act = list->first;
		result = 0;
    }
    else
    {
        result = 1;
    }

	return result;
}

int f_delete_firt(pt_list list)
{
	int result;
	pt_element temp;

	if(list == NULL)
    {
        result = 1;
        fprintf(stderr,"List wasn't initialized");
    }
    else if(list->first == NULL)
    {
        result = 1;
		fprintf(stderr,"List is empty");
    }
    else if(list->first != NULL)
    {
        if(list->first->next == NULL)
		{
			temp = list->first;
			list->first = NULL;
		}
		else
		{
			temp = list->first;
			list->first = temp->next;
		}

		free(temp);
    }
    else
    {
        result = 1;
    }

	return result;
}