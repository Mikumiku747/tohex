//Stdin
//Daniel Selmes 2015
//Convert input from stdin to hex characters

int ConvertStdin(char *sep, char *outfile) {
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
	char ch;
	while ((ch = fgetc(stdin)) != EOF) {
		fprintf(OF, "%X%s", ch, sep);
	}
	fprintf(OF, "\n");
	return 0;
}