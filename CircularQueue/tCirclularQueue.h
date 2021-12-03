#pragma once

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <atomic>

template <typename T>
class tCirclularQueue
{
public:
	tCirclularQueue()  : readIndex(0) , writeIndex(0) //dynamically allocate array 
	{
		arr = new T[RAW_CAPACITY];
	}
	~tCirclularQueue()//cleans up dynamically allocated data
	{
		delete[] arr;
	}

	bool push(const T& val) //returns true if it writes a value to the write index, otherwise it returns false
	{
		size_t tempWriteIndex = writeIndex + 1;
		if (tempWriteIndex == RAW_CAPACITY) tempWriteIndex = 0;
		if (tempWriteIndex == readIndex) {
			std::cout << "adress already occupied" << std::endl;
			return false;
		}
		else
		{
			arr[writeIndex] = val;
			writeIndex = tempWriteIndex;
			return true;

		}
	}
	bool pop();

	const T& front() const;  //retrieves the value at the front of the read index

	bool empty() const;      //returns true if there are no unpopped elements
	size_t size() const;     //returns the current number of elements pushed
	size_t capacity() const; //returns the maximum number of elements that can be pushed
	
private:
	T* arr; // pointer to the underlying array
	static const size_t RAW_CAPACITY = 16; //capicity of the array, will actually be raw capacity-1, raw capacity should always be a power of 2

	
	std::atomic<size_t> readIndex; //first index to read from
	std::atomic<size_t> writeIndex;//next index to write to
};

