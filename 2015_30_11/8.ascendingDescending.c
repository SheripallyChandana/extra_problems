#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

struct testCases{

	int numbers[20];
	int length;
	int resultNumbers[20];

}tests[5] =
{
	{ { 1, 2, 3, 7,20, 15, 10 }, 7, { 1, 2, 3, 7,10, 15, 20} },
	{ { 1, 2, 3, 7, 7, 7, 20, 20, 20, 15, 10 }, 11, { 1, 2, 3, 7,7,7, 10, 15, 20,20,20 } },
		{{11,12,13,13,15,20,19,19,19,16},10,{11,12,13,13,15,16,19,19,19,20}},
	{{3,7,8,9,10,15,14,13,12,11},10,{3,7,8,9,10,11,12,13,14,15}},
	{{10,20,30,40,50,60,59,56,55,51},10,{10,20,30,40,50,51,55,56,59,60}}	
	
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
NODE* sort(NODE* head){

	NODE* a = head;
	NODE* b = head;
	NODE* c = head;
	NODE* t = NULL;

	while (c->link && c->number <= c->link->number){
		if (c->number != c->link->number)
			b = c;
		c = c->link;
	}
	a = c->link;

	while (a->link){
		a = a->link;
	}
	if (c->number < a->number){
		b = c;
	}
	t = b->link;
	reverse(&t);

	b->link = t;	
	return head;
}

void test(int noOfTestCases){

	int count;
	for (count = 0; count < noOfTestCases; ++count){
		
		NODE* head = sort(arrayToLinkedList(tests[count].numbers, tests[count].length));
		if (isSameArrayLinkedList(tests[count].resultNumbers, tests[count].length, head))
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
