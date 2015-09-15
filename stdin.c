//Stdin
//Daniel Selmes 2015
//Convert input from stdin to hex characters

int ConvertStdin(char *sep) {
	char ch;
	while ((ch = fgetc(stdin)) != EOF) {
		fprintf(stdout, "%X%s", ch, sep);
	}
	printf("\n");
	return 0;
}