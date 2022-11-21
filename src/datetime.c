#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

char *get_time(int hour, int min, unsigned int tmode) {
	int strlength = 0;
	if(tmode == 0) strlength = 9;
	else if(tmode == 1) strlength = 6;
	char *time = malloc(strlength);
	int ampm = 0;
	if(hour >= 0 && hour <= 11) { //hour
		ampm = 1;
		if(hour == 0) {
			if(tmode == 0) strcpy(time, "12:");
			else if(tmode == 1) strcpy(time, "24:");
		}
		else if(hour == 1) {
			if(tmode == 0) strcpy(time, "1:");
			else if(tmode == 1) strcpy(time, "01:");
		}
		else if(hour == 2) {
			if(tmode == 0) strcpy(time, "2:");
			else if(tmode == 1) strcpy(time, "02:");
		}
		else if(hour == 3) {
			if(tmode == 0) strcpy(time, "3:");
			else if(tmode == 1) strcpy(time, "03:");
		}
		else if(hour == 4) {
			if(tmode == 0) strcpy(time, "4:");
			else if(tmode == 1) strcpy(time, "04:");
		}
		else if(hour == 5) {
			if(tmode == 0) strcpy(time, "5:");
			else if(tmode == 1) strcpy(time, "05:");
		}
		else if(hour == 6) {
			if(tmode == 0) strcpy(time, "6:");
			else if(tmode == 1) strcpy(time, "06:");
		}
		else if(hour == 7) {
			if(tmode == 0) strcpy(time, "7:");
			else if(tmode == 1) strcpy(time, "07:");
		}
		else if(hour == 8) {
			if(tmode == 0) strcpy(time, "8:");
			else if(tmode == 1) strcpy(time, "08:");
		}
		else if(hour == 9) {
			if(tmode == 0) strcpy(time, "9:");
			else if(tmode == 1) strcpy(time, "09:");
		}
		else if(hour == 10) strcpy(time, "10:");
		else if(hour == 11) strcpy(time, "11:");
	}
	else if(hour >= 12 && hour <= 23) {
		ampm = 2;
		if(hour == 12) strcpy(time, "12:");
		else if(hour == 13) {
			if(tmode == 0) strcpy(time, "1:");
			else if(tmode == 1) strcpy(time, "13:");
		}
		else if(hour == 14) {
			if(tmode == 0) strcpy(time, "2:");
			else if(tmode == 1) strcpy(time, "14:");
		}
		else if(hour == 15) {
			if(tmode == 0) strcpy(time, "3:");
			else if(tmode == 1) strcpy(time, "15:");
		}
		else if(hour == 16) {
			if(tmode == 0) strcpy(time, "4:");
			else if(tmode == 1) strcpy(time, "16:");
		}
		else if(hour == 17) {
			if(tmode == 0) strcpy(time, "5:");
			else if(tmode == 1) strcpy(time, "17:");
		}
		else if(hour == 18) {
			if(tmode == 0) strcpy(time, "6:");
			else if(tmode == 1) strcpy(time, "18:");
		}
		else if(hour == 19) {
			if(tmode == 0) strcpy(time, "7:");
			else if(tmode == 1) strcpy(time, "19:");
		}
		else if(hour == 20) {
			if(tmode == 0) strcpy(time, "8:");
			else if(tmode == 1) strcpy(time, "20:");
		}
		else if(hour == 21) {
			if(tmode == 0) strcpy(time, "9:");
			else if(tmode == 1) strcpy(time, "21:");
		}
		else if(hour == 22) {
			if(tmode == 0) strcpy(time, "10:");
			else if(tmode == 1) strcpy(time, "22:");
		}
		else if(hour == 23) {
			if(tmode == 0) strcpy(time, "11:");
			else if(tmode == 1) strcpy(time, "23:");
		}
	}
	if(min == 0) strcat(time, "00"); //minute
	else if(min == 1) strcat(time, "01");
	else if(min == 2) strcat(time, "02");
	else if(min == 3) strcat(time, "03");
	else if(min == 4) strcat(time, "04");
	else if(min == 5) strcat(time, "05");
	else if(min == 6) strcat(time, "06");
	else if(min == 7) strcat(time, "07");
	else if(min == 8) strcat(time, "08");
	else if(min == 9) strcat(time, "09");
	else if(min == 10) strcat(time, "10");
	else if(min == 11) strcat(time, "11");
	else if(min == 12) strcat(time, "12");
	else if(min == 13) strcat(time, "13");
	else if(min == 14) strcat(time, "14");
	else if(min == 15) strcat(time, "15");
	else if(min == 16) strcat(time, "16");
	else if(min == 17) strcat(time, "17");
	else if(min == 18) strcat(time, "18");
	else if(min == 19) strcat(time, "19");
	else if(min == 20) strcat(time, "20");
	else if(min == 21) strcat(time, "21");
	else if(min == 22) strcat(time, "22");
	else if(min == 23) strcat(time, "23");
	else if(min == 24) strcat(time, "24");
	else if(min == 25) strcat(time, "25");
	else if(min == 26) strcat(time, "26");
	else if(min == 27) strcat(time, "27");
	else if(min == 28) strcat(time, "28");
	else if(min == 29) strcat(time, "29");
	else if(min == 30) strcat(time, "30");
	else if(min == 31) strcat(time, "31");
	else if(min == 32) strcat(time, "32");
	else if(min == 33) strcat(time, "33");
	else if(min == 34) strcat(time, "34");
	else if(min == 35) strcat(time, "35");
	else if(min == 36) strcat(time, "36");
	else if(min == 37) strcat(time, "37");
	else if(min == 38) strcat(time, "38");
	else if(min == 39) strcat(time, "39");
	else if(min == 40) strcat(time, "40");
	else if(min == 41) strcat(time, "41");
	else if(min == 42) strcat(time, "42");
	else if(min == 43) strcat(time, "43");
	else if(min == 44) strcat(time, "44");
	else if(min == 45) strcat(time, "45");
	else if(min == 46) strcat(time, "46");
	else if(min == 47) strcat(time, "47");
	else if(min == 48) strcat(time, "48");
	else if(min == 49) strcat(time, "49");
	else if(min == 50) strcat(time, "50");
	else if(min == 51) strcat(time, "51");
	else if(min == 52) strcat(time, "52");
	else if(min == 53) strcat(time, "53");
	else if(min == 54) strcat(time, "54");
	else if(min == 55) strcat(time, "55");
	else if(min == 56) strcat(time, "56");
	else if(min == 57) strcat(time, "57");
	else if(min == 58) strcat(time, "58");
	else if(min == 59) strcat(time, "59");
	if(tmode == 0) {
		if(ampm == 1) strcat(time, " AM");
		else if(ampm == 2) strcat(time, " PM");
	}
	strcat(time, "\0");
	return time;
}

