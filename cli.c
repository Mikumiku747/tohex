//Command line interface
//Daniel Selmes 2015
//This module deals with processing string input from the command line. (Not
//to be confused with processing the command line options, which happens in 
//the main program file.)

#ifndef CLI_C_
#define CLI_C_

int convertCLI(int arg1, int argc, char **argv, char *sep) {
	//Processes words off the command line and turns the into hex characters
	for (int letter = 2; argv[arg1][letter] != 0; letter++) {
		printf("%X%s", argv[arg1][letter], sep);
	}
	printf("20%s", sep);
	for(int word = arg1 + 1; word < argc; word++) {
		for (int letter = 0; argv[word][letter] != 0; letter++) {
			printf("%X%s", argv[word][letter], sep);
		}
		printf("20%s", sep);
	}
	printf("\n");
}

#endif