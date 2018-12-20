#include <iostream>
#include <thread>
#include <chrono> 

using namespace std;


float a = 0;
float b = 0;
float c = 0;

void process1() {
		
	while (true) {
		a = a + 1;
	
	}
}

void process2() {

	while (true)
	{
		b = b + 1;
		
	}

}

void process3() {

	while (true)
	{
		c = c + 1;

	}

}

void timer() {

	while (true)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));

		cout << "a:" << (a/1000)/1000 << "|b:" << (b/1000)/1000 <<"|c:"<<(c/1000)/1000<<endl;

		a = 0;
		b = 0;
		c = 0;
	}
	
}

int main() {

	std::thread one(process1);
	std::thread dos(process2);
	std::thread t(process3);

	std::thread tres(timer);

	one.join();
	dos.join();
	t.join();
	tres.join();
	cin.get();

}