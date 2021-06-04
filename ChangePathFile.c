# include "ChangePathFile.h"
#include "DatabaseStruct.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>

//Zmiana sciezki zapisu
void ChangePath(Database* database)
{
	PrintOptionFilePath();

	int optionRenameFile;
	scanf("%d", &optionRenameFile);

	switch (optionRenameFile)
	{
	case 1:        //wlasna sciezka
		PathFileChange(database);
		printf("Ustawiono na sciezke: %s\n", database->dbPath);
		break;

	case 2:        //domysla sciezka
		strcpy(database->dbPath,"Write.txt");
		printf("Ustawiono na sciezke domysla: %s\n", database->dbPath);
		break;

	default:
		printf("%s", "Zla opcja!");
	}
}

void PathFileChange(Database* database){
	printf("Podaj sciezke do pliku: ");
	scanf("%s", database->dbPath);
	strcat(database->dbPath, ".txt");
}

void PrintOptionFilePath(){
	printf("%s","Sciezka do pliku.\n");
	printf("%s","1- Wprowadz wlasna sciezke do pliku.\n");
	printf("%s","2- Uzyj folderu domyslnego.\n");
}
