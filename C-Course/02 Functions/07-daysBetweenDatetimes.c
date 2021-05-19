#include <stdio.h>
#include <time.h>

void createDateTime(struct tm *t, int day, int month, 
		int year, int hour, int min, int sec) {
	t->tm_year =  year -1900;
	t->tm_mon = month -1;
	t->tm_mday = day;
	t->tm_hour = hour;
	t->tm_min = min;
	t->tm_sec = sec;
}

int main() {
	struct tm ini, end;
	time_t timestamp0, timestamp1;
	double secs;

	createDateTime(&ini, 1, 1, 2019, 0, 0, 0);
	createDateTime(&end, 3, 1, 2019, 2, 30, 30);
	timestamp1 = mktime(&end);
	timestamp0 = mktime(&ini);
	secs = difftime(timestamp1, timestamp0);
	
	printf("DateTime final: %s", asctime(&end));
	printf("DateTime initial: %s", asctime(&ini));
	printf("Total of %0.2f h\n", secs/3600);
}