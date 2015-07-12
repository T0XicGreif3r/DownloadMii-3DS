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
//	File name: User.hpp
//	Description: This file contains the user struct and related function(s)
//
#pragma once
#include <iostream>

namespace DownloadMii {
	struct User {
		std::string guid;
		std::string username;
		unsigned char* avatar;
		bool isPublisher; //True if the user has uploaded and gotten an app approved
	};
}
