//
//  main.cpp
//  LambdaThread
//
//  Created by Eric Kampman on 5/26/21.
//

#include <iostream>

#include "LambdaThread.hpp"

int main(int argc, const char * argv[]) {
	
	std::function<void(TLambdaData<int>)> runf = [](TLambdaData<int> data){
		std::cout << "run" << std::endl;
	};
	std::function<void(TLambdaData<int>)> compf = [](TLambdaData<int> data){
		std::cout << "completion" << std::endl;
	};
	int data = 0;
	LambdaThread<int> lt(runf, compf, data);
	lt.run();
	
	return 0;
}
