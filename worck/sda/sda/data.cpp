#include <iostream>т
int daysInMonthWithoutLeapYear[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int daysInMonthWithLeapYear[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int DaysInMonth(int m) { return daysInMonthWithoutLeapYear[m - 1]; }



int main()
{
	int god, monthNumber, number;

	std::cin >> number >> monthNumber >> god;
	//определяем высокосный год или нет
	int *daysInMonth = (((god % 4 == 0) && (god % 100 != 0)) || (god % 400 == 0)) 
		              ? daysInMonthWithLeapYear : daysInMonthWithoutLeapYear;

	int backDay, backMonth, backYear;
/*
	if (number == daysInMonth[monthNumber - 1])
	{
		backDay = 1;
		if (monthNumber == 12)
		{
			backMonth = 1;
			backYear = ++god;
		}
		else
		{
			backMonth = ++monthNumber;
			backYear = god;
		}
	}
	else
	{
		backDay = ++number;
		backMonth = monthNumber;
		backYear = god;
	}
*/
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


	std::cout << backDay << '.' << backMonth << '.' << backYear << std::endl;

	int c;
	std::cin >> c;

	return 0;
}