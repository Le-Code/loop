#include "MessageQueue.h"

bool MessageQueue::IsEmpty()
{
	return queue_.empty();
}

void MessageQueue::Enqueue(VariableType data)
{
	queue_.push(data);
}

bool MessageQueue::Dequeue(VariableType *res)
{
	if (queue_.empty()) {
		return false;
	}
	*res = queue_.front();
	queue_.pop();
	return true;
}