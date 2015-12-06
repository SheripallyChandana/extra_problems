#include<stdio.h>
#include<malloc.h>

struct testCases{
	int numbers[20];
	int  length;
	int  median;
}tests[5] =
{
{ { 10 }, 1, 10 },
{ { 10, 20 }, 2, 15 },
{{10,20,30,40,50}, 5, 30},
{{ 10, 20, 30, 40, 50, 60}, 6, 35},
{{ 30, 30, 30, 30, 30, 30 }, 6, 30}
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
int round(int nodeCount){
	if (nodeCount % 2 == 0)
		return nodeCount / 2;
	else
		return (nodeCount / 2) + 1;
}

int findMedian(NODE* head){

	NODE* median = head;
	int currentCount = 0;
	int nodeCount = 0;

	if (head){
		++nodeCount;
		++currentCount;
	}
	head = head->link;
	while (head){
		++nodeCount;
		int r = round(nodeCount);
		while (currentCount != r){
			median = median->link;
			++currentCount;
		}
		head = head->link;
	}	
	if (nodeCount % 2 == 0)
		return (median->number + median->link->number) / 2;
	else
		return median->number;
}
void test(int noOfTestCases){

	int count;
	NODE* head;

	for (count = 0; count < noOfTestCases; ++count){
		head = arrayToLinkedList(tests[count].numbers, tests[count].length);
		if (tests[count].median == findMedian(head))
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
