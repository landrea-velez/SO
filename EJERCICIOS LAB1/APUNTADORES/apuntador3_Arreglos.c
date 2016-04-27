#include <stdio.h>

int main(void){

	/*int vec[4] = {1, 2, 3, 4};
	int a = vec [0];	
	printf("Valor de a: %d\n", a);*/
	int A[6] = {2, 3, 1, 0, 9, 6};
	int *ptr1;
	int *ptr2 = &A[5];
	printf("*ptr2 = &A[5]:%d\n", *ptr2);
	ptr1 = A;
	printf("ptr1 = A:\n", ptr1);
	ptr1+=2;
	printf("ptr1+=2:\n", ptr1);
	*ptr1 = 5;
	printf("*ptr1 = 5:%d\n", *ptr1);
	ptr2--;
	printf("ptr2--:\n", ptr2);
	*(ptr2) = *ptr1 + *(ptr2-1) + *(ptr2+1);
	printf("%d = %d %d %d \n",*(ptr2), *ptr1, *(ptr2-1), *(ptr2+1));
	printf("A:  %d  %d  %d  %d  %d  %d",A[0], A[1], A[2], A[3], A[4], A[5] );

	return 0;
}




