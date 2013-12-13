#ifndef LINKED_LIST_INT

    typedef struct linkedListInt
    {
        Value                   value;
            
        struct linkedListInt    *next;
        struct linkedListInt    *prev;
    }
    LinkedListInt;
    
    LinkedListInt ** LinkedListIntCreate();
    int  LinkedListIntAddFirst(LinkedListInt **list, Value *value);
    int  LinkedListIntAddLast(LinkedListInt **list, Value *value);
    void LinkedListIntRemoveFirst(LinkedListInt **list);
    void LinkedListIntRemoveLast(LinkedListInt **list);
    void LinkedListIntRemove(LinkedListInt **list, LinkedListInt *toRemove);
    void LinkedListIntClear(LinkedListInt **list);
    
    void LinkedListIntPrint(LinkedListInt **list);
    
    #define LINKED_LIST_INT

#endif
