#include<stdio.h>
#include"usrInt.h"
#include"calc.h"

int main () {
	printf("|=========================================|\n");
	printf("|           LAMDA - Never Mind            |\n");
	printf("|  Linear Algebraic Matrix Data Analyzer  |\n");
	printf("|            version - 1.0.1.0            |\n");
	printf("|         enter man to see manual         |\n");
	printf("|=========================================|\n\n");
	
	int code = 0, count = 1;
	do {
		double oprnd1 = 0.0, oprnd2 = 0.0, result = 0.0;
		printf("LAMDA ;-) ");
		code = getCmdCode();
		switch (code) {
			case 0:
				oprnd1 = getOprnd();
				oprnd2 = getOprnd();
				result = add(oprnd1, oprnd2);
				break;
			case 1:
				oprnd1 = getOprnd();
				oprnd2 = getOprnd();
				result = sub(oprnd1, oprnd2);
				break;
			case 2:
				oprnd1 = getOprnd();
				oprnd2 = getOprnd();
				result = tms(oprnd1, oprnd2);
				break;
			case 3:
				oprnd1 = getOprnd();
				oprnd2 = getOprnd();
				result = dvd(oprnd1, oprnd2);
				break;
			case 5:
				oprnd1 = 0;
				oprnd2 = 0;
				visitMan();
				break;
			default : break;
		}
		if (code == -1 || oprnd1 == -1 || oprnd2 == -1) {
			printf("Invalid command or argument, enter man to see user manual.\n");
			clearBuffer();
			continue;
		}
		clearBuffer();
		printf("\n%d) %lf\n\n", count, result);
		count++;
	} while (code != 4);
}

