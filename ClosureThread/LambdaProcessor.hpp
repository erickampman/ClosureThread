//
//  LambdaProcessor.h
//  ClosureThread
//
//  Created by Eric Kampman on 5/26/21.
//

#ifndef LambdaProcessor_h
#define LambdaProcessor_h

#include <cstdint>

#include "LambdaThread.hpp"

/*
	Example of an object that specifies the run and completion lambda.
	Seems a bit tortured. There are probably better ways to do this.
 */
class LambdaProcessor {
public:
	LambdaProcessor(double start) :
		start_(start),
		thread_([](TLambdaData<LambdaProcessor&> data) {
			std::cout << "runf, data: " << data.data_.start_ << std::endl;
			double temp = 1;
			for (double i = data.data_.start_; i < data.data_.start_ + 1000; ++i) {
				int intI = static_cast<int>(i);
				if (!(intI % 2)) {
					temp *= i;
				} else {
					temp /= i;
				}
			}
			data.data_.result_ = temp;
		},
		[](TLambdaData<LambdaProcessor&> data) {
			std::cout << "compf, result: " << data.data_.result_ << std::endl;
		},
		*this) {}
// 	The below used the private lambdas. 
//		thread_(runf, compf, *this) {}

	void run() { thread_.run(); }
private:
	std::function<void(TLambdaData<LambdaProcessor&>)> runf = [](TLambdaData<LambdaProcessor&> data){
		std::cout << "runf, data: " << data.data_.start_ << std::endl;
		double temp = 1;
		for (double i = data.data_.start_; i < data.data_.start_ + 1000; ++i) {
			int intI = static_cast<int>(i);
			if (!(intI % 2)) {
				temp *= i;
			} else {
				temp /= i;
			}
		}
		data.data_.result_ = temp;
	};
	std::function<void(TLambdaData<LambdaProcessor&>)> compf = [](TLambdaData<LambdaProcessor&> data){
		std::cout << "compf, result: " << data.data_.result_ << std::endl;
	};
	
	double start_;
	double result_;
	LambdaThread<LambdaProcessor&> thread_;
};


#endif /* LambdaProcessor_h */
