//File interface
//Daniel Selmes 2015
//This module deals with taking a file name and converting all the characters
//in it to hex.

int ConvertFile(char *filename) {
	FILE *fp;
	char ch;
	fp = fopen(filename, "r");
	if (fp == NULL) {
		perror("Unable to open file");
		return -1;
	} else {
		return 0;
	}
}