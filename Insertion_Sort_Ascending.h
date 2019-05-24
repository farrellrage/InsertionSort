//------------------------------------------------------------------------------
//Programmer:		Austin M Farrell
//Insertion Sort
//	Insertion Sort looks at each element in the given array and determines
//	whether they are in the correct position by comparing them to the element
//	before them.
//	If a given element is smaller than the previous element, then all previous
//	elements that are larger than the given element are moved to the position
//	after their current position.
//	The given element is then inserted at the position freed up by the shifted
//	elements.
//	Sorts in ascending order
//------------------------------------------------------------------------------
#ifndef Insertion_Sort_Ascending_h
#define Insertion_Sort_Ascending_h

#include "Main.h"
#include "Standard_Helper_Functions.h"

template <typename type>
void InsertionSortAscending(type data[], int length)
{
	type key;
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
		for (int currentPosition = 1;
			currentPosition < length;
			currentPosition++)
		{
			/*
			Save the current array element, which should be the next unsorted
			element
			*/
			key = data[currentPosition];

			/*
			Save the location of the element before the current unsorted
			element, which is to say the position of the last element in the
			sorted part of the array
			*/
			sortLocation = currentPosition - 1;

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
			The last time the decrement statement in the 'while' loop
			executes, the saved location now points to the position in the
			array before the position that the key value should be placed,
			so we must increment the saved location
			*/
			data[sortLocation + 1] = key;
		} // !for
	} // !else
} // !InsertionSort_Ascending

#endif // !Insertion_Sort_Ascending_h
