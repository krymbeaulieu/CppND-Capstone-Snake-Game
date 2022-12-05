#ifndef STRUCTS_H
#define STRUCTS_H

#include <vector>
#include "SDL.h"

struct Widget {
	char name[MAX_NAME_LENGTH];
	int x;
	int y;
	char label[MAX_NAME_LENGTH];
	Widget *prev;
	Widget *next;
}
#endif