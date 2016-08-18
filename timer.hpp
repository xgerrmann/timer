// timer.hpp
// Definition of the timer class
// X.G.Gerrmann
// 18-08-2016

start = std::chrono::system_clock::now();
elapsed_seconds = std::chrono::system_clock::now()-start;
std::cerr << std::printf ("Update estimator: Elapsed time %f",elapsed_seconds.count())<<std::endl;
std::chrono::time_point<std::chrono::system_clock> start, end;
std::chrono::duration<double> elapsed_seconds;

class timer{
	private:
		bool running = false;
		std::chrono::time_point time_start, time_start_previous_lap;
		std::chrono::duration<double> time_elapsed
		show_time(char[] text, bool lap = false);
	public:
		timer();
		start();
		lap(char[] text);
		stop(char[] text);
};

// Constructor
timer::timer(){
}

// Start function
timer::start(){
	started		= true;
	time_start	= std::chromo::steady_clock::now();
	time_start_previous_lap = std::chromo::steady_clock::now();
}

// Lap function
timer::lap(char[] text){
	if(running == true){
		show_time(text);
		time_start_previous_lap = std::chromo::steady_clock::now();
	}
	else{
		std::cout << "Timer has not been started yet";
	}
}

// Stop function
timer::stop(char[] text){
	if(running == true){
		show_time(text);
		running		= false;
	}
}

// Show time function
 timer::show_time(char[] text, bool lap = false){
	if(lap){
		time_elapsed	= std::chromo::steady_clock::now()-time_start_previous_lap;
		std::cerr<< text << printf(": Total time: %f",elapsed_seconds.count()) << std::endl;
	}
	else{
		time_elapsed	= std::chromo::steady_clock::now()-time_start;
		std::cerr<< text << printf(": Elapsed time: %f",elapsed_seconds.count()) << std::endl;
	}
 }
