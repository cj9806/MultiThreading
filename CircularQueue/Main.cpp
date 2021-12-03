#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <string>
#include "tCirclularQueue.h"

using std::cout; std::string;

int main() {
	tCirclularQueue<int> test;
	for (int i = 0; i < 25; i++) {
		test.push(i);
	}

	return 0;
}