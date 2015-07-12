#include <iostream>
#include <3ds.h>
#include <vector>


using namespace std;

char* getErrorMsg(Result error) {
	switch (error) {
	case 0:
		return "No error";
	case -1:
		return "Generic error";
	case -2:
		return "failed to communicate with the remote api";
	case -3:
		return "Remote server down for unkown reason";
	case -4:
		return "Remote server down for update";
	case -5:
		return "Remote api outdated";
	case -6:
		return "Client api outdated";
	case -7:
		return "Unknown remote api error";
	case -99:
		return "Not yet implamented";
	case -200:
		return "Service closed";
	default:
		return "Unknown error";
	}
}