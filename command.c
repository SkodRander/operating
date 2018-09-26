#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *dynamic_table(int *oldarray, int *arraysize) { 	
	int *newarray = NULL; 	
	// new array should be 2x size of old array	    		
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
	char command; //init char which is continously changed
	int counter = 0; // counter which is always incremented
	int * collection = malloc(2*sizeof(int)); // init array, guessing size to be 2 ints
	int insertions = 0; // this keeps track of the latest insertion in the collection
	int size = sizeof(*collection)/sizeof(int); // size of the collection
	int *psize = &size;

	while(1){
		command = getchar(); //read the next char
	
		if(command == 'a'){ // if a then add the counter to collection
			if(insertions == *psize){ //double array if full
				collection = dynamic_table(collection, psize); 
			}
			collection[insertions] = counter;
			insertions += 1; // increment always points to the next element in collection
		}
		else if(command == 'b'){ 
			//do nothing
		}
		else if(command == 'c'){ // if a then delete last element 
			collection[insertions] = 0; 
			if(insertions == 0) { 
				// do nothing
			} else {
				insertions -= 1;
			}
		}
		else{ //if anything else than abc then print whole collection
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
		counter += 1; // always increment counter, so only need it once
	}
}
