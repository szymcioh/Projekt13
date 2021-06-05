//
// Created by mateu on 03.06.2021.
//

#ifndef PK_PROJEKT_TEMAT_13_INPUT_OUTPUT_DATA_H
#define PK_PROJEKT_TEMAT_13_INPUT_OUTPUT_DATA_H
#include <stdio.h>
#include <stdlib.h>
#include "DatabaseStruct.h"

void AddMultipleItems(Database* database);

void SaveToFileTable(Database* database);

void PrintTable(Database* database);

void ClearDb(Database* database);

#endif //PK_PROJEKT_TEMAT_13_INPUT_OUTPUT_DATA_H
