extern "C"{
    // Add the header files required to run your main 
    #include "linked_list.h"
    #include "insertion_sort.h"
    #include "list_queue.h"
    
}

// File for sandboxing and trying out code
int main(int argc, char **argv)
{
    node *head = NULL;
    
    linked_list *list = createLinkedList();
    node *n = createNode(4);
    insertFront(n,list);
    node *n1 = createNode(2);
    insertFront(n1,list);
    node *n2 = createNode(3);
    insertFront(n2,list);
    node *n3 = createNode(99);
    insertFront(n3,list);
    node *n4 = createNode(9);
    insertFront(n4,list);
    node *n5 = createNode(18);
    insertFront(n5,list);
    printLL(list);
    insertionSort(list);
    printLL(list);

    queue *q = malloc(sizeof(queue));
    init_queue(q);
    printf("Size: %d\n",q->size);
    enqueue(q,6);
    enqueue(q,4);
    enqueue(q,8);
    print_queue(q);
    dequeue(q);    
    print_queue(q);
    dequeue(q);    
    print_queue(q);
    dequeue(q);    
    print_queue(q);


    test1();
    test2();
    test3();
    return 0;
}