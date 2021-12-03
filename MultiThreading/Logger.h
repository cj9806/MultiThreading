#pragma once
#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <vector>
#include <string>

class Logger
{
private:
	std::string stringLog;
public:
	//initilize logger file
	void init();
	//accept text in the order it was provided to the log file
	void writeLog();
};

