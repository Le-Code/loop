#include "Runner.h"

static std::list<Runner*> runners;

Runner::Runner() : messageQueue_(), sig_(), runnerState_(STARTING)
{
	runners.emplace_back(this);
}

void Runner::OnMessage(uv_async_t* req)
{
	for (Runner* runner : runners) {
		if (runner->GetLoop() == req->loop) {
			runner->HandleMessage();
		}
	}
}

void Runner::Run()
{
	std::cout << "loop start" << std::endl;
	if (loop_ == nullptr) {
		loop_ = uv_loop_new();
	}
	uv_async_init(loop_, &sig_, reinterpret_cast<uv_async_cb>(Runner::OnMessage));
	UpdateState(RUNNING);
	std::cout << "async init" << std::endl;
	uv_run(loop_, UV_RUN_DEFAULT);
	std::cout << "uv_run" << std::endl;
}

void Runner::HandleMessage()
{
	VariableType data = NULL;
	while (messageQueue_.Dequeue(&data)) {
		std::cout << data << std::endl;
	}
}

void Runner::PostMessage(VariableType data)
{
	messageQueue_.Enqueue(data);
	uv_async_send(&sig_);
}