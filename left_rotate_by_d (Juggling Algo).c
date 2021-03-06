
// METHOD 3 (A Juggling Algorithm)

// This is an extension of method 2. Instead of moving one by one, divide the array in different sets
// where number of sets is equal to GCD of n & d and move the elements within sets.
// If GCD is 1 as is for the above example array (n = 7 and d =2), then elements will be moved within one set only, 
// we just start with temp = arr[0] and keep moving arr[I+d] to arr[I] and finally store temp at the right place.
// C program to rotate an array by d elements 
#include <stdio.h> 

void printArray(int arr[], int size);                      // function to print an array 

int gcd(int a, int b);                                     // Fuction to get gcd of a and b

void leftRotate(int arr[], int d, int n)                   // Function to left rotate arr[] of siz n by d
{ 
	int i, j, k, temp; 
	/* To handle if d >= n */
	d = d % n; 
	int g_c_d = gcd(d, n); 
	for (i = 0; i < g_c_d; i++) { 
		/* move i-th values of blocks */
		temp = arr[i]; 
		j = i; 
		while (1) { 
			k = j + d; 
			if (k >= n) 
				k = k - n; 
			if (k == i) 
				break; 
			arr[j] = arr[k]; 
			j = k; 
		} 
		arr[j] = temp; 
	} 
} 

void printArray(int arr[], int n) 
{ 
	int i; 
	for (i = 0; i < n; i++) 
		printf("%d ", arr[i]); 
} 

//Fuction to get gcd of a and b
int gcd(int a, int b) 
{ 
	if (b == 0) 
		return a; 
	else
		return gcd(b, a % b); 
} 
 
int main() 
{ 
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 }; 
	leftRotate(arr, 2, 7); 
	printArray(arr, 7); 
	getchar(); 
	return 0; 
} 

// Time complexity : O(n)
// Auxiliary Space : O(1)