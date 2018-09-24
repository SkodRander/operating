#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *dynamic_table(int *oldarray, int *size) {
	int *newarray = NULL;
	int k;
	newarray = (int *) malloc(*size * 2 * sizeof(int));

	memcpy(newarray, oldarray, *size * 2 * sizeof(int));
	
	*size *= 2;
	
	free(oldarray);
	return newarray; 
}


int main(){
	char command;
	int counter = 0;
	int * collection = malloc(2*sizeof(int));
	int insertions = 0; 
	int size = sizeof(*collection)/sizeof(int);
	int *psize = &size;

	while(1){
		command = getchar();
	
		if(command == 'a'){
			if(insertions == *psize){
				collection = dynamic_table(collection, psize);
			}
			collection[insertions] = counter;
			insertions += 1;
			
		}
		else if(command == 'b'){
			//Do nothing
		}
		else if(command == 'c'){
			collection[insertions] = 0; 
			insertions -= 1;
		}
		else{
			int i;
			for(i=0; i<(*psize); i++){
				if(i<1 || collection[i] != 0) {
						printf("%i | ",collection[i]);
					}
				else {
					//do nothing
				}
				
			}
			printf("\n");
			break;
		}
		counter += 1;
	}

}
