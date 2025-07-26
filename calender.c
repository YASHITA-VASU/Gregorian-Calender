#include <stdio.h>
#include <stdbool.h>
bool is_leap_year(int year) {
 if (year % 400 == 0)
 return true;
 else if (year % 100 == 0)
 return false;
 else if (year % 4 == 0)
 return true;
 else
 return false;
}
int days_in_month(int month, int year)
{
 if(month == 9 || month == 4 || month == 6 || month == 11)
 return 30;
 else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 ||
month == 12)
 return 31;
 else if(month == 2 && is_leap_year(year)==true)
 return 29;
 else
 return 28;
}
int days_from_epoch(int day, int month, int year) {
 int days = 0;
 int i, j;
 int diff;
 if (year < 1970) {
 diff = 1970 - year;
 for (j = 1; j < diff; j++) {
 if (is_leap_year(1970 - j))
 days += 366; else
 days += 365;
 }
 for (i = month + 1; i <= 12; i++)
 days += days_in_month(i - 1, year);
 days += (days_in_month(month, year) - day + 1);
 } else {
 diff = year - 1970;
 for (j = 0; j < diff; j++) {
 if (is_leap_year(1970 + j))
 days += 366;
 else
 days += 365;
 }
 for (i = 1; i < month; i++)
 days += days_in_month(i, year);
 days += (day - 1);
 }
 return days;
}
int day_of_week(int day, int month, int year) {
 int _day = days_from_epoch(day, month, year) % 7;
 if (year > 1970) {
 switch (_day) {
 case 0:
 return 4;
 case 1:
 return 5;
 case 2:
 return 6;
 case 3:
 return 0;
 case 4:
 return 1;
 case 5:
 return 2;
 case 6:
 return 3;
 }
 } else {
 switch (_day) {
 case 0:
 return 4;
 case 1:
 return 3;
 case 2:
 return 2;
 case 3:
 return 1;
 case 4:
 return 0;
 case 5:
 return 6;
 case 6:
 return 5;
 }
 }
}
void display_month(int month, int year) {
 printf("\n ");
 printf("Month %d, %d\n", month, year);
 printf(" Sun Mon Tue Wed Thu Fri Sat\n");
 int begin = day_of_week(1, month, year);
 int i, count = 0;
 for (i = 0; i < begin; i++) {
 printf(" ");
 ++count;
 }
 for (i = 1; i <= days_in_month(month, year); i++) {
 printf("%5d", i);
 count++;
 if (count % 7 == 0)
 printf("\n");
 }
 printf("\n\n");
}
int main() {
 int month;
 int year;
 printf("\nEnter Year = ");
 scanf("%d", &year);
 printf("Enter Month (1-12 or 'ALL') = ");
 if(scanf("%d", &month) == 1 && (month < 1 || month > 12)) {
 printf("\nInvalid Month, Please Enter Again (1-12) - ");
 return 1;
 }
 if (month == 0) {
 for (int m = 1; m <= 12; ++m) {
 display_month(m, year);
 }
 } else {
 while (year < 1) {
 printf("\nInvalid Year, Please Enter Again - ");
 scanf("%d", &year);
 }
 display_month(month, year);
 }
 return 0;
}
