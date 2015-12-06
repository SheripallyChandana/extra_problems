#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

struct testCases{
	int numbers[20];
	int  length;
	int  reverse[20];
}tests[5] =
{
	{ { 10, 20, 30, 40, 50 }, 5, {50,40,30,20,10} },
	{ { 50}, 1, { 50 } },
	{{ 10, 20, 20, 20, 50 }, 5, { 50, 20, 20, 20, 10 } },
	{ { 10,10,10 }, 3, { 10,10,10} },
	{ { 10 }, 0, { 10 } }

};

typedef struct node{
	int number;
	struct node* link;
}NODE;

NODE* arrayToLinkedList(int* numbers, int length){

	NODE* head = (NODE*)malloc(sizeof(NODE));
	NODE* temp;

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
			printf("%d", head->number);
		head = head->link;
	}
}

void reverse(NODE** head){
	
	NODE* prev;
	NODE* next;

	if (*head == NULL || (*head)->link == NULL)
		return;

	prev = *head;
	next = (*head)->link;

	reverse(&next);
	prev->link->link = prev;

	prev->link = NULL;
	
	*head = next;
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

void test(int noOfTestCases){

	int count;
	NODE* head;

	for (count = 0; count < noOfTestCases; ++count){
		head = arrayToLinkedList(tests[count].numbers, tests[count].length);
		reverse(&head);
		if (isSameArrayLinkedList(tests[count].reverse, tests[count].length, head))
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
