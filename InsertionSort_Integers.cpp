#include "InsertionSort_Integers.h"

void InsertionSort(int data[], int length)
{
	int key;
	int sortLocation;

	//Determine whether the array is empty
	if (length == 0)
	{
		//Output error message to the console
		PrintDividerToConsole(DIVIDER_WIDTH, ERROR_DIVIDER_CHAR);
		PrintCenteredMessage(cout, "Error - empty array", DIVIDER_WIDTH);
		PrintDividerToConsole(DIVIDER_WIDTH, ERROR_DIVIDER_CHAR);
	} // !if
	/*
	Determine whether the array only has 1 element, in which case it is
	technically already sorted
	*/
	else if (length == 1)
	{
		//Output message to the console indicating the array is sorted
		PrintDividerToConsole(SUB_DIVIDER_WIDTH, DIVIDER_CHAR);
		cout << "Array is already sorted" << endl;
		PrintDividerToConsole(SUB_DIVIDER_WIDTH, DIVIDER_CHAR);

		//Output the one element to the console
		cout << data[0] << endl;

		PrintDividerToConsole(SUB_DIVIDER_WIDTH, DIVIDER_CHAR);
	} // !else if
	else
	{
		/*
		Start at position 1 in the array since the array is technically sorted
		up to position 0
		*/
		//For each element in the array
		for (int unsortedElem = 1;
			unsortedElem < length;
			unsortedElem++)
		{
			/*
			Save the current array element, which should be the next unsorted
			element
			*/
			key = data[unsortedElem];

			/*
			Save the location of the element before the current unsorted element
			which is also the position of the last element in the sorted part of
			the array
			*/
			sortLocation = unsortedElem - 1;

			//Determine whether the key value is in the correct position
			if (key < data[sortLocation])
			{
				/*
				Move the elements of the array that are greater than the key
				value to one position ahead of their current position
				*/
				while ((sortLocation >= 0) && (data[sortLocation] > key))
				{
					/*
					Move the element at the current sort location to the next
					position after it
					*/
					data[sortLocation + 1] = data[sortLocation];

					/*
					Decrement the current sort location for the next comparison
					*/
					sortLocation--;
				} // !while

				  /*
				  At this point all the elements that are greater than the key
				  value have been moved to the position immediately after their
				  original position
				  Now we just have to put the key value in its correct location
				  */
				data[sortLocation] = key;
			} // !if
		} // !for

		PrintArrayToConsole(data, length);
	} // !else
} // !InsertionSort