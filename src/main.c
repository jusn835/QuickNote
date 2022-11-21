#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "style.h"
#include "datetime.h"
#include "io.h"

int err(int code) {
	printf("\x1b[33mqn:\x1b[0m \x1b[31merr%d:\x1b[0m ", code);
	if(code == 355) printf("Operating system not supported.");
	else if(code == 356) printf("No output file specified.");
	else if(code == 357) printf("Too many arguments.");
	else if(code == 358) printf("File already exists.");
	else if(code == 359) printf("File creation aborted.");
	else if(code == 360) printf("Nothing was typed.");
	printf("\n");
	return code;
}

void help(char *cfpath) {
	printf("\x1b[33mQuickNote\x1b[0m by Justin Roach (GPLv3)\n\n");
	printf("  \x1b[33mUsage:\x1b[0m\n");
	printf("    qn *file\n\n");
	printf("  \x1b[33mConfiguration File:\x1b[0m\n    %s\n\n", cfpath);
	printf("  \x1b[33mFeedback:\x1b[0m\n");
	printf("    jusn835@protonmail.com\n\n");
}

int make_note(CONFIG cfg, char *filepath) {
	char head[51];
	strcpy(head, format_timedate(cfg.style, cfg.miltime));
	strcat(head, "\0");
	char *body_unformatted = get_user_input(cfg);
	if(body_unformatted == NULL) return 1;
	if(strlen(body_unformatted) == 0) return 2;
	unsigned int num_newlines = 0;
	for(int i = 0; i < strlen(body_unformatted); i += 1) {
		if(body_unformatted[i] == '\n') num_newlines += 1;
	}
	int b_size = strlen(body_unformatted) + num_newlines + 1;
	char body[b_size];
	body[0] = '\t';
	int bu_inc = 0;
	for(int i = 1; i <= b_size; i += 1) {
		body[i] = body_unformatted[bu_inc];
		if(body[i] == '\n') {
			i += 1;
			body[i] = '\t';
		}
		bu_inc += 1;
	}
	FILE *out;
	if(cfg.appendmode == 0) out = fopen(filepath, "w");
	else if(cfg.appendmode == 1) {
		out = fopen(filepath, "a");
		fseek(out, 0, SEEK_SET);
		fseek(out, 0, SEEK_END);
		if(ftell(out) != 0) {
			char *space = "\n\n";
			fwrite(space, 1, strlen(space), out);
		}
	}
	fwrite(head, 1, strlen(head), out);
	fwrite(body, 1, strlen(body), out);
	fclose(out);
	return 0;
}

char *init(void) {
	char *username = getlogin();
	#if __linux__
	char *cfpath = malloc(strlen(username) + 13);
	strcpy(cfpath, "/home/");
	strcat(cfpath, username);
	strcat(cfpath, "/.qnrc\0");
	return cfpath;
	#elif __APPLE__
	char *cfpath = malloc(strlen(username) + 14);
	strcpy(cfpath, "/Users/");
	strcat(cfpath, username);
	strcat(cfpath, "/.qnrc\0");
	return cfpath;
	#elif _WIN32
	char *cfpath = malloc(strlen(username) + 16);
	strcpy(cfpath, "C:/Users/");
	strcat(cfpath, username);
	strcat(cfpath, "/.qnrc\0");
	return cfpath;
	#elif _WIN64
	char *cfpath = malloc(strlen(username) + 16);
	strcpy(cfpath, "C:/Users/");
	strcat(cfpath, username);
	strcat(cfpath, "/.qnrc\0");
	return cfpath;
	#elif __ANDROID__
	#endif
}

int main(int argc, char *argv[]) {
	char cfpath[51];
	strcpy(cfpath, init());
	strcat(cfpath, "\0");
	CONFIG cfg = get_config_from_file(cfpath);
	if(argc < 2) return err(356);
	else if(argc > 2) return err(357);
	else if(strcmp(argv[1], "help") == 0) {
		help(cfpath);
		return 0;
	}
	else if(access(argv[1], F_OK) == 0) {
		if(cfg.appendmode == 0) return err(358);
	}
	int ec = make_note(cfg, argv[1]);
	if(ec == 1) return err(359);
	else if(ec == 2) return err(360);
	return 0;
}