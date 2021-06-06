#pragma once
#include <queue>

using VariableType = int;

class MessageQueue
{
public:
	void Enqueue(VariableType data);
	bool Dequeue(VariableType *res);
	bool IsEmpty();

private:
	std::queue<VariableType> queue_;
};

