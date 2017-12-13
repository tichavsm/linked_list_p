/**
 * Main test file for modul linked_list.c
 * @author Miroslav Tichavský
 * @file main.c
 */

#include "linked_list.h"

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

int main(int argc, char *argv[])
{
    (void)argv[0];
    (void)argc;

	t_list list;
	pt_list p_list;
    p_list = &list;

	pt_element p_element;

	p_element = f_create_element("Dokončit projekt do INP","22.12.2017", false);

	f_list_init(p_list);

	f_insert_first(p_list, p_element);

	printf("Úkol %d - Jméno: %s Datum: %s Splněno: %s\n", p_list->first->data.serial_number,p_list->first->data.name,p_list->first->data.date, (p_list->first->data.complete) ? "true" : "false");

	p_element = f_create_element("Dokončit studium zdrojových souborů pro projekt do INP","14.12.2017", false);

	f_insert_first(p_list, p_element);

	printf("Úkol %d - Jméno: %s Datum: %s Splněno: %s\n", p_list->first->data.serial_number,p_list->first->data.name,p_list->first->data.date, (p_list->first->data.complete) ? "true" : "false");


	return 0;
}