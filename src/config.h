#ifndef CONFIG_H
#define CONFIG_H

typedef struct CONFIG {
	char editor[26];
	unsigned int style;
	unsigned int appendmode;
	unsigned int miltime;
} CONFIG;

char *get_setting(char *line, char *s_id);

int verify_setting_id(char *line, char *s_id);

void init_config_file(char *filepath);

CONFIG get_config_from_file(char *filepath);

#endif //CONFIG_H
