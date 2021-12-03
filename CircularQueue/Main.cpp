#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <string>
#include "tCirclularQueue.h"

using std::cout; std::string;

int main() {
	tCirclularQueue<int> test;
	for (int i = 0; i < 15; i++) {
		test.push(i);
	}
	test.pop();
	test.pop();
	test.push(16);
	test.push(17);
	
	return 0;
}