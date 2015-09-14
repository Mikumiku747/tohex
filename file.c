//File interface
//Daniel Selmes 2015
//This module deals with taking a file name and converting all the characters
//in it to hex.

#ifndef FILE_C_
#define FILE_C_

int ConvertFile(char *filename, char* seperator) {
	FILE *fp;
	char ch;
	fp = fopen(filename, "r");
	if (fp == NULL) {
		fprintf(stderr, "Unable to load file [%s", filename);
		perror("]");
		return -1;
	} else {
		while ((ch = fgetc(fp)) != EOF) {
			fprintf(stdout, "%X%s", ch, seperator);
		}
	}
	printf("\n");
	return 0;
}

#endif
