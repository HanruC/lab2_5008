#include <stdio.h>
#include <stdlib.h> // contains the functions free/malloc

typedef struct node { 
    int year;
    int wins;
    struct node* next;
}node_t;

typedef struct lst {
    int size;
    node_t* head;
}lst_t;

// create a list to store each node in the list. 
lst_t* newList(){
    lst_t* newList = (lst_t*)malloc(sizeof(lst_t));
    if (newList == NULL){
        return NULL;
    }
    newList->head =NULL;
    newList->size =0;
    return newList;
}

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

// now we need to add the node into the list, which is inserting the nodes in the front. 
//set the head of the list as the newNode 
//then newNode->next will be the list head 
void add_nodes(lst_t* list, int year, int wins){
    node_t* newNode = makeNode(wins, year, NULL);
    newNode->next = list->head; //1. new->next:NULL (list->head was set to be null at first) 2. new->next: the first makenode. 3. new->next: the second makenode. 
    list->head = newNode; // 1. list->head set to be the first makenode. 2. the second makenode. 3. the third makenode. 
    // 5 4 3 2 1 from the end insert the front. 
    list->size++;
}

node_t* build_list(int* wins, int* year, int size) { 
    node_t* head = NULL; 
    node_t* tail = NULL;
        
    for (int i = 0; i < size; i++){
        node_t* newNode = makeNode(wins[i], year[i], NULL);
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
        printf("%d, %d wins\n", pointer->year, pointer->wins);
        printList(pointer->next);
        
    }
}
void free_list(node_t* head){
    
    if (head == NULL){
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


node_t* find_year(lst_t* list, int year){
    node_t* pointer = list->head; 
    if (pointer == NULL){
        return NULL;
    }
    while (pointer != NULL){
        if (pointer->year == year){
            return pointer;
        }
        pointer = pointer->next;
    }
    return NULL;
}
// check the year stored in the list 
// compare to the year to find. 
int insert_year(lst_t* list, int year_to_find, int year, int wins){
    node_t* pointer = list->head; 
    if (pointer == NULL){
        return 0;
    }
    while (pointer != NULL){
        if (pointer->year == year_to_find){
            node_t* newNode = makeNode(wins, year, pointer->next);  // _ _ (yeartofind) (insert here) _ _ _ _ 
            pointer->next = newNode;
            list->size++;
            return 1;
        }
        pointer = pointer->next; // check the next one if not found. 
    }
    return 0;

}
//void remove_wins_helper(int wins){
    //free(wins);
//}

int remove_year(lst_t* list, int year_to_remove){
    node_t* pointer = list->head;
    node_t* prev = NULL; 

    if (pointer == NULL){
        return 0;
    }
    while (pointer!= NULL && pointer->year != year_to_remove){
        prev = pointer;
        pointer = pointer->next;
    if (pointer != NULL && pointer->year == year_to_remove){
        if (prev != NULL){
            prev->next = pointer->next;
        }else if(pointer->next == NULL){
            prev->next = NULL;
        } 
        else {
            list->head = pointer->next; //prev = null which is the first element. 
        }
        //free(pointer->wins);
        free(pointer);
        list->size--;
        return 1;
    }
    }
    return 0;
}


// TODO: Write your functions here
// There should be 1.) create_list 2.) print_list 3.) free_list
// You may create as many helper functions as you like.

int main()
{
    int test_years[5] = {2018, 2017, 2016, 2015, 2014};
    int test_wins[5] = {108, 93, 93, 78, 71};

    lst_t* newlist = newList();
    for (int i = 0; i < 5; i++) {
        add_nodes(newlist, test_years[i], test_wins[i]);
    }
    printList(newlist->head);

    int search_year = 2016;
    node_t* found_year = find_year(newlist, search_year);
    if (found_year != NULL) {

        printf("Year: %d, Wins: %d\n", found_year->year, found_year->wins);
    } else {
        printf("Year %d not found in the list.\n", search_year);
    }
    int year_to_find = 2016;
    int new_year = 2013;
    int new_wins = 15;
    int result = insert_year(newlist, year_to_find, new_year, new_wins);
    if (result == 1){
        printf("Inserted\n");
        printList(newlist->head);
    }else{
        printf("failed");
    }
    int year_to_remove = 2018; 
    int result2 = remove_year(newlist, year_to_remove);
    if (result2 == 1){
        printf("removed\n");
        printList(newlist->head);

    }else{
        printf("failed");
    }
    free_list(newlist->head);
    free(newlist);
    return 0;
}
