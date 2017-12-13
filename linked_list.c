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

pt_element f_create_element(char *name, char date[5],bool complete)
{
    pt_element temp;
    if((temp = malloc(sizeof(t_element))) == NULL)
    {
    	return NULL;
    }
    else
    {
    	temp->data.complete = complete;
		strcpy(temp->data.date, date);
		int lenght; //Variable to store lenght of string
		lenght = strlen(name);
		temp->data.name = (char *) malloc((lenght + 1) * sizeof(char));
		strcpy(temp->data.name, name);
		temp->data.serial_number = serial_counter;
		serial_counter++;

		return temp;
	}
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
    }
}


int main(int argc, char *argv[])
{
    char *prog = argv[0];
    (void)argc;
    
	t_list list;
	pt_list p_list;

	pt_element p_element;

	p_element = f_create_element("Dokončit projekt do INP","22.12.2017", false);

	p_list = &list;
	f_list_init(p_list);

	f_insert_first(p_list, p_element);

	printf("Úkol %d- Jméno: %s Datum: %s Splněno: %s\n", p_list->first->data.serial_number,p_list->first->data.name,p_list->first->data.date, (p_list->first->data.complete) ? "true" : "false");

	return 0;
}

