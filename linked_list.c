/**
 * @file linked_list.h
 * @author Miroslav Tichavský
 * @brief One-way linked list
 */

#include "linked_list.h"

int serial_counter = 1;

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