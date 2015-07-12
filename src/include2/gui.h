/*------------------------------------------------------
					DownloadMii
			� Filiph Sandstr�m 2014-2015

		TODO:
		* Create a universal GUI Library
		* Migrate to that Library

		CONTRIBUTORS:
		* Filiph Sandstr�m (filfat)
		* Lectem
		* AlbertoSONIC
		* celcodioc
		* Joostin
------------------------------------------------------*/
#pragma once

#include <iostream>
#include <string.h>
#include <vector>
#include <3ds.h>
#include "input.h"
#include "draw.h"
#include "ascii64.h"
#include "application.h"
#include "print.h"

/* FLAT DESIGN UI */
#define TOPSCREEN_W 400
#define TOPSCREEN_H 240
#define BOTTOMSCREEN_W 320
#define BOTTOMSCREEN_H 240
#define APPLICATION_ENTRY_W 320
#define APPLICATION_ENTRY_H 75
#define CATEGORY_ENTRY_H 28
#define NAVBAR_H 12
#define SECONDARY_NAVBAR_H 36
#define SHADOW_ANGLE 135
#define MARGIN 0 //No margin
#define APPTITLE_MARGIN ((APPLICATION_ENTRY_H/2) - fontBlackHeader.height) + 12
#define APPVERSION_MARGIN ((APPLICATION_ENTRY_H/2) - fontBlackSubHeader.height) + 24

using namespace std;

struct navBar_s{
	string Title;
	int ID;
	//ToDo
};
struct progressBar_s {
	const int maxProgress = 100;
	int progress = 0;
	bool used;
};
struct Screen_s {
	u8* screenTopLeft, *screenTopRight, *screenBottom;
	bool topUpdated, bottomUpdated;
};
extern Screen_s screen;
extern progressBar_s progressbar;
extern font_s debugfnt;
extern int currentMenu; //0 = overview, 1 = settings, 2 = app page, 3 = downloads(When i fugure out multi-threading), 4 = by dev.
extern Application_s currentApp;
extern Category_s currentCat;
extern vector<Application_s> tAppList;
extern std::vector<Category_s> tCatList;

extern int VSPY;
extern int VSPX;
extern int VSTY;
extern int VSTX;


extern int FPS;

void guiInit();
void draw();
void renderGUI();
void renderStoreFront();
void renderCategories();
void renderSettings();
void renderAppPage();
void renderDebug();
void renderDownloads();
void renderByDev();
void renderUpdate(char* cv, char* rv);
void setAppList(vector<Application_s> AppList);
void fadeOut();
void renderDebugLog();

/* UIs */
void drawTopBar();
void setStoreFrontImg(char* url); //Needs to be: 400x192
void background();
void drawAppEntry(Application_s app, int place);
void drawCategory(Category_s cat, int place, bool subCategory);

/* UI Elements */
Result guiPopup(char* title, char* content, char* b1, char* b2, u8* screen);
Result guiScrollbar(int x, int y, int x2, int y2, u8 procent);


/* TEXT */
void cutLine(char* str);
int countLines(char* str);

/* SCENE */
extern int scene;
extern int maxScene;
extern string sceneTitle;