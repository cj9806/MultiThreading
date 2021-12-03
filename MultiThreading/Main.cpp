#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using std::cout;

void print(int i)
{
	static std::mutex myMutex;

	myMutex.lock();
	cout << "Hello Thread\n";
	cout << "this is my second sentence. #" << i+1 << "\n";
	cout << "goodbye\n"; 
	myMutex.unlock();
}

int main() {
	//create a thread that will execute the print function
	std::vector<std::thread> threads;
	for (int i = 0; i < 50; ++i)
	{
		threads.push_back(std::thread(print, i));
	}

	//block execution on the main thread until aThread exits
	for (auto& thread : threads) {
		thread.join();
	}

	return 0;
}