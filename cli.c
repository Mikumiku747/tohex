//Command line interface
//Daniel Selmes 2015
//This module deals with processing string input from the command line. (Not
//to be confused with processing the command line options, which happens in 
//the main program file.)

#ifndef CLI_C_
#define CLI_C_

int convertCLI(int arg1, int argc, char **argv, char *sep, char* outfile) {
	//Processes words off the command line and turns the into hex characters
	FILE *OF;
	if (outfile != NULL) {
		OF = fopen(outfile, "w");
		if (OF == NULL) {
			fprintf(stderr, "Unable to write to file [%s", outfile);
			perror("]");
			return 1;
		}
	} else {
		OF = stdout;
	}
	for (int letter = 2; argv[arg1][letter] != 0; letter++) {
		fprintf(OF, "%X%s", argv[arg1][letter], sep);
	}
	fprintf(OF, "20%s", sep);
	for(int word = arg1 + 1; word < argc; word++) {
		for (int letter = 0; argv[word][letter] != 0; letter++) {
			fprintf(OF, "%X%s", argv[word][letter], sep);
		}
		fprintf(OF, "20%s", sep);
	}
	fprintf(OF, "\n");
}

#endif