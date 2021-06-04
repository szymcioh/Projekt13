#include "InputOutputData.h"
#include "Sorting.h"
#include "ItemStruct.h"
#include "InputOutputData.h"

void QuickSort(Database* database, int left, int right, int printSteps)                               //Szybkie sortowanie
{
	if(printSteps)
	{
		PrintTable(database);
		printf("%s", "\n");
	}

	double v = database->records[(left+right)/2].price;
	int i,j;
	Item x;
	i=left;
	j=right;
	do
	{
		while(database->records[i].price<v) i++;
			while(database->records[j].price>v) j--;
			if(i<=j)
			{
				x=database->records[i];
				database->records[i]=database->records[j];
				database->records[j]=x;
				i++;
				j--;
			}
	}
	while(i<=j);
	if(j>left) QuickSort(database,left, j, printSteps);
	if(i<right) QuickSort(database, i, right, printSteps);
}

void ShellSort(Database* database, int printSteps )
{
	int przerwa = database->recordsCount / 2;
	while(przerwa >= 1) {
		for (int i = przerwa; i < database->recordsCount; i += 1) {
			Item temp = database->records[i];
			int j;
			for (j = i; j >= przerwa && database->records[j - przerwa].price > temp.price; j -= przerwa)
			{
				database->records[j] = database->records[j - przerwa];

				if(printSteps)
				{
					PrintTable(database);
					printf("%s", "\n");
				}
			}
			database->records[j] = temp;
		}
		przerwa /= 2;
	}
}

void SelectSort(Database* database, int printSteps)
{

	for (int i = 0; i < database->recordsCount - 1; ++i)
	{
		int minValue = i;

		for (int j = i + 1; j < database->recordsCount; ++j)
		{
			if (database->records[j].price < database->records[minValue].price)
			{
				minValue = j;
			}
		}
		swap(&database->records[minValue].price, &database->records[i].price);

		if(printSteps)
		{
			PrintTable(database);
			printf("%s", "\n");
		}
	}
}

void swap(double *first, double *second)
{
	double temp = *first;
	*first = *second;
	*second = temp;
}