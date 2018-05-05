/*
 * LogSet.cpp
 *
 *  Created on: 2018��5��5��
 *      Author: j.chen
 */
#ifdef ANDROID
#include <android/log.h>
#endif
#include "LogSet.h"
#include "log4z.h"

static LogSet* nativeObj = nullptr;

LogSet* LogSet::instance() {
	if(nativeObj == nullptr) {
		nativeObj = new LogSet();
	}
	return nativeObj;
}

bool LogSet::setPath(std::string path) {
	path_ = path;
	zsummer::log4z::ILog4zManager::getPtr()->setLoggerPath(0, path_.c_str());
	return true;
}

bool LogSet::setEnable(bool enable) {
	enable_ = enable;
	return true;
}

bool LogSet::setLevel(int level) {
	switch (level) {
		case LOG_LEVEL_TRACE:
		case LOG_LEVEL_DEBUG:
		case LOG_LEVEL_INFO:
		case LOG_LEVEL_WARN:
		case LOG_LEVEL_ERROR:
		case LOG_LEVEL_ALARM:
		case LOG_LEVEL_FATAL:
			level_ = level;
			break;

		default:
			return false;
	}
	return true;
}

bool LogSet::setOutToScreen(bool enable) {
	display_ = enable;
	return true;
}

bool LogSet::setOutToFile(bool enable) {
	file_ = enable;
	return true;
}

bool LogSet::setFileSizeLimit(int size) {
	if(size < 1) {
		return false;
	}

	fileSize_ = size;
	return true;
}
bool LogSet::logStart() {
#ifdef ANDROID
	if(enable_) {
		__android_log_print(ANDROID_LOG_ERROR, "LogSet" , "path : %s , enable : %d, display : %d, file : %d, level : %d",
		path_.c_str(), enable_, display_, file_, level_);
	}
#endif
	return zsummer::log4z::ILog4zManager::getPtr()->start();
}

std::string LogSet::getLogPath() {
	return path_;
}

bool LogSet::isEnable() {
	return enable_;
}

bool LogSet::isOutToScreenEnable() {
	return display_;
}

bool LogSet::isOutToFileEnable() {
	return file_;
}

int LogSet::getLevel() {
	return level_;
}

int LogSet::getFileSizeLimit() {
	return fileSize_;
}

LogSet::LogSet():file_(false), display_(true), enable_(true), level_(LOG_LEVEL_INFO), fileSize_(20) {}

LogSet::~LogSet() {
	// TODO Auto-generated destructor stub
}

