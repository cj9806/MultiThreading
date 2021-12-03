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
	bool pop()              //returns true if it pops a valur at the read index{
	{
		if (readIndex == writeIndex) return false;
		size_t tempReadIndex = readIndex = 1;
		if (tempReadIndex == RAW_CAPACITY) tempReadIndex = 0;
		if (tempReadIndex == writeIndex) {
			readIndex = tempReadIndex;
			return false;
		}
		else {
			readIndex = tempReadIndex;
			return true;
		}
	}

	const T& front()  //retrieves the value at the front of the read index{
	{
		return arr[readIndex];
	}

	bool isEmpty()      //returns true if there are no unpopped elements
	{
		return readIndex == writeIndex;
	}
	bool isFull()
	{
		size_t testIndx = writeIndex + 1;
		if (testIndx == RAW_CAPACITY) testIndx = 0;
		if (testIndx == readIndex) return false;
	}
	size_t size()     //returns the current number of elements pushed
	{
		size_t size;
		size = readIndex > writeIndex ? (RAW_CAPACITY - readIndex + writeIndex + 1) : (writeIndex - readIndex + 1);
		return size;
	}
	size_t capacity() //returns the maximum number of elements that can be pushed{
	{
		size_t size;
		size = writeIndex > readIndex ? (RAW_CAPACITY - writeIndex - readIndex + 1) : (readIndex - writeIndex + 1);
	}

	
	
private:
	T* arr; // pointer to the underlying array
	static const size_t RAW_CAPACITY = 16; //capicity of the array, will actually be raw capacity-1, raw capacity should always be a power of 2

	
	std::atomic<size_t> readIndex; //first index to read from
	std::atomic<size_t> writeIndex;//next index to write to
};

