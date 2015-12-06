#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

struct testCases{

	int numbers[20];
	int  length;
	int sortedNumbers[20];

}tests[5] =
{
	{ { 50, 20, 30, 40, 10 }, 5, { 10, 20, 30, 40, 50 } },
	{ { 10, 20, 30, 50, 40 }, 5, { 10, 20, 30, 40, 50 } },
	{ { 10, 10, 10, 20, 30, 20, 30, 20, 30, 40 }, 10, { 10, 10, 10, 20, 20, 20, 30, 30, 30, 40 } },

	{ { 10, 20, 30, 40, 50 }, 5, { 10, 20, 30, 40, 50 } },
	{ { 10, 40, 30, 20, 50 }, 5, { 10, 20, 30, 40, 50 } }
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
void swapTwoElementsSortedList(NODE* head){

	if (head == NULL || head->link == NULL)
		return;
	int t;

	NODE* temp = head;
	NODE* prev;
	bool flag = false;

	while (head && head->link){

		if (head->number > head->link->number){
			prev = head;
			temp = head->link;
			while (temp && head->number > temp->number){
				prev = temp;
				temp = temp->link;
			}

			while (temp && temp->number == head->number){
				temp = temp->link;
				flag = true;
			}
			if (flag){
				t = head->number;
				head->number = temp->number;
				temp->number = t;
			}
			else{
				t = head->number;
				head->number = prev->number;
				prev->number = t;
			}

			break;
		}
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
void test(int noOfTestCases){

	int count;
	NODE* head;
	for (count = 0; count < noOfTestCases; ++count){

		head = arrayToLinkedList(tests[count].numbers, tests[count].length);
		swapTwoElementsSortedList(head);

		if (isSameArrayLinkedList(tests[count].sortedNumbers, tests[count].length,
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
