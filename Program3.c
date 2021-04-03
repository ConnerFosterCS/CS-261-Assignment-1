/* CS261- HW1 - Program3.c*/
/* Name: Conner Foster
 * Date: 1/17/20
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int* number, int n) {							/*Sort the array of integers of length n*/
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - 1; j++) {
			if (number[j] > number[j + 1]) {
				double temp = number[j];
				number[j] = number[j + 1];
				number[j + 1] = temp;
			}
		}
	}
}

int main() {
	srand(time(0));										/*set current time as seed for random numbers*/
	int i;
	int n = 20;											/*Declare an integer n and assign it a value of 20.*/
	int *number = (int*)malloc(n *sizeof(int));			/*Allocate memory for an array of n integers using malloc.*/

	for (i = 0; i < 20; i++) {						/*Fill this array with random numbers, using rand().*/
		number[i] = rand() % 10;
	}

	printf("\n%s", "UNSORTED: ");
	for (i = 0; i < 20; i++) {						/*Print the contents of the array.*/
		printf("%i, ", number[i]);
	} printf("\n");

	sort(number, n); 									/*Pass this array along with n to the sort() function of part a.*/

	printf("%s", "  SORTED: ");
	for (i = 0; i < 20; i++) {						/*Print the contents of the array.*/
		printf("%i, ", number[i]);
	} printf("\n\n");

	return 0;
}