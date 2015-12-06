#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct testCases{

	int length;
	int startIndex;
	int endIndex;
	int numbers[20];

}tests[10] =
{
	{ 12, 4, 9, { 1, 2, 2, -18, 4, 6, -2, -3, 6, 7, -2, -13 } },
	{ 4, 0, 3, { 1, 2, 3, 4 } },
	{ 12, 0, 9, { 1, 2, 2, -1, 4, 6, -2, -3, 6, 7, -2, -13 } },
	{ 7, 0, 1, { -1, -2, -3, -4, -5, -6, -7 } },
	{ 7, 1, 2, { -1, -2, 3, -4, -5, -6, -7 } },
	{ 9, 0, 1, { -1, 1, -1, 1, -1, 1, -1, 1, -1 } },
	{ 8, 2, 6, { -2, -3, 4, -1, -2, 1, 5, -3 } },
	{ 7, 5, 6, { -7, -6, -5, -4, -3, -2, -1 } },
	{ 7, 0, 1, { 0, 0, 0, 0, 0, 0, 0 } },
	{ 12, 0, 9, { 1, 2, 2, -1, 4, 6, -2, -3, 6, 7, -2, -13 } }

};

void setIndices(int *numbers, int len, int* startIndex, int* endIndex){

	int index;
	int fixSum = numbers[0];
	int currSum = numbers[0];
	bool atleastOnce = false;

	for (index = 1; index < len; ++index){

		if (numbers[index] > currSum + numbers[index])
			currSum = numbers[index];
		else
			currSum = currSum + numbers[index];

		if (currSum > fixSum){
			fixSum = currSum;
			*endIndex = index;
		}
		else
			fixSum = fixSum;
	}

	currSum = 0;
	*startIndex = *endIndex;

	while (fixSum != currSum && *startIndex > -1){
		currSum += numbers[(*startIndex)--];
		atleastOnce = true;
	}
	if (atleastOnce)
		(*startIndex)++;


	if (*startIndex == *endIndex)

	if (*startIndex == 0)
		fixSum = fixSum + numbers[((*endIndex)++) + 1];
	else if (*endIndex == len - 1)
		fixSum = fixSum + numbers[((*startIndex)--) - 1];
	else if (numbers[*startIndex - 1] + numbers[*startIndex] >= numbers[*startIndex] + numbers[*startIndex + 1]){
		fixSum = fixSum + numbers[*startIndex - 1];
		(*startIndex)--;
	}
	else if (numbers[*startIndex - 1] + numbers[*startIndex] < numbers[*startIndex] + numbers[(*startIndex) + 1]){
		fixSum = fixSum + numbers[(*startIndex) + 1];
		(*endIndex)++;
	}
}

void test(int testCaseCount){

	int count;
	int endIndex;
	int startIndex;

	for (count = 0; count < testCaseCount; ++count){

		startIndex = 0;
		endIndex = 0;

		setIndices(tests[count].numbers, tests[count].length, &startIndex, &endIndex);

		if (tests[count].startIndex == startIndex && tests[count].endIndex == endIndex)
			printf("\nPass");
		else
			printf("\nFail");
	}
}

int main(void){
	test(10);
	getchar();
	return 0;
}
