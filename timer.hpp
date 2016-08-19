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
	public:
		timer();
		void start();
		double lap(std::string text);
		double stop();

		typedef std::chrono::time_point<std::chrono::steady_clock> tp; // define ts as a timestamp
		static tp now();
	
	private:
		bool running;
		tp time_start, time_start_previous_lap;
		std::chrono::duration<double> time_elapsed;
		double show_time(std::string text, bool lap = false);
};

// Constructor
timer::timer(){
	running = false;
}

// Start function
void timer::start(){
	tp time_tmp;
	running		= true;
	time_tmp	= std::chrono::steady_clock::now();
	time_start	= time_tmp;
	time_start_previous_lap = time_tmp;
}

// Lap function
double timer::lap(std::string text){
	double t = 0;
	if(running == true){
		t = show_time(text,true);
		time_start_previous_lap =  std::chrono::steady_clock::now();
	}
	else{
		std::cout << "Timer has not been started yet";
	}
	return t;
}

// Stop function
double timer::stop(){
	double t = 0;
	if(running == true){
		t		= show_time("",false);
		running	= false;
	}
	else{
		std::cout << "Timer has not been started yet";
	}
	return t;
}

// Show time function
double timer::show_time(std::string text, bool lap){
	if(lap){
		time_elapsed	= std::chrono::steady_clock::now()-time_start_previous_lap;
		std::cerr<< text << ": Elapsed time: " << time_elapsed.count() << std::endl;
	}
	else{
		time_elapsed	= std::chrono::steady_clock::now()-time_start;
		std::cerr<< "Total time: " << time_elapsed.count() << std::endl;
	}
	return (double) time_elapsed.count();
 }

//
timer::tp now(){
	return std::chrono::steady_clock::now();
}

#endif
