/**
 * Main test file for modul linked_list.c
 * @author Miroslav Tichavský
 * @file main.c
 */

#include "main.h"

int serial_counter = 1;

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
	printf("Úkol %d - Jméno: %s Datum: %s Splněno: %s\n", (f_copy_first(p_list))->data.serial_number,(f_copy_first(p_list))->data.name,(f_copy_first(p_list))->data.date, ((f_copy_first(p_list))->data.complete) ? "true" : "false");
	
	p_element = f_create_element("Dokončit studium zdrojových souborů pro projekt do INP","14.12.2017", false);
	f_insert_first(p_list, p_element);
	printf("Úkol %d - Jméno: %s Datum: %s Splněno: %s\n", (f_copy_first(p_list))->data.serial_number,(f_copy_first(p_list))->data.name,(f_copy_first(p_list))->data.date, ((f_copy_first(p_list))->data.complete) ? "true" : "false");

	p_element = f_create_element("Říct Zuzance, že jí mam strašně rád","14.12.2017", false);
	f_insert_first(p_list, p_element);
	printf("Úkol %d - Jméno: %s Datum: %s Splněno: %s\n", (f_copy_first(p_list))->data.serial_number,(f_copy_first(p_list))->data.name,(f_copy_first(p_list))->data.date, ((f_copy_first(p_list))->data.complete) ? "true" : "false");

	f_first(p_list);

	printf("Úkol %d - Jméno: %s Datum: %s Splněno: %s\n", (f_copy(p_list))->data.serial_number,(f_copy(p_list))->data.name,(f_copy(p_list))->data.date, ((f_copy(p_list))->data.complete) ? "true" : "false");

	f_succ(p_list);

	printf("Úkol %d - Jméno: %s Datum: %s Splněno: %s\n", (f_copy(p_list))->data.serial_number,(f_copy(p_list))->data.name,(f_copy(p_list))->data.date, ((f_copy(p_list))->data.complete) ? "true" : "false");
	
	f_succ(p_list);

	printf("Úkol %d - Jméno: %s Datum: %s Splněno: %s\n", (f_copy(p_list))->data.serial_number,(f_copy(p_list))->data.name,(f_copy(p_list))->data.date, ((f_copy(p_list))->data.complete) ? "true" : "false");
	
	p_element = f_create_element("Dokončit projekt do INP","22.12.2017", false);
	f_post_insert(p_list, p_element);

	f_succ(p_list);
	printf("Úkol %d - Jméno: %s Datum: %s Splněno: %s\n", (f_copy(p_list))->data.serial_number,(f_copy(p_list))->data.name,(f_copy(p_list))->data.date, ((f_copy(p_list))->data.complete) ? "true" : "false");
	
	p_element = f_create_element("Dokončit projekt do INP","22.12.2017", false);
	f_insert_first(p_list, p_element);
	
	f_first(p_list);

	printf("Úkol %d - Jméno: %s Datum: %s Splněno: %s\n", (f_copy(p_list))->data.serial_number,(f_copy(p_list))->data.name,(f_copy(p_list))->data.date, ((f_copy(p_list))->data.complete) ? "true" : "false");

	f_delete_first(p_list);
	f_delete_first(p_list);
	f_delete_first(p_list);
	f_delete_first(p_list);
	f_delete_first(p_list);

	return 0;
}