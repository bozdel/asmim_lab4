#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 64000000

void swap_long(long *e1, long *e2) {
	long tmp = *e2;
	*e2 = *e1;
	*e1 = tmp;
}

void swap_int(int *e1, int *e2) {
	int tmp = *e2;
	*e2 = *e1;
	*e1 = tmp;
}

void swap_short(short *e1, short *e2) {
	short tmp = *e2;
	*e2 = *e1;
	*e1 = tmp;
}

void swap_char(char *e1, char *e2) {
	char tmp = *e2;
	*e2 = *e1;
	*e1 = tmp;
}

void perm_long(long *arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = i;
	}
	long tmp = 0;
	for (int i = size - 1; i > 0; i--) {
		tmp = rand() % i;
		swap_long(&arr[i], &arr[tmp]);
	}
}

void perm_int(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = i;
	}
	int tmp = 0;
	for (int i = size - 1; i > 0; i--) {
		tmp = rand() % i;
		swap_int(&arr[i], &arr[tmp]);
	}
}

void perm_short(short *arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = i;
	}
	short tmp = 0;
	for (int i = size - 1; i > 0; i--) {
		tmp = rand() % i;
		swap_short(&arr[i], &arr[tmp]);
	}
}

void perm_char(char *arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = i;
	}
	char tmp = 0;
	for (int i = size - 1; i > 0; i--) {
		tmp = rand() % i;
		swap_char(&arr[i], &arr[tmp]);
	}
}

int measure_long(size_t size, clock_t *res) {
	long *arr = (long*)malloc(size);
	if (!arr) {
		perror("malloc");
		return -1;
	}
	if (!res) {
		fprintf(stderr, "bad pointer\n");
		free(arr);
		return -2;
	}
	printf("measuring %ld size\n", sizeof(long));
	perm_long(arr, size / sizeof(long));

	register int sum = 0;
	register int ind = 0;
	
	clock_t beg = clock();
	for (register int i = 0; i < size / sizeof(long); i++) {
		sum += arr[ind];
		ind = arr[ind];
	}
	clock_t end = clock();

	free(arr);
	*res = end - beg;
	return sum;
}

int measure_int(size_t size, clock_t *res) {
	int *arr = (int*)malloc(size);
	if (!arr) {
		perror("malloc");
		return -1;
	}
	if (!res) {
		fprintf(stderr, "bad pointer\n");
		free(arr);
		return -2;
	}
	printf("measuring %ld size\n", sizeof(int));
	perm_int(arr, size / sizeof(int));

	register int sum = 0;
	register int ind = 0;
	
	clock_t beg = clock();
	for (register int i = 0; i < size / sizeof(int); i++) {
		sum += arr[ind];
		ind = arr[ind];
	}
	clock_t end = clock();

	free(arr);
	*res = end - beg;
	return sum;
}

int measure_short(size_t size, clock_t *res) {
	short *arr = (short*)malloc(size);
	if (!arr) {
		perror("malloc");
		return -1;
	}
	if (!res) {
		fprintf(stderr, "bad pointer\n");
		free(arr);
		return -2;
	}
	printf("measuring %ld size\n", sizeof(short));
	perm_short(arr, size / sizeof(short));

	register int sum = 0;
	register int ind = 0;
	
	clock_t beg = clock();
	for (register int i = 0; i < size / sizeof(short); i++) {
		sum += arr[ind];
		ind = arr[ind];
	}
	clock_t end = clock();

	free(arr);
	*res = end - beg;
	return sum;
}

int measure_char(size_t size, clock_t *res) {
	char *arr = (char*)malloc(size);
	if (!arr) {
		perror("malloc");
		return -1;
	}
	if (!res) {
		fprintf(stderr, "bad pointer\n");
		free(arr);
		return -2;
	}
	printf("measuring %ld size\n", sizeof(char));
	perm_char(arr, size / sizeof(char));

	register int sum = 0;
	register int ind = 0;
	
	clock_t beg = clock();
	for (register int i = 0; i < size / sizeof(char); i++) {
		sum += arr[ind];
		ind = arr[ind];
	}
	clock_t end = clock();

	free(arr);
	*res = end - beg;
	return sum;
}











int measure_long_ur(size_t size, clock_t *res) {
	long *arr = (long*)malloc(size);
	if (!arr) {
		perror("malloc");
		return -1;
	}
	if (!res) {
		fprintf(stderr, "bad pointer\n");
		free(arr);
		return -2;
	}
	printf("measuring %ld size\n", sizeof(long));
	perm_long(arr, size / sizeof(long));

	register int sum = 0;
	register int ind = 0;
	
	clock_t beg = clock();
	for (register int i = 0; i < size / sizeof(long); i+=8) {
		sum += arr[ind];
		ind = arr[ind];

		sum += arr[ind];
		ind = arr[ind];

		sum += arr[ind];
		ind = arr[ind];

		sum += arr[ind];
		ind = arr[ind];

		sum += arr[ind];
		ind = arr[ind];

		sum += arr[ind];
		ind = arr[ind];

		sum += arr[ind];
		ind = arr[ind];

		sum += arr[ind];
		ind = arr[ind];
	}
	clock_t end = clock();

	free(arr);
	*res = end - beg;
	return sum;
}

