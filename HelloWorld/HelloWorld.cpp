#include <iostream>
#include <uv.h>
#include <algorithm>
#include "Runner.h"

static void fib(uv_work_t* req)
{
	int n = *(int*)req->data;
	std::cout << "res = " << n << std::endl;
}

void after(uv_work_t* req, int status)
{
	int n = *(int*)req->data;
	std::cout << "after res = " << n << std::endl;
}

int main(void) {
	Runner *workRunner = new Runner();
	workRunner->Start();
	while (!workRunner->IsRunning());
	// postMessage
	std::cout << " running" << std::endl;
	int messages = 10;
	for (int i = 0; i < messages; i++) {
		workRunner->PostMessage(i * 100);
		Sleep(2000);
	}
	
	pthread_exit(NULL);
	return 0;
}