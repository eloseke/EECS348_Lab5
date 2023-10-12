#include <stdio.h>
#include <string.h>

void print_monthly_sales(float sales[], char months[][10])
{
	printf("\nMonthly sales report for 2022:\n\n");
	printf("%-12s%s\n", "Month", "Sales");
	for (int i=0; i<12; i++)
	{
		printf("%-12s$%0.2f\n", months[i], sales[i]);
	}
}

void print_sales_summary(float sales[], char months[][10])
{
	float avg = 0;
	float min = sales[0];
	char min_month[10] = "January";
	float max = sales[0];
	char max_month[10] = "January";

	for (int i=0; i<12; i++)
	{
		if (sales[i] < min)
		{
			min = sales[i];
			strcpy(min_month, months[i]);
		}
		if (sales[i] > max)
		{
			max = sales[i];
			strcpy(max_month, months[i]);
		}
	avg += sales[i];
	}
	avg /= 12;
	printf("\nSales summary:\n\n");
	printf("%-17s$%0.2f  (%s)\n", "Minimum sales:", min, min_month);
	printf("%-17s$%0.2f  (%s)\n", "Maximum sales:", max, max_month);
	printf("%-17s$%0.2f\n", "Average sales:", avg);
}

void print_moving_average(float sales[], char months[][10])
{
	printf("\nSix-Month Moving Average Report:\n\n");
	for (int i=0; i<7; i++)
	{
		float avg = 0;
		for (int j=i; j<i+6; j++)
		{
			avg += sales[j];
		}
		avg /= 6;
		printf("%-12s-  %-12s$%0.2f\n", months[i], months[i+5], avg);
	}
}

void print_sorted_report(float sales[], char months[][10])
{
	float temp_f = 0.0f;
	char temp_s[10] = "abcdef";
	for (int i=0; i<12; i++)
	{
		for (int j=0; j<11-i; j++)
		{
			if (sales[j] < sales[j+1])
			{
				temp_f = sales[j+1];
				sales[j+1] = sales[j];
				sales[j] = temp_f;
				strcpy(temp_s, months[j+1]);
				strcpy(months[j+1], months[j]);
				strcpy(months[j], temp_s);
			}
		}
	}
	printf("\nSales Report (Highest to Lowest)\n\n");
	printf("%-12s%s\n", "Month", "Sales");
	for (int i=0; i<12; i++)
	{
		printf("%-12s$%0.2f\n", months[i], sales[i]);
	}
}

int main()
{
	float num;
	float data[12];
	char MONTHS[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	int index = 0;

	FILE *in_file = fopen("sales_report.txt", "r");

	while (fscanf(in_file, "%f", &num) == 1)
	{
		data[index] = num;
		index++;
	}

	fclose(in_file);

	print_monthly_sales(data, MONTHS);
	print_sales_summary(data, MONTHS);
	print_moving_average(data, MONTHS);
	print_sorted_report(data, MONTHS);
	printf("\n");

	return 0;
}
