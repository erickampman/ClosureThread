//
//  LambdaThread.hpp
//  LambdaThread
//
//  Created by Eric Kampman on 5/26/21.
//

#ifndef LambdaThread_h
#define LambdaThread_h

#include <functional>
#include <algorithm>
#include <thread>


template<typename T> struct TLambdaData {
	std::function<void(TLambdaData)> run_;
	std::function<void(TLambdaData)> completion_;
	T data_;
	
	TLambdaData(std::function<void(TLambdaData)> run,
				std::function<void(TLambdaData)> completion,
				T data)
	: run_(run), completion_(completion), data_(data) {}
};

template<typename T> class LambdaThread {
public:
	LambdaThread<T>(std::function<void(TLambdaData<T>)> run,
					 std::function<void(TLambdaData<T>)> completion,
					 T data)
		: data(run, completion, data) {}
	
	virtual ~LambdaThread<T>() {
		// FIXME
		std::cout << "~LambdaThread" << std::endl;
	}
	void run() {
		data.run_(data);
		data.completion_(data);
	}

private:
	TLambdaData<T> data;
	std::thread *thread;
};
	

#endif /* LambdaThread_h */
