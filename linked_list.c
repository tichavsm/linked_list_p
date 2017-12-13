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
        fprintf(stderr,"List wasn't initialized\n");
    }
    else if(list->first == NULL)
    {
        list->first = element;
		element->next = NULL;
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

pt_element f_copy_first(pt_list list)
{
	pt_element temp;

	if(list == NULL)
    {
        temp = NULL;
        fprintf(stderr,"List wasn't initialized\n");
    }
    else if(list->first == NULL)
    {
        temp = NULL;
		fprintf(stderr,"List is empty\n");
    }
    else if(list->first != NULL)
    {
        temp = list->first;
    }
    else
    {
        temp = NULL;
    }
	    return temp;
}

int f_first(pt_list list)
{
	int result;

	if(list == NULL)
    {
        result = 1;
        fprintf(stderr,"List wasn't initialized\n");
    }
    else if(list->first == NULL)
    {
        result = 1;
		fprintf(stderr,"List is empty\n");
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

int f_delete_first(pt_list list)
{
	int result;
	pt_element temp;

	if(list == NULL)
    {
        result = 1;
        fprintf(stderr,"List wasn't initialized\n");
    }
    else if(list->first == NULL)
    {
        result = 1;
		fprintf(stderr,"List is empty\n");
    }
    else if(list->first != NULL)
    {
        if(list->first->next == NULL)
		{
			if(list->act == list->first)
			{
				list->act = NULL;
			}
			else
			{;}

			temp = list->first;
			list->first = NULL;
		}
		else
		{
			temp = list->first;
			list->first = temp->next;
		}

		free(temp);
		result = 0;
    }
    else
    {
        result = 1;
    }

	return result;
}

int f_succ(pt_list list)
{
	int result;

	if(list == NULL)
    {
        result = 1;
        fprintf(stderr,"List wasn't initialized\n");
    }
    else if(list->act == NULL)
    {
        result = 1;
		fprintf(stderr,"List is inactive\n");
    }
    else if(list->act->next == NULL)
    {
		list->act = NULL;
		result = 1;
    }
    else
    {
		list->act = list->act->next;
        result = 0;
    }

	return result;
}

bool f_active(pt_list list)
{
    bool result;

	if(list->act != NULL)
    {
        result = true;
    }
    else
    {
        result = false;
    }

	return result;
}

int f_post_insert(pt_list list, pt_element element)
{
    int result;

	if(list == NULL)
    {
        result = 1;
        fprintf(stderr,"List wasn't initialized\n");
    }
    else if(list->act == NULL)
    {
        result = 1;
		fprintf(stderr,"List is inactive\n");
    }
    else if(list->act->next == NULL)
    {
		list->act->next = element;
		result = 0;
    }
    else
    {
        pt_element temp;
		temp = list->act->next;
        list->act->next = element;
        element->next = temp;
        result = 0;
    }
	return result;
}

int f_post_delete(pt_list list)
{
    int result;

	if(list == NULL)
    {
        result = 1;
        fprintf(stderr,"List wasn't initialized\n");
    }
    else if(list->act == NULL)
    {
        result = 1;
		fprintf(stderr,"List is inactive\n");
    }
    else if(list->act->next == NULL)
    {
		result = 1;
        fprintf(stderr,"Nothing to delete\n");
    }
    else
    {
        pt_element temp;

        if(list->act->next->next == NULL)
        {
		    temp = list->act->next;
            list->act->next = NULL;
            result = 0;
        }
        else
        {
            temp = list->act->next;
            list->act->next = temp->next;
            result = 0;
        }
        free(temp);
    }
	return result;
}

pt_element f_copy(pt_list list)
{
	pt_element temp;

	if(list == NULL)
    {
        temp = NULL;
        fprintf(stderr,"List wasn't initialized\n");
    }
    else if(list->first == NULL)
    {
        temp = NULL;
		fprintf(stderr,"List is empty\n");
    }
    else if(list->act == NULL)
    {
        temp = NULL;
		fprintf(stderr,"List is inactive\n");
    }
    else
    {
        temp = list->act;
    }

	return temp;
}