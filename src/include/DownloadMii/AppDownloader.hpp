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
//	Description: This file contains everything needed to handle applications
//
#pragma once
#include <iostream>
#include <vector>
#include <zlib.h>

#include "Review.hpp"
#include "ServerConnector.hpp"

namespace DownloadMii {
	struct Application {
		/* Data loaded when reciving the application */
		std::string guid;
		std::string name;
		std::string publisher;
		std::string downloads;
		//Only used when data is cached or if the application is installed
		std::string localVersion = "none";
		bool installed = false;
		float avgRating;

		/* Data loaded by LoadAppInfo */
		std::string description;
		std::string version;
		std::vector<ApplicationReview> reviews;
	};

	class AppDownloader {
	public:
		/* Functions */
		AppDownloader();
		AppDownloader(ServerConnector* serverConnector);
		~AppDownloader();

		/* App Handling */
		void LoadAppInfo(Application &app);

		/* Vars */
		ServerConnector* serverConnector;
	private:
	};
}