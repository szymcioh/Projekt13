//
// Created by szymo on 04.06.2021.
//

#include "ItemStruct.h"

#ifndef PK_PROJEKT_TEMAT_13__DATABASESTRUCT_H
#define PK_PROJEKT_TEMAT_13__DATABASESTRUCT_H

struct DatabaseStruct
{
	int recordsCount;
	Item * records;

	char dbPath[100];
};

typedef struct DatabaseStruct Database;

#endif //PK_PROJEKT_TEMAT_13__DATABASESTRUCT_H