int measure_int_ur(size_t size, clock_t *res) {
	int *arr = (int*)malloc(size);
	if (!arr) {
		perror("malloc");
		return -1;
	}
	if (!res) {
		fprintf(stderr, "bad pointer\n");
		free(arr);
		return -2;
	}
	printf("measuring %ld size\n", sizeof(int));
	perm_int(arr, size / sizeof(int));

	register int sum = 0;
	register int ind = 0;
	
	clock_t beg = clock();
	for (register int i = 0; i < size / sizeof(long); i+=8) {
		sum += arr[ind];
		ind = arr[ind];

		sum += arr[ind];
		ind = arr[ind];

		sum += arr[ind];
		ind = arr[ind];

		sum += arr[ind];
		ind = arr[ind];

		sum += arr[ind];
		ind = arr[ind];

		sum += arr[ind];
		ind = arr[ind];

		sum += arr[ind];
		ind = arr[ind];

		sum += arr[ind];
		ind = arr[ind];
	}
	clock_t end = clock();

	free(arr);
	*res = end - beg;
	return sum;
}

int measure_short_ur(size_t size, clock_t *res) {
	short *arr = (short*)malloc(size);
	if (!arr) {
		perror("malloc");
		return -1;
	}
	if (!res) {
		fprintf(stderr, "bad pointer\n");
		free(arr);
		return -2;
	}
	printf("measuring %ld size\n", sizeof(short));
	perm_short(arr, size / sizeof(short));

	register int sum = 0;
	register int ind = 0;
	
	clock_t beg = clock();
	for (register int i = 0; i < size / sizeof(long); i+=8) {
		sum += arr[ind];
		ind = arr[ind];

		sum += arr[ind];
		ind = arr[ind];

		sum += arr[ind];
		ind = arr[ind];

		sum += arr[ind];
		ind = arr[ind];

		sum += arr[ind];
		ind = arr[ind];

		sum += arr[ind];
		ind = arr[ind];

		sum += arr[ind];
		ind = arr[ind];

		sum += arr[ind];
		ind = arr[ind];
	}
	clock_t end = clock();

	free(arr);
	*res = end - beg;
	return sum;
}

int measure_char_ur(size_t size, clock_t *res) {
	char *arr = (char*)malloc(size);
	if (!arr) {
		perror("malloc");
		return -1;
	}
	if (!res) {
		fprintf(stderr, "bad pointer\n");
		free(arr);
		return -2;
	}
	printf("measuring %ld size\n", sizeof(char));
	perm_char(arr, size / sizeof(char));

	register int sum = 0;
	register int ind = 0;
	
	clock_t beg = clock();
	for (register int i = 0; i < size / sizeof(long); i+=8) {
		sum += arr[ind];
		ind = arr[ind];

		sum += arr[ind];
		ind = arr[ind];

		sum += arr[ind];
		ind = arr[ind];

		sum += arr[ind];
		ind = arr[ind];

		sum += arr[ind];
		ind = arr[ind];

		sum += arr[ind];
		ind = arr[ind];

		sum += arr[ind];
		ind = arr[ind];

		sum += arr[ind];
		ind = arr[ind];
	}
	clock_t end = clock();

	free(arr);
	*res = end - beg;
	return sum;
}

int measure_memset(size_t size, clock_t *res) {
	char *arr = (char*)malloc(size);
	if (!arr) {
		perror("malloc");
		return -1;
	}
	if (!res) {
		fprintf(stderr, "bad pointer\n");
		free(arr);
		return -2;
	}
	printf("measuring memset %d bytes\n", size);

	clock_t beg = clock();
	memset(arr, 1, size);
	clock_t end = clock();

	*res = end - beg;
}

/*void test() {
	int test_amount = 10;
	int *sizes = (int*)malloc(sizeof(int) * test_amount);
	for (int i = 0; i < test_amount; i++) {
		clock_t time = 0;
		measure(sizes[i], &time);
	}
}*/		

int main() {
	size_t size = SIZE;
	clock_t time = 0;
	// int sum = measure_long_ur(size, &time);
	int sum = measure_memset(size, &time);
	double secs = (double)time / CLOCKS_PER_SEC;
	printf("sum: %d, time: %f, speed: %f mb/s\n", sum, secs, SIZE / secs / 1000000);
	return 0;
}
