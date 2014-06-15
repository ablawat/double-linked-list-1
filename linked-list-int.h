#ifndef LINKED_LIST_INT_H
#define LINKED_LIST_INT_H

typedef struct linked_list_uint
{
    unsigned int             value;
    
    struct linked_list_uint  *next;
    struct linked_list_uint  *prev;
}
linked_list_uint_t;

linked_list_uint ** linked_list_uint_create();

int   linked_list_uint_add_first     (linked_list_uint_t **list, unsigned int value);
int   linked_list_uint_add_last      (linked_list_uint_t **list, unsigned int value);

void  linked_list_uint_remove_first  (linked_list_uint_t **list);
void  linked_list_uint_remove_last   (linked_list_uint_t **list);
void  linked_list_uint_remove        (linked_list_uint_t **list, linked_list_uint_t *to_remove);

void  linked_list_uint_clear         (linked_list_uint_t **list);
void  linked_list_uint_print         (linked_list_uint_t **list);

#endif
