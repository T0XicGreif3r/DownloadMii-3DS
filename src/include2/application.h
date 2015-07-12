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
//	File name: Application.hpp
//	Description: This file contains the application related function(s) and structure(s)
//
#pragma once

#include <iostream>
#include <3ds.h>
#include <vector>

struct Application_s{
	std::string GUID;
	std::string name;
	std::string publisher;
	std::string version;
	std::string description;
	std::string category;
	std::string subcategory;
	std::string _3dsx, md5_3dsx;
	std::string smdh, md5_smdh;
	std::string appdata, md5_appdata;
	int raiting;
	int downloads;

	bool installed = false, updateAvalible = false, error = false;
};

struct Theme_s {
	std::string GUID;
	std::string name;
	std::string publisher;
	std::string version;
	std::string description;
	std::string category;
	std::string subcategory;
	std::string theme, md5_theme;
	int raiting;
	int downloads;

	bool installed = false, updateAvalible = false, error = false;
};

struct Category_s {
	int ID;
	std::string name;
	bool subCategories;
};

extern std::vector<Application_s> InstalledApps;

Result installApp(Application_s app);
Result updateInstalledList(std::vector<Application_s> &list);
Result dlAndUnZip(char* url, char* path, char* appname);