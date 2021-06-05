#include <stdio.h>
#include "ChangePathFile.h"
#include "Sorting.h"
#include "main.h"
#include "InputOutputData.h"
#include "DatabaseStruct.h"
#include <string.h>
#include <time.h>
#include "SortingTest.h"

void TestSorting()
{
	clock_t start, stop;
	double time;

	Database database1 = {0,0,"Write.txt"};
	GenerateRandomData(&database1);

	Database database2 = CopyTable(&database1);
	Database database3 = CopyTable(&database1);

	QuickSortTest(&database1);
	ShellSortTest(&database2);
	InsertSortTest(&database3);

	ClearDb(&database1);
	ClearDb(&database2);
	ClearDb(&database3);
}

void QuickSortTest(Database* database)
{
	clock_t start, stop;

	printf("Sortowanie szybkie. Prosze czekac!\n");
	start = clock();
	QuickSort(database,0 , database->recordsCount-1,0);
	stop = clock();
	printf("Czas sortowania szybkiego: %1.3lf sekund.\n\n", (double)(stop - start)/ CLOCKS_PER_SEC);
}

void ShellSortTest(Database* database)
{
	clock_t start, stop;

	printf("Sortowanie Shella. Prosze czekac!\n");
	start = clock();
	ShellSort(database,0);
	stop = clock();
	printf("Czas sortowania Shella: %1.3lf sekund.\n\n", (double)(stop - start)/ CLOCKS_PER_SEC);
}

void InsertSortTest(Database* database)
{
	clock_t start, stop;

	printf("Sortowanie przez wybieranie. Prosze czekac!\n");
	start = clock();
	SelectSort(database,0);
	stop = clock();
	printf("Czas sortowania przez wybieranie: %1.3lf sekund.\n\n", (double)(stop - start)/ CLOCKS_PER_SEC);
}


Database CopyTable(Database* database){
	Database databaseCOPY = {0,0,"Write.txt"};
	databaseCOPY.recordsCount = database->recordsCount;
	if (database->recordsCount == 0){
		printf("Tablica jest pusta!");
	} else {
		databaseCOPY.records = malloc(database->recordsCount * sizeof *database->records);
		for (int i = 0; i < database->recordsCount; ++i) {

			strcpy(databaseCOPY.records[i].name, database->records[i].name);
			databaseCOPY.records[i].price = database->records[i].price;
		}
	}
	return databaseCOPY;
}

void GenerateRandomData(Database* database)
{
	int recordsAmount;

	if (database->records != NULL)
	{
		printf("Nie mozna dodac wiecej elementow\n");
		return;
	}

	int exitLoop = 0;

	while (exitLoop != 1) {
		printf("Wprowadz ilosc rekordow do utworzenia");
		scanf("%d", &recordsAmount);

		if (recordsAmount >0) {
			database->records = malloc(recordsAmount * sizeof *database->records);
			database->recordsCount = recordsAmount;
			exitLoop = 1;
		} else{
			printf("podana liczba musi byc wieksza od 0! sprobuj ponownie :)\n");
		}
	}

	for(int i = 0; i < recordsAmount; i++)
	{
		RandomString(&database->records[i].name, 20);
		database->records[i].price = rand() / 10.0;
	}
}

void RandomString(char* string, int length)
{
	static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

	for(int i = 0; i < length; i++)
		string[i] = charset[rand() % (int)(sizeof(charset) -1)];

	string[length] = '\0';
}