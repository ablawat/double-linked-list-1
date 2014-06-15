#include "linked-list-int.h"

int main()
{
    linked_list_uint_t **list = linked_list_uint_create();
    
    linked_list_uint_print(list);
    putchar(10);
    
    linked_list_uint_add_last(list, 1);
    linked_list_uint_print(list);
    putchar(10);
    
    linked_list_uint_add_last(list, 2);
    linked_list_uint_print(list);
    putchar(10);
    
    linked_list_uint_remove_last(list);
    linked_list_uint_print(list);
    putchar(10);
    
    linked_list_uint_add_first(list, 3);
    linked_list_uint_print(list);
    putchar(10);
    
    linked_list_uint_clear(list);
    linked_list_uint_print(list);
    putchar(10);
    
    linked_list_uint_add_last(list, 2);
    linked_list_uint_print(list);
    putchar(10);
    
    linked_list_uint_add_last(list, 2);
    linked_list_uint_print(list);
    putchar(10);
    
    linked_list_uint_remove_first(list);
    linked_list_uint_print(list);
    putchar(10);
    
    linked_list_uint_remove_last(list);
    linked_list_uint_print(list);
    putchar(10);
    
    linked_list_uint_add_last(list, 1);
    linked_list_uint_print(list);
    putchar(10);
    
    linked_list_uint_add_last(list, 2);
    linked_list_uint_print(list);
    putchar(10);
    
    linked_list_uint_add_last(list, 3);
    linked_list_uint_print(list);
    putchar(10);
    
    linked_list_uint_clear(list);
    linked_list_uint_print(list);
    putchar(10);
    
    return 0;
}
