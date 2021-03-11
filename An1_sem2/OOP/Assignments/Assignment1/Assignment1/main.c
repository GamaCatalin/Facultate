#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char first_date[10000], dates[100000],ASCII_0='0';
int needed_days = 10000, NumberOfCharactersDate=10;
int DaysInYear= 365, MileniumConstant = 1000, CenturyConstant = 100, DecadeConstant = 10,MonthDateMultiplyer=10, DayDateMultiplyer=10, DaysInMonthWith31Days = 31, DaysInMonthWith30Days = 30, DaysInMonthWith29Days = 29, DaysInMonthWith28Days = 28;
int dayFirstCharacter, daySecondCharacter, monthFirstCharacter, monthSecondCharacter, yearMileniumCharacter, yearCenturyCharacter, yearDecadeCharacter, yearCharacter;

int calculate_days(char StringOfDates[100000]) {

	/*

	Calculates the number of days between the two dates entered as a string

	*/


	int first_date_days_number, second_date_days_number, first_date_month_days_number, second_date_month_days_number, first_date_year_days_number, second_date_year_days_number;
	int days = 0, FirstDateDays = 0, SecondDateDays = 0;


	/*

	Gets the first/second date's day

	*/


	dayFirstCharacter = StringOfDates[0]-ASCII_0;
	daySecondCharacter = StringOfDates[1] - ASCII_0;

	first_date_days_number = dayFirstCharacter * DayDateMultiplyer + daySecondCharacter ;



	dayFirstCharacter = StringOfDates[11] - ASCII_0;
	daySecondCharacter = StringOfDates[12] - ASCII_0;

	second_date_days_number = dayFirstCharacter * DayDateMultiplyer + daySecondCharacter;

	/*

	Gets the first/second date's month

	*/

	monthFirstCharacter = (StringOfDates[3] - ASCII_0);
	monthSecondCharacter = (StringOfDates[4] - ASCII_0);

	first_date_month_days_number = monthFirstCharacter * MonthDateMultiplyer + monthSecondCharacter;

	monthFirstCharacter = (StringOfDates[14] - ASCII_0);
	monthSecondCharacter = (StringOfDates[15] - ASCII_0);

	second_date_month_days_number = monthFirstCharacter * MonthDateMultiplyer + monthSecondCharacter;

	/*

	Gets the first/second date's year

	*/


	yearMileniumCharacter = (StringOfDates[6] - ASCII_0);
	yearCenturyCharacter = (StringOfDates[7] - ASCII_0);
	yearDecadeCharacter = (StringOfDates[8] - ASCII_0);
	yearCharacter = (StringOfDates[9] - ASCII_0);

	first_date_year_days_number =  yearMileniumCharacter * MileniumConstant + yearCenturyCharacter * CenturyConstant + yearDecadeCharacter * DecadeConstant + yearCharacter;


	yearMileniumCharacter = (StringOfDates[17] - ASCII_0);
	yearCenturyCharacter = (StringOfDates[18] - ASCII_0);
	yearDecadeCharacter = (StringOfDates[19] - ASCII_0);
	yearCharacter = (StringOfDates[20] - ASCII_0);

	second_date_year_days_number = yearMileniumCharacter * MileniumConstant + yearCenturyCharacter * CenturyConstant + yearDecadeCharacter * DecadeConstant + yearCharacter;

	FirstDateDays += first_date_days_number;
	SecondDateDays += second_date_days_number;

	/*

	Calculates the first date's month as days

	*/

	while (first_date_month_days_number > 0) {

		if (first_date_month_days_number == 1 || first_date_month_days_number == 3 || first_date_month_days_number == 5 || first_date_month_days_number == 7 || first_date_month_days_number == 8 || first_date_month_days_number == 10 || first_date_month_days_number == 12) {
			FirstDateDays += DaysInMonthWith31Days;
		}
		else {

			if (first_date_month_days_number == 2) {
				if (first_date_year_days_number % 4 == 0) FirstDateDays += DaysInMonthWith29Days;
				else FirstDateDays += DaysInMonthWith28Days;
			}
			else FirstDateDays += DaysInMonthWith30Days;

		}

		first_date_month_days_number--;

	}

	/*

	Calculates the second date's month as days

	*/

	while (second_date_month_days_number > 0) {

		if (second_date_month_days_number == 1 || second_date_month_days_number == 3 || second_date_month_days_number == 5 || second_date_month_days_number == 7 || second_date_month_days_number == 8 || second_date_month_days_number == 10 || second_date_month_days_number == 12) {
			SecondDateDays += DaysInMonthWith31Days;
		}
		else {

			if (second_date_month_days_number == 2) {
				if (second_date_year_days_number % 4 == 0) SecondDateDays += DaysInMonthWith29Days;
				else SecondDateDays += DaysInMonthWith28Days;
			}
			else SecondDateDays += DaysInMonthWith30Days;

		}

		second_date_month_days_number--;
	}

	/*

	Calculates the first/second date's year as days

	*/

	FirstDateDays += first_date_year_days_number * DaysInYear + first_date_year_days_number / 4;
	SecondDateDays += second_date_year_days_number * DaysInYear + second_date_year_days_number / 4;

	/*

	Calculates the difference between the resulting days

	*/

	days = abs(FirstDateDays - SecondDateDays);


	return days;
}




int main()
{


	scanf("%[^\n]s", dates);
	while (strcmp(dates, "exit") != 0) {

		/*

		Saves the first date

		*/

		strncpy(first_date, dates, NumberOfCharactersDate);



		if (calculate_days(dates) >= needed_days) printf("%s\n", first_date);



		scanf("%s", dates);

		return 0;
	}

}