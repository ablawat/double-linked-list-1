#include <stdio.h>
#include <stdlib.h>
#include "linked-list-int.h"

// Tworzy listę dowiązaniową
// -------------------------
linked_list_int_t ** linked_list_int_create()
{
    linked_list_int_t **list = malloc(sizeof(linked_list_int_t *) * 2);
    list[0] = NULL;
    list[1] = NULL;
    
    return list;
}

// Dodaje element na początek listy
// --------------------------------
int linked_list_int_add_first(linked_list_int_t **list, int value)
{
    linked_list_int_t *new_item = malloc(sizeof(linked_list_int_t));
    int result;
    
    if (new_item != NULL)
    {
        new_item -> value = value;
        
        if (list[0] == NULL)
        {
            new_item -> next = NULL;
            new_item -> prev = NULL;
            
            list[0] = new_item;
            list[1] = new_item;
        }
        else
        {
            new_item -> next = list[0];
            new_item -> prev = NULL;
            
            list[0] -> prev = new_item;
            list[0] = new_item;
        }
        
        result = 0;
    }
    else
    {
        result = -1;
    }
    
    return result;
}

// Dodaje element na koniec listy
// ------------------------------
int linked_list_int_add_last(linked_list_int_t **list, int value)
{
    linked_list_int_t *new_item = malloc(sizeof(linked_list_int_t));
    int result;
    
    if (new_item != NULL)
    {
        new_item -> value = value;
        
        if (list[0] == NULL)
        {
            new_item -> next = NULL;
            new_item -> prev = NULL;
            
            list[0] = new_item;
            list[1] = new_item;
        }
        else
        {
            new_item -> next = NULL;
            new_item -> prev = list[1];
            
            list[1] -> next = new_item;
            list[1] = new_item;
        }
        
        result = 0;
    }
    else
    {
        result = -1;
    }
    
    return result;
}

// Usuwa element z początku listy
// ------------------------------
void linked_list_int_remove_first(linked_list_int_t **list)
{
    linked_list_int_t *list_item;
    
    if (list[0] != NULL)
    {
        if (list[0] -> next == NULL)
        {
            free(list[0]);
            list[0] = NULL;
            list[1] = NULL;
        }
        else
        {
            list_item = list[0] -> next;
            list_item -> prev = NULL;
            
            free(list[0]);
            list[0] = list_item;
        }
    }
}

// Usuwa element z końca listy
// ---------------------------
void linked_list_int_remove_last(linked_list_int_t **list)
{
    linked_list_int_t *list_item;
    
    if (list[0] != NULL)
    {
        if (list[0] -> next == NULL)
        {
            free(list[1]);
            list[0] = NULL;
            list[1] = NULL;
        }
        else
        {
            list_item = list[1] -> prev;
            list_item -> next = NULL;
            
            free(list[1]);
            list[1] = list_item;
        }
    }
}

// Usuwa element z listy
// ---------------------
void linked_list_int_remove(linked_list_int_t **list, linked_list_int_t *to_remove)
{
    linked_list_int_t *list_item;
    
    if (list[0] == to_remove)
    {
        if (list[0] -> next == NULL)
        {
            free(list[0]);
            list[0] = NULL;
            list[1] = NULL;
        }
        else
        {
            list_item = list[0] -> next;
            list_item -> prev = NULL;
            
            free(list[0]);
            list[0] = list_item;
        }
    }
    else
    {
        if (list[1] == to_remove)
        {
            if (list[0] -> next == NULL)
            {
                free(list[1]);
                list[0] = NULL;
                list[1] = NULL;
            }
            else
            {
                list_item = list[1] -> prev;
                list_item -> next = NULL;
                
                free(list[1]);
                list[1] = list_item;
            }
        }
        else
        {
            to_remove -> prev -> next = to_remove -> next;
            to_remove -> next -> prev = to_remove -> prev;
            free(to_remove);
        }
    }
}

// Usuwa wszystkie elementy listy
// ------------------------------

void linked_list_int_clear(linked_list_int_t **list)
{
    linked_list_int_t *list_item = list[0];
    linked_list_int_t *to_remove;
    
    while (list_item != NULL)
    {
        to_remove = list_item;
        list_item = list_item -> next;
        free(to_remove);
    }
    
    list[0] = NULL;
    list[1] = NULL;
}

// Wyświetla zawartość listy
// -------------------------
void linked_list_int_print(linked_list_int_t **list)
{
    linked_list_int_t *list_item = list[0];
    
    printf("L");
    
    while (list_item != NULL)
    {
        printf("-|");
        printf("%d", list_item -> value);
        printf("|");
        
        list_item = list_item -> next;
    }
    
    putchar(32);
    
    list_item = list[1];
    
    while (list_item != NULL)
    {
        printf("|");
        printf("%d", list_item -> value);
        printf("|-");
        
        list_item = list_item -> prev;
    }
    
    printf("L");
}
