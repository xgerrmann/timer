// timer.hpp
// Definition of the timer class
// X.G.Gerrmann
// 18-08-2016

#include <iostream>
#include <chrono>
#include <ctime>

class timer{
	private:
		bool running;
		std::chrono::time_point<std::chrono::steady_clock> time_start, time_start_previous_lap;
		std::chrono::duration<double> time_elapsed;
		void show_time(char* text, bool lap = false);
	public:
		timer();
		void start();
		void lap(char* text);
		void stop(char* text);
};

// Constructor
timer::timer(){
	running = false;
}

// Start function
void timer::start(){
	running		= true;
	time_start	= std::chrono::steady_clock::now();
	time_start_previous_lap = std::chrono::steady_clock::now();
}

// Lap function
void timer::lap(char* text){
	if(running == true){
		show_time(text);
		time_start_previous_lap = std::chrono::steady_clock::now();
	}
	else{
		std::cout << "Timer has not been started yet";
	}
}

// Stop function
void timer::stop(char* text){
	if(running == true){
		show_time(text);
		running		= false;
	}
}

// Show time function
void timer::show_time(char* text, bool lap){
	if(lap){
		time_elapsed	= std::chrono::steady_clock::now()-time_start_previous_lap;
		std::cerr<< text << printf(": Total time: %f",time_elapsed.count()) << std::endl;
	}
	else{
		time_elapsed	= std::chrono::steady_clock::now()-time_start;
		std::cerr<< text << printf(": Elapsed time: %f",time_elapsed.count()) << std::endl;
	}
 }
