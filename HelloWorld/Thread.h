#pragma once

#include <iostream>
#include <pthread.h>
#pragma comment(lib, "pthreadVC2.lib")

namespace base {
	class Thread
	{
	public:
		Thread();
		bool Start();
		virtual void Run() = 0;

	private:
		pthread_t thread_id;
	};
}


