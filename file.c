//File interface
//Daniel Selmes 2015
//This module deals with taking a file name and converting all the characters
//in it to hex.

#ifndef FILE_C_
#define FILE_C_

int ConvertFile(char *filename, char* seperator, char *outfile) {
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
	FILE *fp;
	char ch;
	fp = fopen(filename, "r");
	if (fp == NULL) {
		fprintf(OF, "Unable to load file [%s", filename);
		perror("]");
		return 1;
	} else {
		while ((ch = fgetc(fp)) != EOF) {
			fprintf(OF, "%X%s", ch, seperator);
		}
	}
	fprintf(OF, "\n");
	return 0;
}

#endif
