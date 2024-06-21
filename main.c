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
	printf("%d is last number", (*head)->num);
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

    while(!done){
	printf("choose num\n\n\n1.\tprint currnt.\n2.\tprint previous number.\n3\t.quit.\n4.\tprint next\n\n");
	scanf("%d", &choice);
	switch(choice){
	    case 1:
		print(head);
		break;
	    case 2:
		print_back(&head);
		break;
	    case 3:
		done = true;
		break;
	    case 4:
		print_next(&head);
		break;
	    default:
		printf("choose number in the given\n");
		break;
	}
    }

    return 0;
}
