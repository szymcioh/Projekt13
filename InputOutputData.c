#include "InputOutputData.h"
#include "DatabaseStruct.h"

void AddMultipleItems(Database* database) {
	int itemsToAddAmount;

	if (database->records == NULL)
	{
		printf("Ile danych chcesz wprowadzac ?");
		scanf("%d", &itemsToAddAmount);

		database->records = malloc(itemsToAddAmount * sizeof *database->records);
		database->recordsCount = itemsToAddAmount;
	} else
	{
		printf("Nie mozna dodac wiecej elementow\n");
		return;
	}

	for(int i = 0; i < database->recordsCount; i++)
	{
		printf("Podaj nazwe przedmiotu:");
		scanf("%s", &database->records[i].name);

		printf("Podaj cene:");
		scanf("%lf", &database->records[i].price);
	}
}

void SaveToFileTable(Database* database)
{
	auto *plik = fopen(database->dbPath, "w+");

	if (!plik) {
		printf("Bląd zapisu pliku\n");
		return;
	}

	for (int i = 0; i < database->recordsCount; i++)
		fprintf(plik, "%s, %lf\n", database->records[i].name, database->records[i].price);

	fclose(plik);
}

void ClearDb(Database* database)
{
	free(database->records);
	database->recordsCount = 0;
}

void PrintTable(Database* database){
	for (int i = 0; i < database->recordsCount; i++) {
		printf("%s \n", database->records[i].name);
		printf("%lf \n", database->records[i].price);
	}
}