#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "config.h"

char *get_setting(char *line, char *s_id) {
	int size = strlen(line) - (strlen(s_id) + 1) + 1;
	char setting[size];
	int i = 0;
	for(int j = strlen(s_id) + 1; j <= strlen(line); j += 1) {
		setting[i] = line[j];
		i += 1;
	}
	strcat(setting, "\0");
	char *s = setting;
	return s;
}

int verify_setting_id(char *line, char *s_id) {
	if(strstr(line, s_id) != NULL) {
		if(strlen(line) > strlen(s_id) + 1) {
			int i = 0;
			while(i < strlen(s_id)) {
				if(line[i] != s_id[i]) return 1;
				i += 1;
			}
			if(line[i] != '=') return 1;
			return 0;
		}
	}
	return 1;
}

void init_config_file(char *filepath) {
	FILE *config_file = fopen(filepath, "w");
	char *default_settings = "# QuickNote Configuration File\n#\n\n# Choose a text editor.\neditor=nano\n\n# Ex. 9:45 PM --> 21:45\nmiltime=0\n\n# Changes how new notes will look. 0-4\nstyle=0\n\n# Append to an existing file.\nappendmode=0\n\n";
	fwrite(default_settings, 1, strlen(default_settings), config_file);
	fclose(config_file);
}

CONFIG get_config_from_file(char *filepath) {
	if(access(filepath, F_OK) != 0) init_config_file(filepath);
	FILE *config_file = fopen(filepath, "r");
	size_t file_size = 0;
	fseek(config_file, 0, SEEK_SET);
	fseek(config_file, 0, SEEK_END);
	file_size = ftell(config_file);
	fseek(config_file, 0, SEEK_SET);
	char *buf = malloc(file_size);
	int index = 0;
	while(!feof(config_file) && !ferror(config_file)) {
		buf[index++] = fgetc(config_file); //needs tweaked
	}
	strcat(buf, "\0");
	CONFIG cfg;
	cfg.miltime = 0;
	cfg.style = 0;
	cfg.appendmode = 0;
	int num_lines = 0;
	for(int i = 0; i < index; i += 1) {
		if(buf[i] == '\n') num_lines += 1;
	}
	char *lines[num_lines];
	lines[0] = strtok(buf, "\n");
	int token_count = 1;
	while(1) {
		char *token = strtok(NULL, "\n");
		if(token == NULL) break;
		lines[token_count++] = token;
	}
	token_count = token_count - 1;
	free(buf);
	for(int i = 0; i < token_count; i += 1) {
		if(verify_setting_id(lines[i], "editor") == 0) {
			char *setting = get_setting(lines[i], "editor");
			if(strlen(setting) < 1) strcpy(cfg.editor, "nano");
			else strcpy(cfg.editor, setting);
		}
		else if(verify_setting_id(lines[i], "style") == 0) {
			char *setting = get_setting(lines[i], "style");
			if(setting[0] == '1') cfg.style = 1;
			else if(setting[0] == '2') cfg.style = 2;
			else if(setting[0] == '3') cfg.style = 3;
			else if(setting[0] == '4') cfg.style = 4;
			else cfg.style = 0;
		}
		else if(verify_setting_id(lines[i], "miltime") == 0) {
			char *setting = get_setting(lines[i], "miltime");
			if(setting[0] == '1') cfg.miltime = 1;
			else cfg.miltime = 0;
		}
		else if(verify_setting_id(lines[i], "appendmode") == 0) {
			char *setting = get_setting(lines[i], "appendmode");
			if(setting[0] == '1') cfg.appendmode = 1;
			else cfg.appendmode = 0;
		}
	}
	return cfg;
}