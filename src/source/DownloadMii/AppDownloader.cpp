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
#include "DownloadMii/AppDownloader.hpp"

namespace DownloadMii {
	AppDownloader::AppDownloader(){} //Shall not be used!
	AppDownloader::AppDownloader(ServerConnector* ServerConnector) {
		serverConnector = ServerConnector;
	}
	AppDownloader::~AppDownloader() {

	}

	void AppDownloader::LoadAppInfo(Application &app) {
		//TODO: Load JSON from web server and deserialize it.
	}
}