char *get_date(int month, int day, int year) {
	char *date = malloc(11);
	if(month == 0) strcpy(date, "01/"); //month
	else if(month == 1) strcpy(date, "02/");
	else if(month == 2) strcpy(date, "03/");
	else if(month == 3) strcpy(date, "04/");
	else if(month == 4) strcpy(date, "05/");
	else if(month == 5) strcpy(date, "06/");
	else if(month == 6) strcpy(date, "07/");
	else if(month == 7) strcpy(date, "08/");
	else if(month == 8) strcpy(date, "09/");
	else if(month == 9) strcpy(date, "10/");
	else if(month == 10) strcpy(date, "11/");
	else if(month == 11) strcpy(date, "12/");
	if(day == 1) strcat(date, "01/"); //day
	else if(day == 2) strcat(date, "02/");
	else if(day == 3) strcat(date, "03/");
	else if(day == 4) strcat(date, "04/");
	else if(day == 5) strcat(date, "05/");
	else if(day == 6) strcat(date, "06/");
	else if(day == 7) strcat(date, "07/");
	else if(day == 8) strcat(date, "08/");
	else if(day == 9) strcat(date, "09/");
	else if(day == 10) strcat(date, "10/");
	else if(day == 11) strcat(date, "11/");
	else if(day == 12) strcat(date, "12/");
	else if(day == 13) strcat(date, "13/");
	else if(day == 14) strcat(date, "14/");
	else if(day == 15) strcat(date, "15/");
	else if(day == 16) strcat(date, "16/");
	else if(day == 17) strcat(date, "17/");
	else if(day == 18) strcat(date, "18/");
	else if(day == 19) strcat(date, "19/");
	else if(day == 20) strcat(date, "20/");
	else if(day == 21) strcat(date, "21/");
	else if(day == 22) strcat(date, "22/");
	else if(day == 23) strcat(date, "23/");
	else if(day == 24) strcat(date, "24/");
	else if(day == 25) strcat(date, "25/");
	else if(day == 26) strcat(date, "26/");
	else if(day == 27) strcat(date, "27/");
	else if(day == 28) strcat(date, "28/");
	else if(day == 29) strcat(date, "29/");
	else if(day == 30) strcat(date, "30/");
	else if(day == 31) strcat(date, "31/");
	int y = 1900 + year; //year
	char *yr = malloc(sizeof(y));
	sprintf(yr, "%d", y);
	strcat(date, yr);
	return date;
}