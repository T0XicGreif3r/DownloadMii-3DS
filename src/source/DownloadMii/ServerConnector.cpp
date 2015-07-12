//    _____                      _                 _ __  __ _ _ 
//   |  __ \                    | |               | |  \/  (_|_)
//   | |  | | _____      ___ __ | | ___   __ _  __| | \  / |_ _ 
//   | |  | |/ _ \ \ /\ / / '_ \| |/ _ \ / _` |/ _` | |\/| | | |
//   | |__| | (_) \ V  V /| | | | | (_) | (_| | (_| | |  | | | |
//   |_____/ \___/ \_/\_/ |_| |_|_|\___/ \__,_|\__,_|_|  |_|_|_|
//                                                              
//   ©2014-2015 Filiph Sandström & Contributors
//   Please see the LICENSE for more info!
#include "main.h"
#include "DownloadMii/ServerConnector.hpp"

DownloadMii::ServerConnector::ServerConnector() {
	/* Init */
#ifdef DOWNLOADMII_PLATFORM_3DS
	httpcInit();
#endif
	testInternetConnection();
}

void DownloadMii::ServerConnector::testInternetConnection() {
	//TODO: load a smaller page for quicker results.
#ifdef DOWNLOADMII_PLATFORM_3DS
	Result result = httpcOpenContext(&HttpcContext, "http://www.downloadmii.com", 0);
	if (result != 0) {
		httpcCloseContext(&HttpcContext);
		InternetConnection = false;
	}
	result = httpcBeginRequest(&HttpcContext);
	if (result != 0) {
		httpcCloseContext(&HttpcContext);
		InternetConnection = false;
	}
	httpcCloseContext(&HttpcContext);
	InternetConnection = true;
#endif
	InternetConnection = false;
}
