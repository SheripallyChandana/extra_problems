#include <stdio.h>

void printLastLines(char* fileName, int lastLines){

	char c;
	char previousCharacter;
	int lineCount = 0;
	int noOfLines = 0;
	FILE* spSource;
	
	if((spSource = fopen(fileName, "r")) == NULL)
		return;
	
    while( (c = fgetc(spSource)) != EOF){
		if(c=='\n')
			++lineCount;
		previousCharacter = c;
    }

    if(previousCharacter != '\n'){
		++lineCount;
	}  

	if(lastLines == 1 && lineCount == 1)
		rewind(spSource);	
	else if(lastLines > lineCount){
		printf("Invalid lastLines");
		return;
	}	
	
	rewind(spSource);		
    while( (c = fgetc(spSource)) != EOF){
		if(c=='\n')
			++noOfLines;
		if(noOfLines == lineCount - lastLines)
			break;

	}

	if(lastLines == lineCount){
		rewind(spSource);
	}
		
	while((fscanf(spSource,"%c",&c)) !=EOF)
		 	fprintf(stdout,"%c",c);

	if( fclose(spSource) == EOF)
		printf("%s File Not Closed Properly", fileName);	
}

int main(){
	
	char fileName[30] = "givenFile.txt";
	int lastLines = 5;
	
	printLastLines(fileName, lastLines);
	return 0;
}