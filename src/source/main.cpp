//    _____                      _                 _ __  __ _ _ 
//   |  __ \                    | |               | |  \/  (_|_)
//   | |  | | _____      ___ __ | | ___   __ _  __| | \  / |_ _ 
//   | |  | |/ _ \ \ /\ / / '_ \| |/ _ \ / _` |/ _` | |\/| | | |
//   | |__| | (_) \ V  V /| | | | | (_) | (_| | (_| | |  | | | |
//   |_____/ \___/ \_/\_/ |_| |_|_|\___/ \__,_|\__,_|_|  |_|_|_|
//                                                              
//   ©2014-2015 filfat Studios AB
//   Please see the LICENSE for more info!

#include <iostream>
#include <stdio.h>
#include <3ds.h>
#include <3DS_UI.h>
#include "DownloadMii.hpp"

/* Data files */
#include "Splash_png.h"

DownloadMii::DownloadMii DownloadMiiCore;

void DoSplashScreen() {
	uiWindow splashScreen = uiWindow(true);
	splashScreen.set3D(false);
	uiImage img = uiImage("SplashScreenIMG1");
	img.configure({ 0,0 }, SCREEN_TOP_WIDTH, SCREEN_TOP_WIDTH, uiCreateTexture((u8*)Splash_png, "PNG", SCREEN_TOP_WIDTH, SCREEN_TOP_WIDTH));
	splashScreen.addElement(&img);
	splashScreen.render();
	uiFinishRendering();
}

int main(int argc, char** argv) {
	srvInit();
	aptInit();
	hidInit(NULL);
	uiInit();

	DoSplashScreen();

	DownloadMiiCore = DownloadMii::DownloadMii();
	
	uiWindow* windowTop = new uiWindow(true);
	windowTop->setNavbarHeader("DownloadMii");
	
	while (aptMainLoop())
	{
		hidScanInput();
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START) break;

		windowTop->render();
		uiFinishRendering();
	}

	uiExit();
	hidExit();
	aptExit();
	return 0;
}