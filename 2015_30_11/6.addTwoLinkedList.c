#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

struct testCases{

	int numbers1[20];
	int  length1;
	int numbers2[20];
	int  length2;
	int addNumbers[20];
	int  addLength;

}tests[5] =
{
	{ { 1, 2, 3, 4, 5 }, 5, { 5, 1, 2, 3, 4 }, 5,
	{ 6,3,5,7,9 }, 5 },

	{ { 10 }, 1, { 5, 15, 25, 35, 45 }, 5,
	{ 15, 15, 25, 35, 45 }, 5 },

	{ { 10 , 2, 3}, 3, { 5, 15, 25, 35, 45 }, 5,
	{ 15, 17, 28, 35, 45 }, 5 },

	{ { 10, 20, 30, 40, 50 }, 5, { 5 }, 1,
	{ 15, 20, 30, 40, 50 }, 5 },

	{ { 10, 20, 30, 40, 50 }, 5, { 5 , 2, 3}, 3,
	{ 15, 22, 33, 40, 50 }, 5 }
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
NODE* add(NODE* head1, NODE* head2){

	NODE* head3 = NULL;
	NODE* tail = NULL;
	NODE* temp = NULL;

	while (head1 && head2){
		
		temp = (NODE*)malloc(sizeof(NODE));
		temp->number = head1->number + head2->number;
		temp->link = NULL;

		if (head3 == NULL){
			head3 = temp;
			tail  = temp;
		}
		else{
			tail->link = temp;
			tail = temp;
		}
		head1 = head1->link;
		head2 = head2->link;

	}
	while (head1){
		if (head3 == NULL){
			head3 = head1;
			tail = head1;
		}
		else{
			tail->link = head1;
			tail = head1;
		}
		head1 = head1->link;
	}
	while (head2){
		if (head3 == NULL){
			head3 = head2;
			tail = head2;
		}
		else{
			tail->link = head2;
			tail = head2;
		}
		head2 = head2->link;
	}

	return head3;
}

void test(int noOfTestCases){

	int count;
	NODE* head1;
	NODE* head2;
	NODE* head3;

	for (count = 0; count < noOfTestCases; ++count){

		head1 = arrayToLinkedList(tests[count].numbers1, tests[count].length1);
		head2 = arrayToLinkedList(tests[count].numbers2, tests[count].length2);
		head3 = add(head1, head2);

		if (isSameArrayLinkedList(tests[count].addNumbers, tests[count].addLength, head3))
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
