#include <stdio.h>
#include <stdlib.h>

int amountMonth[] = {
	0, 31, 28, 31, 30, 31, 30,
	   31, 31, 30, 31, 30, 31
};

int totalOfMonthDays(int month, int year) {
	int i, days, isBi;
	isBi = abs(2012 - year) % 4;
	amountMonth[2] = (isBi == 0) ? 29 : 28;
	days = 0;
	for(i = 1; i < month; i++) days += amountMonth[i];
	return days;
}

int totalOfDays(int day0, int month0, int year0,
				int day1, int month1, int year1) {
	int timestamp0, timestamp1;
	timestamp0 = totalOfMonthDays(month0, year0) + day0;
	timestamp1 = totalOfMonthDays(month1, year1) + day1;
	for(int i = year0; i < year1; i++) {
		timestamp1 += (abs(2012 - i) % 4 == 0) ? 366 : 365;
	}
	printf("%02d/%02d/%04d - %02d/%02d/%04d\n", 
	   day1, month1, year1, day0, month0, year0);
	return (timestamp1 - timestamp0);
}

int main(void) {
  printf("Diference is %d days\n", totalOfDays(1, 1, 2019, 1, 1, 2020));
  printf("Diference is %d days\n", totalOfDays(1, 1, 2020, 1, 1, 2021));
  printf("Diference is %d days\n", totalOfDays(1, 1, 2019, 8, 7, 2019));
  return 0;
}
