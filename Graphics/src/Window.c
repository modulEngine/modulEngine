#include "Window.h"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

// std
#include <stdlib.h>
#include <stdio.h>

struct LsWindow_T {
	int width;
	int height;
	char *title;
	GLFWwindow *pWindow;
};

static bool GlfwIsInitiated = false;
static int WindowCount = 0;

bool initGlfw(void (callback(int, const char *)));
void makeContextCurrent(LsWindow window);
void terminateGlfw();

void error_callback(int error_code, const char *error_message) {
	fprintf(stderr, "%s\n", error_message);
	exit(error_code);
}

void setGlfwErrorCallback(void(*errorCallback(int, const char *))) {
	glfwSetErrorCallback((GLFWerrorfun)errorCallback);
}

void lsCreateWindow(LsWindowCreateInfo *pCreateInfo, struct LsWindow_T **pWindow) {
	if (pWindow == NULL) {
		return;
	}

	if (!GlfwIsInitiated) {
		if (initGlfw(error_callback)) {
			GlfwIsInitiated = true;
		} else {
			*pWindow = NULL;
			return;
		}
	}

	struct LsWindow_T *result = malloc(sizeof(struct LsWindow_T));

	result->width = pCreateInfo->width;
	result->height = pCreateInfo->height;
	result->title = pCreateInfo->title;

	result->pWindow = glfwCreateWindow(result->width, result->height, result->title, NULL, NULL);
	if (result->pWindow == NULL) {
		*pWindow = NULL;
		return;
	}

	WindowCount++;
	*pWindow = result;
	makeContextCurrent(*pWindow);
}

bool lsWindowShouldClose(LsWindow window) {
	return glfwWindowShouldClose(window->pWindow);
}

void lsUpdateWindow(LsWindow window) {
	glfwSwapBuffers(window->pWindow);
	glfwPollEvents();
}

void lsDestroyWindow(LsWindow window) {
	glfwDestroyWindow(window->pWindow);
	free(window);
	WindowCount--;

	if (WindowCount == 0) {
		terminateGlfw();
	}
}

bool initGlfw(void (errorCallback(int, const char *))) {
	if (glfwInit() != GLFW_TRUE) {
		const char *description;
		int code = glfwGetError(&description);
		errorCallback(code, description);
		return false;
	}
	return true;
}

void makeContextCurrent(LsWindow window) {
	glfwMakeContextCurrent(window->pWindow);
}

void terminateGlfw() {
	glfwTerminate();
}
