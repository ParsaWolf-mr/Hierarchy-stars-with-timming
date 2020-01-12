#include <iostream>
#include <thread>
#include <chrono>



struct Timming
{
	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
	std::chrono::duration<float>duration;

	Timming() {
		start = std::chrono::high_resolution_clock::now();
	}
	~Timming() {
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;

		auto ms = duration.count() * 1000.0f;
		std::cout << "Timming take " << ms <<  "ms "<<  std::endl;
	}
};


void Function()
{
	Timming time;
	// do something
	for (int i = 1; i <= 10; i++) {
		for (size_t j = 1; j <= 10; j++)
		{
			if (j < 10 - i+1) std::cout << " ";
			else std::cout << "*";	
		}
		if (i > 1)
			for (int l = 1; l < i; l++) {
				std::cout << "*";
			}		
		std::cout << "\n";
	}

}


int main() {

	Function();

	std::cin.get();
}