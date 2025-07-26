# Gregorian Calendar Generator

This is a simple C-based console application that displays the Gregorian calendar for a specific month or the entire year. The program is designed to help users easily visualize monthly calendars in a structured, readable format directly in the terminal.

## Overview

The application prompts the user to input a year and either a specific month (1–12) or an option to display all 12 months of that year. It accurately calculates leap years to determine the correct number of days in February and uses logical date computation to find the starting day of the week for any given month. The output is a neatly formatted calendar grid that reflects the actual layout of days and dates for the selected time period.

## Features

* View calendar for a specific month or full year
* Accurate leap year detection
* Day-of-week calculation
* Input validation and edge case handling
* Lightweight and runs fully in terminal
* No external libraries required

## How to Run

1. Compile the program:
   `gcc calendar.c -o calendar`

2. Run the program:
   `./calendar`

3. Input the desired year (e.g., 2024)

4. Input a month number (1–12) or `0` to display all months

## Example

```
Enter Year = 2024  
Enter Month (1-12 or 'ALL') = 0
```

This will display calendars for all months of the year 2024.

## Sample Test Cases

* Year: 2020 → February has 29 days
* Year: 2100 → February has 28 days
* Month: 13 → Shows "Invalid Month" message
* Year: -100 → Shows "Invalid Year" message
* Date: 25/12/2023 → Outputs "Monday"
* Month: 0 → Displays full calendar for the year

## License

This project is intended for educational use. Feel free to explore, modify, and reuse it as needed.
