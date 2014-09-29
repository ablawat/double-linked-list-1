#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked-list-int.h"

void list_create_test()
{
    linked_list_int_t **list = linked_list_int_create();
    
    assert(list[0] == NULL);
    assert(list[1] == NULL);
}

void list_add_first_test()
{
    linked_list_int_t **list;
    
    int value1 = 1;
    int value2 = 2;
    
    
    list = linked_list_int_create();
    
    linked_list_int_add_first(list, value1);
    
    assert(list[0] != NULL);
    assert(list[1] != NULL);
    assert(list[0] == list[1]);
    
    assert(list[0] -> value == value1);
    assert(list[0] -> next  == NULL);
    assert(list[0] -> prev  == NULL);
    
    linked_list_int_add_first(list, value2);
    
    assert(list[0] != NULL);
    assert(list[1] != NULL);
    assert(list[0] != list[1]);
    
    assert(list[0] -> value == value2);
    assert(list[0] -> next  == list[1]);
    assert(list[0] -> prev  == NULL);
    assert(list[1] -> value == value1);
    assert(list[1] -> next  == NULL);
    assert(list[1] -> prev  == list[0]);
}

void list_add_last_test()
{
    linked_list_int_t **list;
    
    int value1 = 1;
    int value2 = 2;
    
    
    list = linked_list_int_create();
    
    linked_list_int_add_last(list, value1);
    
    assert(list[0] != NULL);
    assert(list[1] != NULL);
    assert(list[0] == list[1]);
    
    assert(list[0] -> value == value1);
    assert(list[0] -> next  == NULL);
    assert(list[0] -> prev  == NULL);
    
    linked_list_int_add_last(list, value2);
    
    assert(list[0] != NULL);
    assert(list[1] != NULL);
    assert(list[0] != list[1]);
    
    assert(list[0] -> value == value1);
    assert(list[0] -> next  == list[1]);
    assert(list[0] -> prev  == NULL);
    assert(list[1] -> value == value2);
    assert(list[1] -> next  == NULL);
    assert(list[1] -> prev  == list[0]);
}

void list_remove_first_test()
{
    linked_list_int_t **list;
    
    int value1 = 1;
    int value2 = 2;
    
    
    list = linked_list_int_create();
    
    linked_list_int_add_last(list, value1);
    linked_list_int_add_last(list, value2);
    
    linked_list_int_remove_first(list);
    
    assert(list[0] != NULL);
    assert(list[1] != NULL);
    assert(list[0] == list[1]);
    
    assert(list[0] -> value == value2);
    assert(list[0] -> next  == NULL);
    assert(list[0] -> prev  == NULL);
    
    linked_list_int_remove_first(list);
    
    assert(list[0] == NULL);
    assert(list[1] == NULL);
}

void list_remove_last_test()
{
    linked_list_int_t **list;
    
    int value1 = 1;
    int value2 = 2;
    
    
    list = linked_list_int_create();
    
    linked_list_int_add_last(list, value1);
    linked_list_int_add_last(list, value2);
    
    linked_list_int_remove_last(list);
    
    assert(list[0] != NULL);
    assert(list[1] != NULL);
    assert(list[0] == list[1]);
    
    assert(list[0] -> value == value1);
    assert(list[0] -> next  == NULL);
    assert(list[0] -> prev  == NULL);
    
    linked_list_int_remove_last(list);
    
    assert(list[0] == NULL);
    assert(list[1] == NULL);
}

void list_remove_test()
{
    linked_list_int_t **list;
    
    linked_list_int_t *list_item1;
    linked_list_int_t *list_item2;
    linked_list_int_t *list_item3;
    
    linked_list_int_t *to_remove;
    
    int value1 = 1;
    int value2 = 2;
    int value3 = 3;
    int value4 = 4;
    
    
    list = linked_list_int_create();
    
    linked_list_int_add_last(list, value1);
    linked_list_int_add_last(list, value2);
    linked_list_int_add_last(list, value3);
    linked_list_int_add_last(list, value4);
    
    
    to_remove = list[0] -> next -> next;
    linked_list_int_remove(list, to_remove);
    
    assert(list[0] != NULL);
    assert(list[1] != NULL);
    assert(list[0] != list[1]);
    
    list_item1 = list[0] -> prev;
    list_item2 = list[0];
    list_item3 = list[0] -> next;
    
    assert(list_item2 -> value == value1);
    assert(list_item2 -> next  == list_item3);
    assert(list_item2 -> prev  == list_item1);
    
    list_item1 = list_item2;
    list_item2 = list_item2 -> next;
    list_item3 = list_item3 -> next;
    
    assert(list_item2 -> value == value2);
    assert(list_item2 -> next  == list_item3);
    assert(list_item2 -> prev  == list_item1);
    
    list_item1 = list_item1 -> next;
    list_item2 = list_item2 -> next;
    list_item3 = list_item3 -> next;
    
    assert(list_item2 -> value == value4);
    assert(list_item2 -> next  == list_item3);
    assert(list_item2 -> prev  == list_item1);
    
    
    to_remove = list[0];
    linked_list_int_remove(list, to_remove);
    
    assert(list[0] != NULL);
    assert(list[1] != NULL);
    assert(list[0] != list[1]);
    
    list_item1 = list[0] -> prev;
    list_item2 = list[0];
    list_item3 = list[0] -> next;
    
    assert(list_item2 -> value == value2);
    assert(list_item2 -> next  == list_item3);
    assert(list_item2 -> prev  == list_item1);
    
    list_item1 = list_item2;
    list_item2 = list_item2 -> next;
    list_item3 = list_item3 -> next;
    
    assert(list_item2 -> value == value4);
    assert(list_item2 -> next  == list_item3);
    assert(list_item2 -> prev  == list_item1);
    
    
    to_remove = list[1];
    linked_list_int_remove(list, to_remove);
    
    assert(list[0] != NULL);
    assert(list[1] != NULL);
    assert(list[0] == list[1]);
    
    list_item1 = list[0] -> prev;
    list_item2 = list[0];
    list_item3 = list[0] -> next;
    
    assert(list_item2 -> value == value2);
    assert(list_item2 -> next  == list_item3);
    assert(list_item2 -> prev  == list_item1);
    
    
    to_remove = list[0];
    linked_list_int_remove(list, to_remove);
    
    assert(list[0] == NULL);
    assert(list[1] == NULL);
    assert(list[0] == list[1]);
}

int main()
{
    list_create_test();
    
    list_add_first_test();
    list_add_last_test();
    
    list_remove_first_test();
    list_remove_last_test();
    list_remove_test();
    
    return 0;
}
