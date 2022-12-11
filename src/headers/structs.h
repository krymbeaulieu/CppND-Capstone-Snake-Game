#ifndef STRUCTS_H
#define STRUCTS_H

#include <vector>
#include <SDL2/SDL.h>

const int MAX_NAME_LENGTH = 50;
struct Widget {
	char name[MAX_NAME_LENGTH];
	int x;
	int y;
	char label[MAX_NAME_LENGTH];
	Widget *prev;
	Widget *next;
};

class Menu{
	char name[MAX_NAME_LENGTH];
	int x;
	int y;
	int w;
	int h;
	Widget page_buttons;
	bool isOpen;

	void init();
	void update();
	// Renderer::RenderPauseMenu();

};
#endif