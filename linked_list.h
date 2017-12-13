/**
 * @file linked_list.h
 * @author Miroslav Tichavský
 * @brief One-way linked list
 */

#include <stdio.h>
#include <stdbool.h>

typedef struct _data
{
    int serial_number;  //serial number of task
    char *name; //dynamically allocated name of task
    char date[11];   //string with date of task
    bool complete;
} t_data, *pt_data;

typedef struct _element
{
    t_data data;
    struct _element *next;
} t_element, *pt_element;

typedef struct _list
{
    struct _element *first;
    struct _element *act;
} t_list, *pt_list;

/**
 * Vytvoří prvek se zadanými parametry
 * @param list
 */
pt_element f_create_element(char *name, char date[5],bool complete);

/**
 * Initialize list
 * @param list
 */
void f_list_init(pt_list list);

/**
 * Insert element to start of the list. Element is not active.
 * @param list
 * @param element;
 * @return 0 Element was successfully inserted
 * @return 1 Error occured 
 */
int f_insert_first(pt_list list,pt_element element);

/**
 * Return value of first element
 * @param list
 * @return Value of first element
 */
t_element f_copy_first(pt_list list);

/**
 * Set first element as active.
 * @param list
 * @return 0 Element was successfully set
 * @return 1 Error occured
 */  
int f_first(pt_list list);

/**
 * Delete first element. If it was active, list is not active now.
 * @param list
 * @return 0 Element was successfully deleted
 * @return 1 Errror occured
 */
int f_delete_firt(pt_list list);

/**
 * Set following element as active. If list was inactive, error. If following element doesn't exist, list is now inactive.
 * @param list
 * @return 0 Element was successfully activated
 * @return 1 Error occured
 */
int f_succ(pt_list list);

/**
 * Determine whether list is active
 * @param list
 * @return TRUE list is active
 * @return FALSE list is not active
 */
bool f_active(pt_list list);

/**
 * Insert element behind active element
 * @param list
 * @param element
 * @return 0 Element was succesfully inserted
 * @return 1 Error occured
 */
int f_post_insert(pt_list list, pt_element element);

/**
 * Delete element behind active element
 * @param list
 * @param element
 * @return 0 Element was succesfully inserted
 * @return 1 Error occured
 */
int f_post_delete(pt_list list);

/**
 * Return active element
 * @param list
 * @return element
 * @return NULL None active elements
 */
t_element f_copy(pt_list list);