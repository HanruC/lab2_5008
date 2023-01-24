#include <stdio.h>
#include <stdlib.h> // contains the functions free/malloc

typedef struct node { 
    int year;
    int wins;
    struct node* next
} node_t;

node_t* makeNode(int wins, int year, node_t* next) {
    node_t* newNode = (node_t*)malloc(sizeof(node_t)); 

    newNode->wins = wins;
    newNode->year = year;
    newNode-next = next;
    return newNode; 
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