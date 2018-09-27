#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *dynamic_table(int *oldarray, int *arraysize) {
	int *newarray = NULL;
	newarray = (int *) malloc(*arraysize * 2 * sizeof(int));   // new array = 2x size of old array
	memcpy(newarray, oldarray, *arraysize * 2 * sizeof(int));	 // copy old array content to new array

	*arraysize *= 2;
	free(oldarray); 																					 // free old array from memory
	return newarray;
}

int main(){
	char command;
	int counter = 0;
	int * collection = malloc(2*sizeof(int)); 								 // guessing size to be 2 ints
	int insertions = 0; 																		   // keeps track of latest insertion in collection
	int size = sizeof(*collection)/sizeof(int);
	int *psize = &size;

	while(1){
		command = getchar(); 																		 //read input char by char

		if(command == 'a'){
			if(insertions == *psize){ l
				collection = dynamic_table(collection, psize);  		 // double collection size if full
			}
			collection[insertions] = counter; 										 // add counter to collection
			insertions += 1; 																			 // insertion incremented to always point to next element
		}
		else if(command == 'b'){
			//do nothing
		}
		else if(command == 'c'){
			collection[insertions] = 0;														 // set this value to zero (which is never returned)
			if(insertions == 0) {  																 // make sure that insertions is not pointing to element before 1st element
			} else {
				insertions -= 1;  																	 // make sure insertions is now pointing to the element that was just set to 0 which can be overwritten
			}
		}
		else{
			int i;
			for(i=0; i<(*psize); i++){
				if(i<1 || collection[i] != 	0) {
						printf("%i | ",collection[i]); //if anything else than abc print whole collection
					}
				else {
					//do nothing
				}
			}
			printf("\n");
			break;
		}
		counter += 1; // Here the counter is incremented instead of doing it in each if 
	}
}
