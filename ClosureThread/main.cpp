//
//  main.cpp
//  LambdaThread
//
//  Created by Eric Kampman on 5/26/21.
//

#include <iostream>

#include "LambdaThread.hpp"
#include "LambdaProcessor.hpp"

int main(int argc, const char * argv[]) {
	
	std::cout << "--------------------------------------------------------------------------------" << std::endl;
	std::function<void(TLambdaData<int>)> runf = [](TLambdaData<int> data){
		std::cout << "runf, data: " << data.data_ << std::endl;
	};
	std::function<void(TLambdaData<int>)> compf = [](TLambdaData<int> data){
		std::cout << "compf, data: " << data.data_ << std::endl;
	};
	int data = 0;
	LambdaThread<int> lt(runf, compf, data);
	lt.run();
	
	data = 1;
	std::cout << "--------------------------------------------------------------------------------" << std::endl;
	LambdaThread<int> lt2([](TLambdaData<int> data){
			std::cout << "run lt2, data: " << data.data_ << std::endl;
		},
		[](TLambdaData<int> data){
			std::cout << "completion lt2, data: " << data.data_ << std::endl;
		},
		data);
	lt2.run();
	
	std::cout << "--------------------------------------------------------------------------------" << std::endl;

	LambdaProcessor lp(200);
	lp.run();
	return 0;
}
