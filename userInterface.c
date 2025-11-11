#include<stdio.h>
#include"usrInt.h"
// inputs command validates datatype and data and returns operation code
int getCmdCode () {
	char cmd [4];
	int validData = scanf("%s", cmd);
	if (!validData) {
		return -1;
	} 
	int found = 1;
	char try[6][4] = {"add", "sub", "tms", "dvd", "ext", "man"};
	for (int i = 0; i <= 5; i++) {
		for (int j = 0; j <= 3; j++) {
			if (try[i][j] != cmd[j]) {
				found = 0;
				break;
			}
		}
		if (!found) {
			found = 1;
		} else {
			return i;
		}
	}
	return -1;
}

// inputs operand, validates the datatype and returns to main
double getOprnd () {
	double oprnd = 0.0;
	int validData = scanf("%lf", &oprnd);
	if (!validData) {
		return -1;
	} else {
		return oprnd;
	}
}

//clears any leftover garbage
void clearBuffer () {
	do {
	} while (getchar() != '\n');
	return;
}

//prints user manual when called
void visitMan () {
  printf("\ncommand  operand 1  operand 2       result\n");
	printf("  add       <a>        <b>      result : a + b\n");
	printf("--sub-------<a>--------<b>------result : a - b\n");
	printf("  tms       <a>        <b>      result : a x b\n");
	printf("--dvd-------<a>--------<b>------result : a / b\n");
	printf("  ext                           result : quites the application\n");
	printf("--man---------------------------result : displays manual");
}
