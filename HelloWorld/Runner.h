#pragma once
#include <list>

#include "Thread.h"
#include "uv.h"
#include "MessageQueue.h"

class Runner : public base::Thread
{
public:

	enum RunnerState {
		STARTING,
		RUNNING
	};

	Runner();

	static void OnMessage(uv_async_t* req);

	void Run();
	void PostMessage(VariableType data);
	void HandleMessage();

	void UpdateState(RunnerState runnerState)
	{
		runnerState_ = runnerState;
	}

	bool IsRunning()
	{
		return runnerState_ == RUNNING;
	}

	uv_loop_t* GetLoop()
	{
		return this->loop_;
	}

private:
	MessageQueue messageQueue_;
	uv_loop_t* loop_;
	uv_async_t sig_;
	RunnerState runnerState_;
};

