/*
	This program finds 3 10-bit integers encoded in the unsigned 32-bit integer and then determines if the integers compose
	a valid triangle. 

	Author: Reema Amhaz
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	This function accepts a 32 bit int and then bit shifts to get the 3 integers. It then rearranges the values to find if 
	the two shorter sides are bigger than the largest side. 
	Parameters: 32 bit integer
	Return value: valid or invalid 
*/
int main() {
	unsigned int n = 0;
	scanf("%u", &n);

	int s1 = ((n >> 20) & 0x3ff) ; // finds s1 by shifting by 20 and activating bits
	int s2 = ((n >> 10) & 0x3ff) ; // finds s2 by shifting by 10 and activating bits
	int s3 = (n & 0x3ff); // finds s3 by activating bits

	if (s1 > s3) // swap the number if it isn't the largest
	{
		s3 = s1 ^ s3;
		s1 = s1 ^ s3;
		s3 = s1 ^ s3;
	}
	if (s2 > s3) // swap the number if it isn't the largest
	{
		s3 = s2 ^ s3;
		s2 = s2 ^ s3;
		s3 = s2 ^ s3;
	}

	if (s1 + s2 > s3) //checks they add up and are > s3
	{
		printf("valid\n"); //it's valid and we return out of function
		return 0;
	}
	printf("invalid"); // else they aren't and print out invalid
	return 0;
}