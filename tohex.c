//ToHex
//Daniel Selmes 2015
//Program to convert text into series of hex characters

//Includes
#include <stdio.h>
#include <stdlib.h>

#include "cli.c"
#include "file.c"
#include "stdin.c"

//Main runtime script
int main(int argc, char **argv) {
	int useFile = 0; //Flag for if we are using a file as input
	int useStdI = 0; //Flag for if we are using the stdin as our input

	char *filename;
	char *outfile = NULL;

	char *sep = "-";

	for (int arg = 1; arg < argc; arg++) {
		if (argv[arg][0] == '-') { //Check for command line options
			switch (argv[arg][1]) {
				case 's':
				sep = argv[arg] + 2;
				break;

				case 'f':
				useFile += 1;
				filename = argv[arg] + 2;
				break;

				case 0:
				useStdI = 1;
				break;

				case 'c':
				if (useFile == 0 && useStdI == 0) {
					return convertCLI(arg, argc, argv, sep, outfile);
				} else {
					fprintf(stdout, "Bad arguments: You cannot use  -c in conjunction with -f or -\n");
					return 1;
				}
				break;

				case 'o':
				outfile = argv[arg] + 2;
				break; 

				default:
				fprintf(stderr, "Unrecognised argument: %s\n", argv[arg]);
				return 1;
				break;
			}
		}
	}

	if (useFile == 0 && useStdI == 0) {
		fprintf(stderr, "Usage: tohex [-sSeperator] -fFilename|-cMultiple Arguments|-\n");
		return 0;
	}
	if (useFile == 1 && useStdI == 1) {
		fprintf(stderr, "Error: You cannot use both -f and -\n");
		return 0;
	}
	if (useFile >= 1) {
		if (useFile > 1) {fprintf(stdout, "Warning: More than one file argument specified, using specified file.\n");}
		return ConvertFile(filename, sep, outfile);
	}
	if (useStdI == 1) {
		return ConvertStdin(sep, outfile);
	}
	return 0;
}