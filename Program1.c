/* CS261- HW1 - Program1.c*/
/* Name: Conner Foster
 * Date: 1/16/20
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
	
int foo(int* a, int* b, int c) {
	*a = *a + 1;										/* Increment a */
	*b = *b - 1;										/* Decrement  b */
	c = *a - *b;										/* Assign a-b to c */
	return c;											/* Return c */
}

int main() {
	srand(time(0));										/*set current time as seed for random numbers*/
	int c = 0;											/*declare thee integers a,b and c for use of function foo*/
	int x = rand() % 11;								/*declare three integers x,y and z and initialize them randomly to values in [0,10]*/
	int y = rand() % 11;
	int z = rand() % 11;
	printf("\nX = %i \nY = %i \nZ = %i\n", x, y, z);	/* Print the values of x,y and z */
	foo(&x, &y, z);										/* Call foo(), passing x,y,z as parameters */
	printf("\nX = %i \nY = %i \nZ = %i\n", x, y, z);	/* Print the values of x,y and z */
	printf("\nC foo = %i\n", c);						/* Print the value returned by foo */

	/* Is the return value different than the value of z?  Why? */
	/*Yes because the variables are passed by value not by reference*/

	return 0;
}