#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	struct node *next;
    struct node *prev;
};

struct linked_list_int{
	struct node *head;
    struct node *tail;
};

void print_list(struct linked_list_int list){
	if(list.head == (struct node*)NULL){
		printf("The head of the list is NULL.\n");
		return;
	}	

	struct node *cur = list.head->next;

	if(cur == NULL){
		printf("The list is empty.\n");
		return;
	}

    while(cur->next != NULL){
		printf("%d ", cur->val);
		cur = cur->next;
	}
    printf("\n");
    cur = list.head->next;
	while(cur->next != NULL){
		printf("%d <- %d -> %d\n", cur->prev->val, cur->val, cur->next->val);
		cur = cur->next;
	}
	printf("\n");
}

void insert_node(struct linked_list_int list, int val){	
	struct node *cur = malloc(sizeof(struct node));
	
    cur->val = val;
    cur->prev = list.tail->prev;
    cur->next = list.tail;
    // printf("!%d ", list.tail->prev->next->val);
    list.tail->prev = cur;
    list.tail->prev->prev->next = cur;
    // printf("!%d\n", list.tail->prev->prev->next->val);
    
}

void delete_node(struct linked_list_int list, int val){
	if(list.head == (struct node*)NULL){
		printf("The head of the list is NULL.\n");
		return;
	}	

	struct node *cur = list.head;
	int len = list.head->val;

	while(cur->next){
		if(cur->next->val == val){
			struct node* del = cur->next;
			cur->next = del->next;
            cur->next->prev = del->prev;
			free(del);
			break;
		}
		cur = cur->next;
	}
}

void construct_linked_list_int(struct linked_list_int *list){
	list->head = malloc(sizeof(struct node));
	list->tail = malloc(sizeof(struct node));
	
    list->head->next = list->tail;
    list->tail->prev = list->head;

    // list->head->val = -1;
    // list->tail->val = 1;
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
