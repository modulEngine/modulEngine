#ifndef WINDOW_H
#define WINDOW_H

#include <stdbool.h>

typedef struct LsWindow_T *LsWindow;

typedef struct {
	int width;
	int height;
	char *title;
} LsWindowCreateInfo;

void lsCreateWindow(LsWindowCreateInfo *pCreateInfo, LsWindow *pWindow);
bool lsWindowShouldClose(LsWindow window);
void lsUpdateWindow(LsWindow window);
void lsDestroyWindow(LsWindow window);

#endif //WINDOW_H
