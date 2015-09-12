//ToHex
//Daniel Selmes 2015
//Program to convert text into series of hex characters

//Includes
#include <stdio.h>
#include <stdlib.h>

#include "cli.c"

//Main runtime script
int main(int argc, char **argv) {
	int useFile = 0; //Flag for if we are using a file as input
	int useStdI = 0; //Flag for if we are using the stdin as our input

	char *sep = "-";

	for (int arg = 1; arg < argc; arg++) {
		if (argv[arg][0] == '-') { //Check for command line options
			switch (argv[arg][1]) {
				case 'c':
				if (useFile == 0 && useStdI == 0) {
					return convertCLI(arg, argc, argv, sep);
				} else {
					printf("Bad arguments: You cannot use more than one of -c -f or -\n");
				}
				break;

				default:
				fprintf(stderr, "Unrecognised argument: %s\n", argv[arg]);
				return 1;
				break;
			}
		}
	}

	if (useFile == 0 && useStdI == 0) {
		printf("Usage: tohex [-sSeperator] [-fFilename|-cMultiple Arguments|-]\n");
	}
	return 0;
}