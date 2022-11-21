#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "config.h"

void remove_file(char *fpath) {
	char *cmd = malloc(strlen(fpath) + 4);
	strcpy(cmd, "rm ");
	strcat(cmd, fpath);
	strcat(cmd, "\0");
	system(cmd);
	free(cmd);
}

char *get_user_input(CONFIG cfg) {
	char *fpath = ".tmp"; //Randomize this instead? Ex: .1h38jdf23djj23d9j2d
	char *cmd = malloc(strlen(cfg.editor) + strlen(fpath) + 2);
	strcpy(cmd, cfg.editor);
	strcat(cmd, " ");
	strcat(cmd, fpath);
	strcat(cmd, "\0");
	system(cmd);
	free(cmd);
	char *buffer;
	if(access(fpath, F_OK) != 0) {
		buffer = NULL;
		return buffer;
	}
	FILE *inp = fopen(fpath, "r");
	fseek(inp, 0, SEEK_SET);
	fseek(inp, 0, SEEK_END);
	int fsize = ftell(inp);
	fseek(inp, 0, SEEK_SET);
	if(fsize == 0) buffer = "";
	else {
		buffer = malloc(fsize);
		fread(buffer, 1, fsize, inp);
	}
	fclose(inp);
	remove_file(fpath);
	return buffer;
}