/*
 * LogHelper.h
 *
 *  Created on: 2018??5??5??
 *      Author: j.chen
 */

#ifndef ANDROID_OBJ_LOGHELPER_H_
#define ANDROID_OBJ_LOGHELPER_H_
#include <string>

class LogHelper {
public:
	~LogHelper();
	static LogHelper* instance();
	bool writeLogI(std::string tag, std::string log);
	bool writeLogW(std::string tag, std::string log);
	bool writeLogE(std::string tag, std::string log);
private:
	LogHelper();
	int id_;
	bool enable_;
};

#endif /* ANDROID_OBJ_LOGHELPER_H_ */
