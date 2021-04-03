/* CS261- HW1 - Program2.c*/
/* Name: Conner Foster
 * Date: 1/16/20
 * Solution description:
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include <time.h>

struct student{
	char initials[2];
	int score;
};

struct student* allocate(){
	struct student *ptr = (struct student*)malloc(sizeof(struct student)*10);;			/*allocate memory for ten students*/
	return ptr;																			/*return the pointer*/
}

void generate(struct student* students){
	srand(time(0));												/*set current time as seed for random numbers*/
	int i = 0;

	for (i = 0; i < 10; i++){
		students[i].initials[0] = rand() % 26 + 'A';			/*generate random first initial*/
		students[i].initials[1] = rand() % 26 + 'A';			/*generate random last initial*/
		students[i].score = rand() % 101;						/*generate random score for student between 0 and 100*/
	}
}

void output(struct student* students){
	int i;
	for (i = 0; i < 10; i++){
		printf("%i. %c%c  %i\n", i+1, students[i].initials[0], students[i].initials[1], students[i].score);
	}
}

void summary(struct student* students){							/*Compute and print the minimum, maximum and average scores of the ten students*/
	int avg = 0;
	int max = 0;
	int min = 100;
	int i;

	/*MINIMUM*/
	for (i = 0; i < 10; i++){
		if (students[i].score < min) {
			min = students[i].score;
		}
	}
	/*MAXIMUM*/
	for(i = 0; i < 10; i++){
		if (students[i].score > max) {
			max = students[i].score;
		}
	}
	/*AVERAGE*/
	for (i = 0; i < 10; i++) {
		avg = (avg + students[i].score);
	} avg = avg / 10;
	
	/*OUTPUT*/
	printf("\nMINIMUM: %i\n", min);
	printf("MAXIMUM: %i\n", max);
	printf("AVERAGE: %i\n", avg);
}

void deallocate(struct student* students){
	free(students);													/*Deallocate memory from students*/
}

int main(){
    struct student* students = NULL;
	students = allocate();											/*call allocate*/
	generate(students);												/*call generate*/
	output(students);												/*call output*/
	summary(students);												/*call summary*/
	deallocate(students);											/*call deallocate*/

    return 0;
}