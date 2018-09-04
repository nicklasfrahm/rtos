#include <iostream>
#include <windows.h>

HANDLE hello_threads[2];

void thread_one(void)
{
	while (1)
	{
		std::cout << "Hello from thread one!" << std::endl;
    Sleep(1000);	
	}
}

void thread_two(void)
{
	while (1)
	{
		std::cout << "Hello from thread two!" << std::endl;
		Sleep(2000);		
	}
}

int main(void)
{
	hello_threads[0] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_one, NULL, 0, NULL);
	hello_threads[1] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread_two, NULL, 0, NULL);
	
	// use INFINITE instead of 5000 to make program run forever
	WaitForMultipleObjects(2, hello_threads, true, 5000);

	return 0;
}