#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

struct testCases{

	int nValues[20];
	int length;
	int r;
	int result;

}tests[5] =
{
	{ { 3, 5 }, 2, 5, 10 },
{ {1,2,5},3,3,3 },
{ {7,3},2 ,5,12 },
{ {1,2},2 ,2,2 },
{ {2,5},2 ,3,5 }

};

typedef struct node{
	int number;
	struct node* link;
}NODE;

NODE* arrayToLinkedList(int* numbers, int length){

	NODE* head;
	NODE* temp;

	if (length > 0)
		head = (NODE*)malloc(sizeof(NODE));
	else
		return NULL;

	head->number = numbers[length - 1];
	head->link = NULL;

	for (int i = length - 2; i >= 0; --i){
		temp = (NODE*)malloc(sizeof(NODE));
		temp->number = numbers[i];
		temp->link = head;
		head = temp;
	}
	return head;
}
void printLinkedList(NODE* head){

	while (head){
		if (head->link)
			printf("%d->", head->number);
		else
			printf("%d\n\n", head->number);
		head = head->link;
	}
}
void removeDuplicates(NODE* head){

	NODE* current = head;
	NODE* next;

	if (current == NULL)
		return;
	while (current->link != NULL){
		if (current->number == current->link->number){
			next = current->link->link;
			free(current->link);
			current->link = next;
		}
		else{
			current = current->link;
		}
	}
}
void insert(NODE** head, NODE* newNode){
	NODE* curr;

	if (*head == NULL || (*head)->number > newNode->number){
		newNode->link = *head;
		*head = newNode;
	}
	else{
		curr = *head;
		while (curr->link != NULL && curr->link->number < newNode->number){
			curr = curr->link;
		}
		newNode->link = curr->link;
		curr->link = newNode;
	}
}

int findPosition(int* nValues,int length, int r){

	NODE* head = NULL;
	NODE* temp = NULL;
	for (int i = 0; i < length; ++i)
		for (int j = 1; j <= r; ++j){
			temp = malloc(sizeof(NODE));
			temp->number = nValues[i] * j;
			temp->link = NULL;
			insert(&head, temp);
		}
		removeDuplicates(head);

	int count = 0;
	while (head){
		++count;
		if (count == r)
			return head->number;
		head = head->link;
	}
	return -1;
}
void test(int noOfTestCases){

	int count;
	for (count = 0; count < noOfTestCases; ++count){

		if (findPosition(tests[count].nValues, tests[count].length, tests[count].r) == tests[count].result)
			printf("\nPASS");
		else
			printf("\nFAIL");
	}
}

int main(void){
	test(5);
	getchar();
	return 0;
}
