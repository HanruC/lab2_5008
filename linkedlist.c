#include <stdio.h>
#include <stdlib.h> // contains the functions free/malloc

typedef struct node { 
    int year;
    int wins;
    struct node* next;
}node_t;

node_t* makeNode(int wins, int year, node_t* next) {
    node_t* newNode = (node_t*)malloc(sizeof(node_t)); 
    if (newNode == NULL){
        return NULL;
    }
    newNode->wins = wins;
    newNode->year = year;
    newNode->next = next;
    return newNode; 
}

node_t* build_list(int* wins, int* years, int size) { 
        node_t* head = NULL;
        node_t* tail = NULL;
        int i;
        for (i = 0; i < size; i++){
            node_t* newNode = makeNode(years[i], wins[i], NULL);
            if (i == 0){  // head: year0 win0. tail: year0, win0. 
                head = newNode; 
                tail = newNode;
            } else {   // i = 1: head: year0, win0. tail->next: year1 win1. tail: year1 win1. 
                tail->next = newNode; 
                tail = newNode;
            }
        }
        return head;
}

void printList(node_t* head){
    if (head == NULL){
        return;
    }
    node_t* pointer = head;
    if (pointer != NULL){
        pointer = pointer->next;
        printList(pointer->next);
        printf("%d, %d wins\n", pointer->year, pointer->wins);
    }
}
void free_list(node_t* head){
    
    if (head = NULL){
        return;
    }
    node_t* pointer = head;
    while(pointer != NULL){
        node_t* storage = pointer;
        pointer = pointer->next;
        free(storage);
    }
    head = NULL;
}
/**
 

//int find_year(node_t* head){
    //node_t* pointer = head; 
    int index = 0
    int count = 0;
    while (pointer != NULL ){
        if (count == index){
            return (pointer->year);
        }
        count++;
        index = inde + 2;
        pointer = pointer->next;
    }
    

}
*/
//int find_year()
// TODO: Write your functions here
// There should be 1.) create_list 2.) print_list 3.) free_list
// You may create as many helper functions as you like.

int main()
{
    int test_years[5] = {2018, 2017, 2016, 2015, 2014};
    int test_wins[5] = {108, 93, 93, 78, 71};

    node_t* newlist = build_list(test_years, test_wins, 5);
    printList(newlist);

    // TODO: Implement me!

    return 0;
}