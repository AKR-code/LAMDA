#include<stdio.h>

#define EXPECTARG 2

void loop (FILE *);

int main (int argc, char *argv[]) {
	if (argc > EXPECTARG) {
		printf("Error: Too many targets\n");
		for (int i = 1; i < argc; i++) {
			printf("       %s\n", argv[i]);
		}
		return 1;
	}

	//decide bwn shell & interpreter
	FILE *inputLoc = NULL;
	if (argc == 1) {
		inputLoc = stdin;
	} else {
		inputLoc = fopen(argv[1], "r");
		if (inputLoc == NULL) {
			printf("Error: Target not found in present working directory\n");
			return 1;
		}
	}//end of deciding

	//call loop
	loop(inputLoc);
	return 0;
}
