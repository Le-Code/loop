#include "Thread.h"

namespace base {

	Thread::Thread() : thread_id() {}

	static void* ThreadEntry(void* arg) {
		Thread* thread = reinterpret_cast<Thread*>(arg);
		thread->Run();
		return NULL;
	}

	bool Thread::Start()
	{
		int ret = pthread_create(&thread_id, NULL, ThreadEntry, this);
		return ret != 0;
	}
}

