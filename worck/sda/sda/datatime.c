#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>


int daysInMonthWithoutLeapYear[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int daysInMonthWithLeapYear[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main()
{

	time_t t = time(NULL);
	// получаем текущее время 
	struct tm* aTm = localtime(&t);
	int god =         aTm->tm_year + 1900,
		monthNumber = aTm->tm_mon + 1,
		number =      aTm->tm_mday;
	int backDay, backMonth, backYear;
	int *daysInMonth = (((god % 4 == 0) && (god % 100 != 0)) || (god % 400 == 0))
		? daysInMonthWithLeapYear : daysInMonthWithoutLeapYear;


	printf("%d : %d : %d\n", number, monthNumber, god);

	if (number > 1 && number <= daysInMonth[monthNumber - 1])
	{
		backDay = --number;
		backMonth = monthNumber;
		backYear = god;

	}
	else if (number == 1)
	{
		if (monthNumber != 1)
		{
			backDay = daysInMonth[monthNumber - 2];
			backMonth = --monthNumber;
			backYear = god;
		}
		else
		{
			backMonth = 12;
			backDay = daysInMonth[monthNumber - 1];
			backYear = --god;
		}

	}


	printf("%d : %d : %d\n", backDay, backMonth, backYear);

	{
		int i;

		for (i = 0; i < 10; ++i)
		{
			printf("%d ", i + 1);
		}
	}
}
