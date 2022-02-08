#include <stdio.h>
#include <math.h>
#include <windows.h>
// int main()
// {
//     char str1[6] = {'i', 'l', 'o', 'v', 'e', '\0'};
//     // char str2[] = "pi you love C";
//     // strcat(str1, " ");
//     // strcat(str1, str2);
//     printf("%s\n", str1);
//     printf("hello\n");
//     system("pause");
//     return 0;
// }
#include <stdio.h>
int length;

void quick_sort(int array[], int left, int right)
{
		int i = left, j = right;
		int temp, median;
		median = array[(left + right) / 2];
		while(i <= j)
		{
				while(array[i] < median)
				{
						i++;
				}
				while(array[j] > median)
				{
						j--;
				}
                if(i <= j)
                {
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                    i++;
                    j--; 
                }
                for(int i = 0; i < length; i++)
		        {
				    printf("%d ", array[i]);
		        }
		printf("\n");	
		}
		if(left < j)
		{
				quick_sort(array, left, j);
		}
		if(i < right)
		{
				quick_sort(array, i, right);
		}

}

int main(void)
{
		int array[] = {100 ,80 ,90, 23, 88, 97, 0, 54, 19, 78, 188};
		
		length = sizeof(array) / sizeof(array[0]);
		quick_sort(array, 0, length - 1);
		for(int i = 0; i < length; i++)
		{
				printf("%d ", array[i]);
		}
		printf("\n");
        system("pause");
        return 0;
}
