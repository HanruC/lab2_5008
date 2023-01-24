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
        for (int i = 0; i<size; i++){
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

// TODO: Write your functions here
// There should be 1.) create_list 2.) print_list 3.) free_list
// You may create as many helper functions as you like.

int main()
{
    //int test_years[5] = {2018, 2017, 2016, 2015, 2014};
    //int test_wins[5] = {108, 93, 93, 78, 71};

    // TODO: Implement me!

    return 0;
}