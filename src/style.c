#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#include "style.h"
#include "datetime.h"

char *format_timedate(unsigned int style, unsigned int tmode) {
	time_t now = time(0);
	struct tm *rn = localtime(&now);
	char *date = get_date(rn->tm_mon, rn->tm_mday, rn->tm_year);
	char *time = get_time(rn->tm_hour, rn->tm_min, tmode);
	int strlength = 0;
	if(style == 0) strlength = strlen(date) + strlen(time) + 6;
	else if(style == 1) strlength = strlen(date) + strlen(time) + 6;
	else if(style == 2) strlength = strlen(date) + strlen(time) + 2;
	else if(style == 3) strlength = strlen(date) + strlen(time) + 13;
	else if(style == 4) strlength = strlen(date) + strlen(time) + 13;
	char *fdt = malloc(strlength);
	if(style == 0) {
		strcpy(fdt, date);
		strcat(fdt, " @ ");
		strcat(fdt, time);
	}
	else if(style == 1) {
		strcpy(fdt, date);
		strcat(fdt, " | ");
		strcat(fdt, time);
	}
	else if(style == 2) {
		strcpy(fdt, date);
		strcat(fdt, "\n");
		strcat(fdt, time);
	}
	else if(style == 3) {
		strcpy(fdt, "[ ");
		strcat(fdt, date);
		strcat(fdt, " ]\n[ ");
		strcat(fdt, time);
		int numspaces = strlen(date) - strlen(time);
		for(int i = 0; i < numspaces; i += 1) strcat(fdt, " ");
		strcat(fdt, " ]");
	}
	else if(style == 4) {
		strcpy(fdt, "[ ");
		strcat(fdt, date);
		strcat(fdt, " ]\n[ ");
		int numspaces = strlen(date) - strlen(time);
		for(int i = 0; i < numspaces; i += 1) strcat(fdt, " ");
		strcat(fdt, time);
		strcat(fdt, " ]");
	}
	strcat(fdt, "\n\n\0");
	return fdt;
}