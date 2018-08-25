void BubbleSort(int arr[], unsigned int length)
{
	for (int i=1; i<length; i++)
	{
		for (int j=0; j<length-i; j++)
		{
			if (arr[j]>arr[j+1])
			{
				swap(arr+j, arr+j+1);
			}
		}
	}
}
