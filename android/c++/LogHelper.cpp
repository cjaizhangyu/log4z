/*
 * LogHelper.cpp
 *
 *  Created on: 2018��5��5��
 *      Author: j.chen
 */

#include "LogHelper.h"
#include "log4z.h"
#include "LogSet.h"

#ifdef ANDROID
#include <android/log.h>
#endif

using namespace zsummer::log4z;
#define LOG4Z() ILog4zManager::getPtr()
#define LOGSET() LogSet::instance()

static LogHelper * logHelper = nullptr;

LogHelper* LogHelper::instance() {
	/*if(logHelper == nullptr) {
		logHelper = new LogHelper();
	}
	if(logHelper != nullptr && logHelper->id_ < 0) {
		if(logHelper != nullptr) {
			delete logHelper;
			logHelper = nullptr;
		}*/

		if(logHelper == nullptr) {
			logHelper = new LogHelper();
			logHelper->id_ = LOG4Z()->createLogger("APP");
			LOG4Z()->setLoggerPath(logHelper->id_, LOGSET()->getLogPath().c_str());
			LOG4Z()->enableLogger(logHelper->id_, LOGSET()->isEnable());
			LOG4Z()->setLoggerFileLine(logHelper->id_, false);
			LOG4Z()->setLoggerLevel(logHelper->id_, LOGSET()->getLevel());
			LOG4Z()->setLoggerLimitsize(logHelper->id_, LOGSET()->getFileSizeLimit());
			LOG4Z()->setLoggerOutFile(logHelper->id_, LOGSET()->isOutToFileEnable());
#ifdef ANDROID
			logHelper->enable_ = LOGSET()->isOutToScreenEnable();
#else
			LOG4Z()->setLoggerDisplay(logHelper->id_, LOGSET()->isOutToScreenEnable());
#endif
		}
//	}

	return logHelper;
}

/*typedef enum android_LogPriority {
    ANDROID_LOG_UNKNOWN = 0,
    ANDROID_LOG_DEFAULT,     only for SetMinPriority()
    ANDROID_LOG_VERBOSE,
    ANDROID_LOG_DEBUG,
    ANDROID_LOG_INFO,
    ANDROID_LOG_WARN,
    ANDROID_LOG_ERROR,
    ANDROID_LOG_FATAL,
    ANDROID_LOG_SILENT,      only for SetMinPriority(); must be last
} android_LogPriority;*/

bool LogHelper::writeLogI(std::string tag, std::string log) {
#ifdef ANDROID
	if(enable_) {
		__android_log_print(ANDROID_LOG_INFO, tag.c_str(), "%s", log.c_str());
	}
#endif
    LOG_INFO(id_, log.c_str());
	return true;
}

bool LogHelper::writeLogW(std::string tag, std::string log) {
#ifdef ANDROID
	if(enable_) {
		__android_log_print(ANDROID_LOG_WARN, tag.c_str(), "%s", log.c_str());
	}
#endif
    LOG_WARN(id_, log.c_str());
	return true;
}

bool LogHelper::writeLogE(std::string tag, std::string log) {
#ifdef ANDROID
	if(enable_) {
		__android_log_print(ANDROID_LOG_ERROR, tag.c_str(), "%s", log.c_str());
	}
#endif
	LOG_ERROR(id_, log.c_str());
	return true;
}

LogHelper::LogHelper():id_(-1), enable_(true) {

}

LogHelper::~LogHelper() {}

