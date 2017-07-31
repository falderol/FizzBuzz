#include <stdio.h>
#include <stdlib.h>
////////////////////////////////////////////////////////////////////////////////////////////////////
// This is a simple FizzBuzz program to exercise common c skills.
// Structs were used for easy expandibility and because i wanted to refresh myself on them.
// FizzBuzz           Complete
// FizBuzzWoof        Complete
// FizzBuzzPopWhack   In Progress

struct multiplesCheck {//struct of multiple and what to print out if it is a multiple
	int multiple;
	char * outputText;
};

int fizzBuzz(int iteration, struct multiplesCheck comp, FILE * outputFile){
//Prints outputText to outputFile if the iteration is a multiple of the multiple value
	int isMatched = 0;
	////////////////////
	// If the multiple is found in the number
	// Current solution only works for single digit multiples
	int sizeOfCharIteration = 33; // remember space for terminating null
	char  charIteration[sizeOfCharIteration];
	for (int i = 0; i < sizeOfCharIteration; ++i){//makes sure unused charecters set to null
		charIteration[i] = '\0';
	}
	itoa(iteration, charIteration, 10);
	
	int sizeOfCharMultiple = 2; // remember space for terminating null
	char charMultiple[sizeOfCharMultiple];
	itoa(comp.multiple, charMultiple, 10);
	
	int stop = 0;
	for (int k = 0; stop != 1 ; ++k){// poorly written while loop with iteration
		if (charIteration[k] == charMultiple[0]){// if multiple is in number, works for single digit
			fprintf(outputFile, comp.outputText);
			isMatched +=1;
		}
		if (charIteration[k+1] == '\0'){// if the next is null, we have reached the end.
			stop = 1;
		}
	}
	////////////////////
	// If it is a multiple.
	if (iteration % comp.multiple == 0) {
		fprintf(outputFile, comp.outputText);
		isMatched +=1;
	}
	////////////////////
	// Check to see if anything is found.
	if (isMatched != 0){
		return 1;
	}
	else {
		return 0;
	}
}

int main () {
	FILE * file; //create log file
	file = fopen("fizzBuzz.txt","a+");//Opens log file.
	
	//////////////////////////////////////////////////
	// Declaration of desired FizzBuzz structs.
	// Multiples found in number currently only works for single digit multiples
	int size = 3;// ammount of FizzBuzz structs
	
	struct multiplesCheck mult[size];//Array of structs to save space
	
	mult[0].multiple = 3;
	mult[0].outputText = "Fizz";
	
	mult[1].multiple = 5;
	mult[1].outputText = "Buzz";
	
	mult[2].multiple = 7;
	mult[2].outputText = "Woof";
	
	//////////////////////////////////////////////////
	// Main logic of the program
	
	int loopAmmount;
	
	printf("To what number should FizzBuzz go: ");
	scanf("%i", &loopAmmount);
	
	for (int i = 1; i < loopAmmount +1; ++i){
	// FizzBuzz starts with 1 with 1, so we add 1 to loop ammount.
		int isMultiple = 0; //bool to see if a fizzBuzz matches
		
		for (int j = 0; j < size; ++j){
			isMultiple += fizzBuzz(i, mult[j], file);
		}
		
		if (isMultiple == 0){// If no match, print integer
			fprintf(file, "%i", i);
		}
		
		fprintf(file, "\n");
	}
	fclose(file);// close log file
	return 0;
}