//
// Created by mateu on 03.06.2021.
//

#include "ItemStruct.h"
#include "DatabaseStruct.h"

#ifndef PK_PROJEKT_TEMAT_13_SORTING_H
#define PK_PROJEKT_TEMAT_13_SORTING_H

void swap(double *first, double *second);

//Szybkie sortowanie
void QuickSort(Database* database, int left, int right, int printSteps);

//Sortowanie Shella
void ShellSort(Database* database, int printSteps);

//Sortowanie przez wybieranie
void SelectSort(Database* database, int printSteps);

//Zamiana dwóch liczb dla SelectSort
void swap(double *first, double *second);

#endif //PK_PROJEKT_TEMAT_13_SORTING_H
