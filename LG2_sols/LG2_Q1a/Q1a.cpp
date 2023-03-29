#include <stdio.h>

int main(void) {
	int arr[10] = { 13, 21, 2, 9, 77, 82, 11, 45, 98 };

	printf("%p\n", arr);
	printf("%p\n", arr+2);
	printf("%d\n", *(arr+2));
	printf("%d\n", *arr + 4);
	printf("%p\n", arr + 5);
	printf("%d\n", *(arr +7));

}