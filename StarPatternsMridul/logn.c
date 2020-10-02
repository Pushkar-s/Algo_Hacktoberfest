// C program to find log(n) using Recursion 
#include <stdio.h> 

unsigned int Log2n(unsigned int n) 
{ 
	return (n > 1) ? 1 + Log2n(n / 2) : 0; 
} 

int main() 
{ 
	unsigned int n = 32; 
	printf("%u", Log2n(n)); 
	getchar(); 
	return 0; 
}
