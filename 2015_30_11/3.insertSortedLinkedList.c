#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

struct testCases{

	int numbers[20];
	int  length;
	int newNumber;	
	int NumberAfterInsertion[21];
	int  lengthAfterInsertion;

}tests[5] =
{ 
	{{ 10, 20, 30, 40, 50 },5,15, { 10, 15, 20, 30, 40, 50 }, 6 },

	{ { 10 }, 1, 15, { 10, 15 }, 2 },

	{{ 10, 10, 10, 10, 10 }, 5, 10, { 10,10,10,10,10,10 }, 6 },

	{{ -50, -40, -30, -20, 0, 10, 20, 30, 40, 50 }, 10, -1,
	{ -50, -40, -30, -20,-1, 0, 10, 20, 30, 40, 50}, 11 },

	{{ 10, 20, 30, 40, 50 }, 5, 15, { 10, 15, 20, 30, 40, 50 }, 6 }

};

typedef struct node{
	int number;
	struct node* link;
}NODE;

NODE* arrayToLinkedList(int* numbers, int length){

	NODE* head;
	NODE* temp = NULL;
	NODE* tail;

	if (length > 0)
		head = (NODE*)malloc(sizeof(NODE));
	else
		return NULL;

	head->number = numbers[length - 1];
	head->link = NULL;

	tail = head;

	for (int i = length - 2; i >= 0; --i){
		temp = (NODE*)malloc(sizeof(NODE));
		temp->number = numbers[i];
		temp->link = head;
		head = temp;
	}

	tail->link = head;
	return head;
}
void printLinkedList(NODE* head){

	NODE* temp = head;

	while (head->link != temp){
		if (head->link)
			printf("%d->", head->number);
		head = head->link;
	}
	printf("%d\n", head->number);

}
bool isSameArrayLinkedList(int* numbers, int length, NODE* head){

	int i;
	for (i = 0; i < length; ++i){
		if (numbers[i] != head->number)
			break;
		head = head->link;
	}
	if (i == length)
		return true;
	else
		return false;
}

NODE* InsertSortedCircularList(NODE* head, int newNumber){

	NODE* newNode = malloc(sizeof(NODE));
	NODE* curr = head;

	newNode->number = newNumber;
	newNode->link = NULL;

	if (head == NULL){
		newNode->link = newNode;
		head = newNode;
	}
	else if (head == head->link){
		if (head->number <= newNumber){
			head->link = newNode;
			newNode->link = head;
		}
		else{
			newNode->link = head;
			head->link = newNode;
		}
	}
	else if (curr->number >= newNode->number){
		while (curr->link != head)
			curr = curr->link;
		curr->link = newNode;
		newNode->link = head;
		head = newNode;
	}
	else{
		while (curr->link != head && curr->link->number < newNode->number)
			curr = curr->link;
		newNode->link = curr->link;
		curr->link = newNode;
	}
	return head;
}
void test(int noOfTestCases){
	
	int count;
	NODE* head;
	for (count = 0; count < noOfTestCases; ++count){

		head = arrayToLinkedList(tests[count].numbers, tests[count].length);
		//printLinkedList(head);

		head = InsertSortedCircularList(head, tests[count].newNumber);
		//printLinkedList(head);

		if (isSameArrayLinkedList(tests[count].NumberAfterInsertion, tests[count].lengthAfterInsertion,
			head))
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
