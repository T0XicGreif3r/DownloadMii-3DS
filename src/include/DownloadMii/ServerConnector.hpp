//    _____                      _                 _ __  __ _ _ 
//   |  __ \                    | |               | |  \/  (_|_)
//   | |  | | _____      ___ __ | | ___   __ _  __| | \  / |_ _ 
//   | |  | |/ _ \ \ /\ / / '_ \| |/ _ \ / _` |/ _` | |\/| | | |
//   | |__| | (_) \ V  V /| | | | | (_) | (_| | (_| | |  | | | |
//   |_____/ \___/ \_/\_/ |_| |_|_|\___/ \__,_|\__,_|_|  |_|_|_|
//                                                              
//   ©2014-2015 Filiph Sandström & Contributors
//   Please see the LICENSE for more info!
//
//	File name: AppDownloader.hpp
//	Description: This file handles ALL server connections
//
#pragma once
#ifdef DOWNLOADMII_PLATFORM_3DS
#include <3ds.h>
#else
#include <curl.h>
#endif

namespace DownloadMii {
	class ServerConnector {
	public:
		ServerConnector();
		void testInternetConnection();

		/* Vars */
		bool InternetConnection = false;
	private:
#ifdef DOWNLOADMII_PLATFORM_3DS
		httpcContext HttpcContext;
#endif
	};
}