/*------------------------------------------------------
DownloadMii
� Filiph Sandstr�m 2014-2015

TODO:
* Rename files to "debug.h" and "debug.cpp"

CONTRIBUTORS:
* Filiph Sandstr�m (filfat) - Modified code
* Joostin - Orginal code
------------------------------------------------------*/
#pragma once
#include <3ds.h>
#include "main.h"

extern char superStr[];

s32 printInit(const char *fn);
void printExit(void);
#ifdef DEBUG
	void print(const char *text, ...);

#else

#define DebugStop()
#define print(...) snprintf(&superStr[strlen(superStr)], 9192, __VA_ARGS__); svcOutputDebugString(superStr, 9192);

#endif