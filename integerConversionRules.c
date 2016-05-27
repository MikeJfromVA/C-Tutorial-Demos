#include <stdio.h>
#include <limits.h> // Useful for max values of types

main (int argc, char **argv) {

	// Example Apple : Integer Promotions
	char appleCharOp1, appleCharOp2;
	char appleCharSum;
	int appleIntSum;

	appleCharOp1 = CHAR_MAX;
	appleCharOp2 = CHAR_MAX;
	appleCharSum = appleCharOp1 + appleCharOp2;
	appleIntSum = appleCharOp1 + appleCharOp2;

	// -1L > 1U
	// x86 rank promotion -1L > 1UL (Would be U->L except 32 bits signed
	//	cannot hold every value of 32 bits unsigned)
	// x86 favor unsigned: -1UL > 1UL IE MAX > 1 TRUE
	// x86_64 rank promotion -1L > 1L (U -> L)
	// True on x86, false on x86_64
	printf ("x86 -1L > 1U    %d\n",-1L > 1U);


	// SCHAR_MAX == CHAR_MAX 

	// UINT_MAX + 1
	// 1) punk promotions: none
	// 2) rank promotion: none; both ints
	// 3) sign promotion: 1 converts 
	// UINT_MAX + 1U = 0

	// INT_MAX + 1
	// No conversions
	// INT_MAX = 0111 + 1 = 1000 -> 0111 -> 1000 uh -128?
	// Maybe, but overflowing an integer is undefined behavior
	printf ("INT_MAX + 1    %d\n",INT_MAX+1);
	printf ("INT_MIN     %d\n",INT_MIN);
	printf ("INT_MAX     %d\n",INT_MAX);

	printf ("0 << 32     %d\n",0<<32);

	int x = INT_MIN;
	x = 1 + 1;
	// Warning?

}	
