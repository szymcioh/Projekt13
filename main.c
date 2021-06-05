#include <stdio.h>
#include "ChangePathFile.h"
#include "Sorting.h"
#include "main.h"
#include "InputOutputData.h"
#include "DatabaseStruct.h"
#include <string.h>
#include "SortingTest.h"
#include <time.h>


int main()
{
	Database database = { 0, 0, "Write.txt"};

	int exitLoop = 0;
	int printSteps = 0;

    while (exitLoop != 1) {

        PrintOptionMainProgram();
        printf("Wybierz: ");
        int Option;
        scanf("%d", &Option);

        switch (Option) {
            case 0:
                AddMultipleItems(&database);
                break;
            case 1:
				PrintTable(&database);
                break;
            case 2:
                QuickSort(&database,0,database.recordsCount-1, printSteps);
                break;
            case 3:
                ShellSort(&database, printSteps);
                break;
            case 4:
                SelectSort(&database, printSteps);
                break;
            case 5:
                ChangePath(&database);
                break;
            case 6:
              	SaveToFileTable(&database);
                break;
			case 7:
				printSteps = 1;
				break;
            case 8:
				TestSorting();
                break;
			case 9:
				exitLoop = 1;
				printf("Koniec programu. Do zobaczenia!");
				break;
            default:
                printf("Nieprawidlowa opcja!");
                break;
        }
    }

	ClearDb(&database);

    return 0;
}

void PrintOptionMainProgram(){
	printf("0 - Dodawanie wielu elementow\n");
	printf("1 - Wyswietlanie tablicy\n");
	printf("2 - QuickSort\n");
	printf("3 - Sortowanie Shella\n");
	printf("4 - Sortowanie przez wybieranie\n");
	printf("5 - Zmiana sciezki do zapisu wyniku\n");
	printf("6 - Zapis do pliku\n");
	printf("7 - Aktywuj wyswietlanie wynikow posrednich\n");
	printf("8 - Wykonaj pomiary czasu sortowania\n");
	printf("9 - Wyjscie z programu\n");
}

