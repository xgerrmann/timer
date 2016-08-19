#include "timer.hpp"

int main(){
	timer watch;
	watch.start();
	for(int i = 0; i<20000; i++){
		watch.lap("Loop time");
	}
	watch.stop();

	return 0;
}
