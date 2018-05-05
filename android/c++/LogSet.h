/*
 * LogSet.h
 *
 *  Created on: 2018��5��5��
 *      Author: j.chen
 */

#ifndef ANDROID_LOGSET_H_
#define ANDROID_LOGSET_H_
#include <string>
class LogSet {
public:
	static LogSet *instance();
	~LogSet();
	bool setPath(std::string path);
	bool setEnable(bool enable);
	bool setLevel(int level);
	bool setOutToScreen(bool enable);
	bool setOutToFile(bool enable);
	bool setFileSizeLimit(int size);

	std::string getLogPath();
	bool isEnable();
	bool isOutToScreenEnable();
	bool isOutToFileEnable();
	int getLevel();
	int getFileSizeLimit();
	bool logStart();

private:
	std::string path_;
	bool enable_;
	bool display_;
	bool file_;
	int level_;
	int fileSize_;
	LogSet();
};

#endif /* ANDROID_LOGSET_H_ */
