#include <ctime>

class Timer{
private:
	clock_t start;
public:
	double count(){
		clock_t end = clock();
		return (double)(end-start)/CLOCKS_PER_SEC;
	};
	void begin(){
		start = clock();
	};
};
