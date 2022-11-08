// Determine the min and max value from a set of integers.
// Don't use functions, write only in main and use arrays.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int numbers[1001], count = 0, min_value, max_value;
	char count_string[100];
	printf("Please enter the number of elements the array should have.\n");
	int valid_input = 1;

	do
	{
		valid_input = 1; // Assume that the input is valid.
		scanf("%s", count_string); // Take the input as a string.
		
		for(int i = 0; i < (int)strlen(count_string); i++)
		{
			// If there is a character that is not a digit, it means the input is not a number.
			if(count_string[i] < '0' || count_string[i] > '9')
				valid_input = 0;
		}

		if(valid_input == 0)
			printf("Invalid input! Please enter an integer number!\n");

	}
	while(valid_input == 0); // Repeat until the user enters a valid input(Positive integer in this case).

	// After that, convert the string to an integer.
	count = atoi(count_string);

	printf("Now please enter the elements of the array.\n");

	for(int i = 0; i < count; i++)
	{
		char element_string[101];
		do 
		{
		   	// Repeat the same check for the values in the array.
			valid_input = 1;
			printf("Number %d = ", i + 1);
			scanf("%s", element_string);

			for(int j = 0; j < (int)strlen(element_string); j++)
			{
				if(element_string[j] < '0' || element_string[j] > '9')
					valid_input = 0;

				// Since the allowed numbers are integers, we have to check if the first character is the minus sign.
				if(j == 0 && element_string[j] == '-')
					valid_input = 1;
			}

			if(valid_input == 0)
				printf("Invalid input! Please enter an integer number!\n");
		}
		while(valid_input == 0); // Repeat until the given input is valid(Integer in this case).

		// Convert the string to an integer.
		numbers[i] = atoi(element_string);
	}

	// Set the min and max value as the first element in the array.
	max_value = numbers[0];
	min_value = numbers[0];

	for(int i = 1; i < count; i++)
	{
		// Find the max number.
		if(numbers[i] > max_value)
			max_value = numbers[i];

		// Find the min number.
		if(numbers[i] < min_value)
			min_value = numbers[i];
	}

	printf("The maximum number in the array is %d and the minimum number is %d.\n", max_value, min_value);

	return 0;
}