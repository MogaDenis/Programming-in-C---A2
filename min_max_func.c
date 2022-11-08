// Read a set of integers
// Determine the minimum and maximum values
// Use arrays and functions

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int take_input_and_check(char message[], int type)
{
	// In order to use this function for both positive and negative integers:
	// type == 0 for integers
	// type == 1 for positive integers

	char input_string[101];
	int is_valid = 1;

	do	
	{
		// Show a message for the user and read the string.
		printf("%s", message);
		scanf("%s", input_string);

		// Assume the input is valid.
		is_valid = 1;
		
		for(int i = 0; i < (int)strlen(input_string); i++)
		{
			// If there is a character which is not a digit, it means that the string is not a number.
			if(input_string[i] < '0' || input_string[i] > '9')
				is_valid = 0;
				
			// In case the function is used for integers and the first character is the minus sign,
			// it means the string is valid at this point.
			if(type == 0 && i == 0 && input_string[i] == '-')
				is_valid = 1;
		}

		// If the string can't be expressed as an integer then show a message.
		if(is_valid == 0)
			printf("Invalid input!\n");
		
	}
	while(is_valid == 0); // Repeat until a valid input is given.

	return atoi(input_string); // Return the integer value.
}

void read_array(int *length, int array[])
{
	// Request the user to insert a positive integer.
	*length = take_input_and_check("Please enter the number of elements the array should have (positive integer): ", 1);

	for(int i = 0; i < *length; i++)
	{
		// Generate an appropriate message to display for every iteration.
		char element_number[101];
		sprintf(element_number, "%d", i + 1); // Convert an integer to a string.

		// Compose the message.
		char message[101] = "Element no. ";
		strcat(message, element_number);
		strcat(message, " (integer): ");

		// Request the user to enter an integer.
		array[i] = take_input_and_check(message, 0);
	}
}

void find_min_max(int array[], int length, int *min_value, int *max_value)
{
	// Assume the minimum and maximum values are the first element in the array.
	*min_value = array[0];
	*max_value = array[0];

	// Iterate through the array and find the min and max values.
	for(int i = 1; i < length; i++)
	{
		if(array[i] > *max_value)
			*max_value = array[i];

		if(array[i] < *min_value)
			*min_value = array[i];
	}
}

void print_conclusion(int min_value, int max_value)
{
	// Print the minimum and maximum values in the array.
	printf("The minimum value of the given array is %d and the maximum value is %d.\n", min_value, max_value);
}

int main()
{
	// Put together all the functions.

	// Read the number of values and the array.
	int numbers[1001], numbers_count;
	read_array(&numbers_count, numbers);

	// Find both extreme values.
	int min_value, max_value;
	find_min_max(numbers, numbers_count, &min_value, &max_value);

	// Print an appropriate conclusion.
	print_conclusion(min_value, max_value);

	return 0;
}