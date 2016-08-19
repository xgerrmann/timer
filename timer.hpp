// timer.hpp
// Definition of the timer class
// X.G.Gerrmann
// 18-08-2016

#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <chrono>
#include <ctime>

class timer{
	private:
		bool running;
		std::chrono::time_point<std::chrono::steady_clock> time_start, time_start_previous_lap;
		std::chrono::duration<double> time_elapsed;
		void show_time(std::string text, bool lap = false);
	public:
		timer();
		void start();
		void lap(std::string text);
		void stop(std::string text);
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
void timer::lap(std::string text){
	if(running == true,true){
		show_time(text);
		time_start_previous_lap = std::chrono::steady_clock::now();
	}
	else{
		std::cout << "Timer has not been started yet";
	}
}

// Stop function
void timer::stop(std::string text){
	if(running == true){
		show_time(text,false);
		running		= false;
	}
	else{
		std::cout << "Timer has not been started yet";
	}
}

// Show time function
void timer::show_time(std::string text, bool lap){
	if(lap){
		time_elapsed	= std::chrono::steady_clock::now()-time_start_previous_lap;
		std::cerr<< text << ": Total time: " << time_elapsed.count() << std::endl;
	}
	else{
		time_elapsed	= std::chrono::steady_clock::now()-time_start;
		std::cerr<< text << ": Elapsed time: " << time_elapsed.count() << std::endl;
	}
 }

#endif
