// C++ program for Merge Sort
#include<iostream>
using namespace std;

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int low, int m, int high)
{
	int size1 = m - low + 1;
	int size2 = high - m;

	// Create temp arrays
	int L[size1], R[size2];

	// Copy data to temp arrays L[] and R[]
	for(int i = 0; i < size1; i++)
		L[i] = arr[low + i];
	for(int j = 0; j < size2; j++)
		R[j] = arr[m + 1 + j];

	// Merge the temp arrays back into arr[l..r]

	// Initial index of first subarray
	int i = 0;

	// Initial index of second subarray
	int j = 0;

	// Initial index of merged subarray
	int k = low;

	while (i < size1 && j < size2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of
	// L[], if there are any
	while (i < size1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of
	// R[], if there are any
	while (j < size2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int arr[], int low, int high)
{
	if (low < high)
	{

		// Same as (l+r)/2, but avoids
		// overflow for large l and h
		int m = low + (high - low) / 2;

		// Sort first and second halves
		mergeSort(arr, low, m);
		mergeSort(arr, m + 1, high);

		merge(arr, low, m, high);
	}
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
	for(int i = 0; i < size; i++)
		cout << A[i] << " ";
}

// Driver code
int main()
{
    int n;
	cout<<"\nEnter Size of Array:\n";
	cin>>n;
	int A[n];
	cout<<"\nEnter elements of Array:\n";
	for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

	mergeSort(A, 0, n - 1);

	cout << "\nSorted array is \n";
	printArray(A, n);
	return 0;
}


