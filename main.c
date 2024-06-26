#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    struct node* prev;
    int num;
    struct node* next;
};

void print(struct node* head){
    printf("Current number: %d\n", head->num);
}

void print_back(struct node** head){
    if((*head)->prev == NULL){
	printf("%d is last number\n", (*head)->num);
    }
    else{
	*head = (*head)->prev;
	printf("Previous number: %d\n", (*head)->num);
    }
}

void print_next(struct node** head){
    if((*head)->next == NULL){
	printf("%d is last number.\n", (*head)->num);
    }
    else{
	*head = (*head)->next;
	printf("Next number: %d\n", (*head)->num);
    }
}

void insert(struct node** head, int num){
    struct node* temp = (struct node*)malloc(sizeof(struct node*));
    temp->num = num;
    if(*head == NULL){
	temp->next = *head;
    }
    else if(head != NULL){
	temp->next = *head;
	(*head)->prev = temp;
    }
    *head = temp;
}

void insert_Nth(struct node* head, int num, int n_th){
    struct node* new_node = (struct node*)malloc(sizeof(struct node*));
    new_node->num = num;
    for(int i = 0; i < n_th - 1; i++){
	head = head->next;
    }
    new_node->prev = head;
    new_node->next = head->next;
    head->next = new_node;
    head = new_node->next;
    head->prev = new_node;
}

int main(){
    struct node* head = NULL;

    int nums;
    int num;
    int choice;
    bool done = false;
    printf("How many numbers: ");
    scanf("%d", &nums);
    
    for(int i = 0; i < nums; i++){
	printf("enter number: ");
	scanf("%d", &num);
	insert(&head, num);
    }

    insert_Nth(head, 11, 3);

   while(!done){
	printf("choose num\n\n\n1.\tprint currnt.\n2.\tprint previous number.\n3\tprint next.\n4.\tquit.\n\n");
	scanf("%d", &choice);
	switch(choice){
	    case 1:
		print(head);
		break;
	    case 2:
		print_back(&head);
		break;
	    case 4:
		done = true;
		break;
	    case 3:
		print_next(&head);
		break;
	    default:
		printf("choose number in the given\n");
		break;
	}
    }

    return 0;
}
