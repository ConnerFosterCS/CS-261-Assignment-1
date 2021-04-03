/* CS261- HW1 - Program4.c*/
/* Name: Conner Foster
 * Date: 1/17/20
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student {
	char initials[2];
	int score;
};

void sort(struct student* students, int n) {											/*Sort n students based on their initials*/
	int i, j;
	struct student temp;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - 1; j++) {
			if (students[j].initials[0] > students[j + 1].initials[0]) {
				temp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = temp;
			}
			else if (students[j].initials[0] == students[j + 1].initials[0]) {
				if (students[j].initials[1] > students[j + 1].initials[1]) {
					temp = students[j];
					students[j] = students[j + 1];
					students[j + 1] = temp;
				}
			}
		}
	}
}

int main() {
	int i;
	int n = 10;																			/*Declare an integer n and assign it a value.*/
	struct student* students = (struct student*)malloc(sizeof(struct student)*n);		/*Allocate memory for an array of n students using malloc.*/

	srand(time(0));																		/*set current time as seed for random numbers*/
	for (i = 0; i < 10; i++) {														/*Generate random initials and scores for the n students, using rand().*/
		students[i].initials[0] = rand() % 26 + 'A';									/*generate random first initial*/
		students[i].initials[1] = rand() % 26 + 'A';									/*generate random second initial*/
		students[i].score = rand() % 101;												/*generate random score for student between 0 and 100*/
	}

	printf("\n%s\n", "UNSORTED:");
	for (i = 0; i < 10; i++) {														/*Print the contents of the array of n students.*/
		printf("%c.", students[i].initials[0]);
		printf("%c. ", students[i].initials[1]);
		printf("%i\n", students[i].score);
	} printf("\n");

	sort(students, n);																	/*Pass this array along with n to the sort() function*/

	printf("%s\n", "SORTED:");
	for (i = 0; i < 10; i++) {														/*Print the contents of the array of n students.*/
		printf("%c.", students[i].initials[0]);
		printf("%c. ", students[i].initials[1]);
		printf("%i\n", students[i].score);
	} printf("\n");
	return 0;
}