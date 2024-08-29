#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std;
int f(int a, int b) 
{
	
	cout << "func " << endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	return a + b;
}
int main()
{
	
	/*thread t(f,30,20);
	t.join();*/
	future<int> fu = async(launch::async, f, 30, 50);
	cout << "main start " << endl;
	
	
	cout << "return "  << fu.get() << endl;
	return 0;
}