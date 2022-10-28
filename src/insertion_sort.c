#include "insertion_sort.h"
#include "linked_list.h"

void insert_sort(linked_list *sorted,node* new_node){
    //If the list is empty, or new node is largest values >head then insert at front
    if ( !isempty(sorted) || ((sorted->head)->data >= new_node->data)) { 
        insertFront(new_node,sorted);
    } else { //Locate the node before the point of insertion
        node* current = sorted->head;
        while (current->next!=NULL && current->next->data < new_node->data){ 
            current = current->next; 
        } 
        swap(new_node,current); //insert node at the location
    } 
}
void sort(linked_list *list){
    linked_list *sorted = createLinkedList(); //create a new linked list for sorted elements
    node* current = list->head;
    while(current!=NULL){ //iterate through unsorted list
        node* next=current->next; //store 'next' for next iterration
        insert_sort(sorted, current); //insert current node into sorted list
        current=next; //Update "current" to the next node
    }
    list->head=sorted->head;
}