/*
Function: Find the median of the two sorted arrays within O(log(m+n)) time complexity
Parameter: two arrays, length of both arrays
ReturnValue: The median
*/

/*
Method1: Using Insert Sort to combline both arrays. O(m*n)
Method2: Merge Sort to combine. O(m+n)
*/




/**************************************************************************************************************************
 * Solution1:  Insert_Sort   TC: O((m+n)^2)  SC: O(m+n)
 **************************************************************************************************************************/
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
	int size = nums1Size +  nums2Size;
	int array[size]; 
	int i, j, k;
	for( i=0; i < nums1Size; i++ )
	{
		array[i] = nums1[i];
	}
	for( j=0; i < size; i++, j++ )
	{
		array[i] = nums2[j];
	}
	k = 0;	
	for( i=nums1Size;i > 0 && i < size; i++  )
	{	
		if( array[i] < array[i-1] )
		{
			int temp = array[i];
			for( j=i-1; j >= k && array[j] > temp; j-- )
			{
				array[j+1] = array[j];
			}
			array[j+1] = temp;
			k = j+1;
		}
	}
	int mid = size/2;
	double median;
	median = (0 == size%2) ? (array[mid]+array[mid-1])/2.0 : (double) array[mid];
	return median;
}





/**************************************************************************************************************************
 * Solution2  Merge_Sort   TC: O(m+n)  SC: O(m+n)
 **************************************************************************************************************************/
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
	int size = nums1Size + nums2Size;
	int array[size];
	int i, j, k;
	i = j = k = 0;
	while( i < nums1Size && j < nums2Size )
	{
		array[k++] = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];			
	}
	while( i < nums1Size )
	{
		array[k++] = nums1[i++];
	}
	while( j < nums2Size )
	{
		array[k++] = nums2[j++];
	}
	int mid = size/2;
	double median;
	median = (0 == size%2) ? (array[mid]+array[mid-1])/2.0 : (double) array[mid];
	return median; 	
}


