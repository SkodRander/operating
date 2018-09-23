
#include <stdio.h>
#include <stdlib.h>


//guessing the buffersize (i.e. the size that needs to be allocated
// int* buffer = malloc(buffer_size*sizeof(int)); 

// how to dynamically allocate space? what type should buffer be?
// use the dynamic tables (algo 2) 

// when array gets full, new array of double size 
// malloc the new array first and then free the old array space
int *double_array_size(int *array, int *size) {
	int *temp = NULL;
	int k;
	temp = (int *) malloc(*size * 2 * sizeof(int));
	
	for(k=0; k<*size;k++){
		temp[k] = array[k];
	}
	
	*size *= 2;
	
	free(array);
	return temp; 
}


int main(){
	char command;
	int counter = 0;
	//int collection[8] = {}; //what should be the size of the array ? think malloc
	int * collection = malloc(2*sizeof(int));
	int insertions = 0; 
	int size = sizeof(*collection)/sizeof(int);
	int *psize = &size;

	while(1){
		command = getchar();
	
		if(command == 'a'){
			if(insertions == *psize){
				collection = double_array_size(collection, psize);
			}
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
			for(i=0; i<(*psize); i++){ 
				if(collection[i] != -1){
					if(i<1 || collection[i] != 0) {
						printf("%i | ",collection[i]);
					}
				}
				else {
					//do nothing
				}

			}
			/* printf("\n %i = number of insertions", insertions);
			printf("\n %i = counter value", counter);
			printf("\n %i = size of array\n", *psize); */
			break;
		}
		counter += 1;
	}

}
