#include <stdio.h>
#include <limits.h> // Useful for max values of types

int main (int argc, char **argv) {

	// Example Apple : Integer Promotions
	unsigned char appleCharOp1, appleCharOp2, appleCharOp3;
	unsigned char appleCharResult;
	unsigned char appleCharWrongResult;

	appleCharOp1 = 80;
	appleCharOp2 = 70;
	appleCharOp3 = 100;
	appleCharResult = appleCharOp1 * appleCharOp2 / appleCharOp3;
	appleCharWrongResult = (unsigned char)(appleCharOp1 * appleCharOp2) / appleCharOp3;

	/* Apple Explanation : uchar promoted to uint during arithmetic.
		So the final sum of appleCharResult is correct.
	*/

	// Example Banana : Casting and Conversions
	unsigned char bananaChar1 = UCHAR_MAX;
	int bananaInt1 = bananaChar1;	
	char bananaChar2 = CHAR_MIN;
	unsigned int bananaInt2 = bananaChar2;	
	char bananaChar3 = CHAR_MIN;
	int bananaInt3 = bananaChar3;	

	/* Banana Explanation: Conversion sign-extends in a sensible way. 
		The unsigned 8-bit is not sign-extended going to 16-bits.
		The signed 8-bit is sign-extended going to 16-bits.
		The unsigned 16-bit cannot old a negative value, so the
			representation of the 8-bit value changes to 255.
	*/

	// Example Cantaloupe
	unsigned int cantaloupeInt1 = UINT_MAX / 4;
	unsigned int cantaloupeInt2 = UINT_MAX / 8;
	unsigned int cantaloupeInt3 = UINT_MAX / 16;
	unsigned long long cantaloupeLongLongResult1 = cantaloupeInt1 * cantaloupeInt2 / cantaloupeInt3;
	unsigned long long cantaloupeLongLongResult2 = (unsigned long long) cantaloupeInt1 * (unsigned long long) cantaloupeInt2 / (unsigned long long) cantaloupeInt3;

}	
