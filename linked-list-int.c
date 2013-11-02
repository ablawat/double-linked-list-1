#include <stdio.h>
#include <stdlib.h>
#include "value.h"
#include "linked-list-int.h"

// Tworzy listę dowiązaniową
// -------------------------
LinkedListInt ** LinkedListIntCreate()
{
    LinkedListInt **list = malloc(sizeof(LinkedListInt *) * 2);
    list[0] = NULL;
    list[1] = NULL;
    
    return list;
}

// Dodaje element na początek listy
// --------------------------------
int LinkedListIntAddFirst(LinkedListInt **list, Value *value)
{
    LinkedListInt *newValue = malloc(sizeof(LinkedListInt));
    int result;
    
    if (newValue != NULL)
    {
        newValue -> value = *value;
        
        if (list[0] == NULL)
        {
            newValue -> next = NULL;
            newValue -> prev = NULL;
            
            list[0] = newValue;
            list[1] = newValue;
        }
        else
        {
            newValue -> next = list[0];
            newValue -> prev = NULL;
            
            list[0] -> prev = newValue;
            list[0] = newValue;
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
int LinkedListIntAddLast(LinkedListInt **list, Value *value)
{
    LinkedListInt *newValue = malloc(sizeof(LinkedListInt));
    int result;
    
    if (newValue != NULL)
    {
        newValue -> value = *value;
        
        if (list[0] == NULL)
        {
            newValue -> next = NULL;
            newValue -> prev = NULL;
            
            list[0] = newValue;
            list[1] = newValue;
        }
        else
        {
            newValue -> next = NULL;
            newValue -> prev = list[1];
            
            list[1] -> next = newValue;
            list[1] = newValue;
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
void LinkedListIntRemoveFirst(LinkedListInt **list)
{
    LinkedListInt *tmpValue;
    
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
            tmpValue = list[0] -> next;
            tmpValue -> prev = NULL;
            
            free(list[0]);
            list[0] = tmpValue;
        }
    }
}

// Usuwa element z końca listy
// ---------------------------
void LinkedListIntRemoveLast(LinkedListInt **list)
{
    LinkedListInt *tmpValue;
    
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
            tmpValue = list[1] -> prev;
            tmpValue -> next = NULL;
            
            free(list[1]);
            list[1] = tmpValue;
        }
    }
}

// Usuwa element z listy
// ---------------------
void LinkedListIntRemove(LinkedListInt **list, LinkedListInt *toRemove)
{
    LinkedListInt *tmpValue;
    
    if (list[0] == toRemove)
    {
        if (list[0] -> next == NULL)
        {
            free(list[0]);
            list[0] = NULL;
            list[1] = NULL;
        }
        else
        {
            tmpValue = list[0] -> next;
            tmpValue -> prev = NULL;
            
            free(list[0]);
            list[0] = tmpValue;
        }
    }
    else
    {
        if (list[1] == toRemove)
        {
            if (list[0] -> next == NULL)
            {
                free(list[1]);
                list[0] = NULL;
                list[1] = NULL;
            }
            else
            {
                tmpValue = list[1] -> prev;
                tmpValue -> next = NULL;
                
                free(list[1]);
                list[1] = tmpValue;
            }
        }
        else
        {
            toRemove -> prev -> next = toRemove -> next;
            toRemove -> next -> prev = toRemove -> prev;
            free(toRemove);
        }
    }
}

// Usuwa wszystkie elementy listy
// ------------------------------

void LinkedListIntClear(LinkedListInt **list)
{
    LinkedListInt *tmpValue = list[0];
    LinkedListInt *toRemove;
    
    while (tmpValue != NULL)
    {
        toRemove = tmpValue;
        tmpValue = tmpValue -> next;
        free(toRemove);
    }
    
    list[0] = NULL;
    list[1] = NULL;
}

// Wyświetla zawartość listy
// -------------------------
void LinkedListIntPrint(LinkedListInt **list)
{
    LinkedListInt *tmpValue = list[0];
    
    printf("L");
    
    while (tmpValue != NULL)
    {
        printf("-|");
        printf("%d", tmpValue -> value.number);
        printf("|");
        tmpValue = tmpValue -> next;
    }
    
    putchar(32);
    
    tmpValue = list[1];
    
    while (tmpValue != NULL)
    {
        printf("|");
        printf("%d", tmpValue -> value.number);
        printf("|-");
        tmpValue = tmpValue -> prev;
    }
    
    printf("L");
}
