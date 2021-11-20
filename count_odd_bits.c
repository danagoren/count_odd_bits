# include <stdio.h>
# define SIZE sizeof(unsigned short int)*8

int count_odd_bits(unsigned short int); /*function declaration*/

/*the function main scans decimal numbers from the user. after scanning each number, the function prints it and the number of odd set bits in its binary representation*/
int main()
{
	unsigned short int num;
	printf("\nPlease insert a number\n");
	while (scanf("%hu", &num)!=EOF) /*while the input is acceptable*/
	{	
		printf("\nThe number %hu has %d odd bits set in its binary representation\n", num, count_odd_bits(num));
		printf("\nPlease insert another number\n");
	}
	return 0;
}

/*the function count_odd_bits counts how many odd bits are set in the binary representation of a received number that is given in a decimal representation, then returns the count*/
int count_odd_bits(unsigned short int x)
{
	int count = 0;
	int i = 1;
	int mask = 1; /* mask current binary representation: ...00001*/
	mask = mask << 1; /* mask current binary representation: ...00010*/
	/*the function starts checking bits from the second bit (mask current only set bit index=1) because we care only about the odd bits*/
	while (i<=(SIZE))
	{
		if (x == (x|mask)) /*if the current bit is set*/
		{
			count++;
		}
		mask = mask << 2; /*next time we will check the next odd bit. (if there will be another check)*/
		i+=2;
	}/*end of while*/
	return count;
}/*end of count_odd_bits*/
