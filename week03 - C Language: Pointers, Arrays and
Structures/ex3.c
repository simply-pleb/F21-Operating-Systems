#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	struct node *next;
};

struct linked_list_int{
	struct node *head;
};

void print_list(struct linked_list_int list){
	if(list.head == (struct node*)NULL){
		printf("The head of the list is NULL.\n");
		return;
	}	

	struct node *cur = list.head->next;
	// int len = list.head->val;

	if(cur == NULL){
		printf("The list is empty.\n");
		return;
	}

	// for(int i=0; i<len; i++){
	while(cur != NULL){
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

void insert_node(struct linked_list_int list, int val){
	struct node *prev = list.head;
	// for(int i=0; i<list.head->val; i++){
	while(prev->next != NULL){
		prev = prev->next;
	}
	
	struct node *cur = malloc(sizeof(struct node));
	prev->next = cur;
	cur->val = val;
	// list.head->val++;
}

void delete_node(struct linked_list_int list, int val){
	if(list.head == (struct node*)NULL){
		printf("The head of the list is NULL.\n");
		return;
	}	

	struct node *cur = list.head;
	int len = list.head->val;

	// for(int i=0; i<len; i++){
	while(cur->next){
		if(cur->next->val == val){
			struct node* del = cur->next;
			cur->next = del->next;
			free(del);
			// list.head->val --;
			break;
		}
		cur = cur->next;
	}
}

void construct_linked_list_int(struct linked_list_int *list){
	// list = malloc(sizeof(struct linked_list_int));
	list->head = malloc(sizeof(struct node));
}

int main()
{
	struct linked_list_int list;
	construct_linked_list_int(&list);

	insert_node(list, 1);
	insert_node(list, 9);
	insert_node(list, 2);
	insert_node(list, 3);
	insert_node(list, 6);
	insert_node(list, 4);
	insert_node(list, 8);
	insert_node(list, 5);
	insert_node(list, 7);

	printf("Initial list\n");
	print_list(list);

	printf("Remove 1\n");
	delete_node(list, 1);
	print_list(list);

	printf("Remove 7\n");
	delete_node(list, 7);
	print_list(list);

	printf("Remove 6\n");
	delete_node(list, 6);
	print_list(list);

}
