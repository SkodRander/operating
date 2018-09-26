#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *dynamic_table(int *oldarray, int *arraysize) { 	
	int *newarray = NULL; 	
	// new array = 2x size of old array	    		
	newarray = (int *) malloc(*arraysize * 2 * sizeof(int));
	// copy old array vals to new array
	memcpy(newarray, oldarray, *arraysize * 2 * sizeof(int)); 
	
	*arraysize *= 2;
	// free old array from memory
	free(oldarray);
	// new array is returned
	return newarray; 
}

int main(){
	char command; //init char 
	int counter = 0; // init counter 
	int * collection = malloc(2*sizeof(int)); // init array & guessing size to be 2 ints
	int insertions = 0; // keeps track of latest insertion in collection
	int size = sizeof(*collection)/sizeof(int); // size of collection
	int *psize = &size; // pointer to size

	while(1){
		command = getchar(); //read next char
	
		if(command == 'a'){ 
			if(insertions == *psize){ //double array if full
				collection = dynamic_table(collection, psize); // if a add counter to collection
			}
			collection[insertions] = counter;
			insertions += 1; // insertion incremented to always point to next element 
		}
		else if(command == 'b'){ 
			//do nothing
		}
		else if(command == 'c'){ // if c delete last element 
			collection[insertions] = 0; 
			if(insertions == 0) {  // make sure that insertions is not pointing to element before 1st element
			} else {
				insertions -= 1; //decrement which element that is pointed to, such that newest element can be overwritten (deleted)
			}
		}
		else{ //if anything else than abc print whole collection
			int i;
			for(i=0; i<(*psize); i++){
				if(i<1 || collection[i] != 	0) {
						printf("%i | ",collection[i]);
					}
				else {
					//do nothing
				}
			}
			printf("\n");
			break;
		}
		counter += 1; // always increment counter
	}
}
