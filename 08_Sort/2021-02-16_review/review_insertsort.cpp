

void InsertSort(int array[],int len){
	int temp = -1;
	int i = 0;
	int j = 0;
	int k = -1;

	for(i = 1;i < len;i++){
		k = i;
		temp = array[k];
		for(j = i - 1;(j >= 0) && (array[j] > temp);j--)
		{
			array[j + 1] = array[j];
			k = j;
		}
		array[k] = temp;
	}
}


