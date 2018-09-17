
#include <stdio.h>
#include <stdlib.h>

int buffer_size = 100; //guessing the buffersize (i.e. the size that needs to be allocated
// int* buffer = malloc(buffer_size*sizeof(int)); 

// how to dynamically allocate space? what type should buffer be?
// use the dynamic tables (algo 2) 

// when array gets full, new array of double size 
// malloc the new array first and then free the old array space

int main(){
	char command;
	int counter = 0;
	int collection[10] = {}; //what should be the size of the array ? think malloc
	int insertions = 0; 

	while(1){
		command = getchar();	
		
		if(command == 'a'){
			collection[insertions] = counter;
			insertions += 1;
		}
		else if(command == 'b'){
			//Do nothing
		}
		else if(command == 'c'){
			collection[insertions-1] = -1;
		}
		else{
			int i;
			/* need to add logic which only prints 
			the values that we want 
			and not ALL the zeros */
			for(i=0; i<(sizeof(collection)/sizeof(int)); i++){ 
				if(collection[i] != -1){
					printf("%i | ",collection[i]);
				}
				else {
					//do nothing
				}
			}
			break;
		}
		counter += 1;
	}

}

