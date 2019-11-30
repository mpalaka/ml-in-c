//mohana palaka
//29.11.19
//this is a program to read a .csv / .data file and write it into a 2d array
//particularly for iris dataset
//the conditional attributes are stored in a 2d array and the decision attribute(we are considering only one) is stored in a 1d array

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void print_2d(float data[][4], int rows, int cols){	//a function to print the values in a 2d matrix

	int i,j = 0;

	for(i = 0; i < rows; i++){
	
		for(j = 0; j < cols; j++){
		
			printf("%f\t", data[i][j]);
		}
		printf("\n");
	}
}


void print_strarr(char arr[][30], int rows){	//a function to print the values in a array of srings

	int i = 0;

	for(i = 0; i < 150; i++){
	
		printf("%s", arr[i]);
	}
}

int main(void){
	//150 rows and 4 columns because this is specific to iris dataset
	float datapoints[150][4];	//conditional attributes
	char d_class[150][30];	//for the decision attribute (array of strings)
	FILE *fptr;	//file pointer
	char filename[] = "iris.data";	//name of the dataset to be opened
	char* line = NULL;
	size_t len = 0;
	ssize_t read;
	const char* token;	//character pointer to store the tokenized string
	char val[20];	//string to store the token	
	int i,j = 0;

	fptr = fopen(filename, "r");	//open the file for reading

	if(fptr == NULL){
	
		printf("Error opening file! :< \n");
		exit(0);
	}

	while((read = getline(&line, &len, fptr)) != -1){
	
		//printf("Retrieved line of length %zu:\n", read);
		//printf("%s", line);
		
		char* tmp = strdup(line);
		token = strtok(line, ",");
		j = 0;
		while(token != NULL){
		
			//val = *token;
			//printf("%s\n", token);
			if(j < 4){	//first 4 tokens are conditional attributes
				datapoints[i][j] = strtof(token, NULL);
			}
			else{
				strcpy(d_class[i], token);
			}

			token = strtok(NULL, ",");
			j++;
		}
		i++;

	}

	fclose(fptr);	//close file
	if(line){
		free(line);
	}
	
	print_2d(datapoints, 150, 4);
	print_strarr(d_class, 150);

}
