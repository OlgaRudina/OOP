#include "Task.h"

Task::Task(std::string& str) : Item(str) {
	pNextTask = nullptr;
}

void Task::RunProcess(std::ostream& os) {
	if (!Orders.empty()) {


		if (!Orders.back().getItemFillState(getName())) {
			Orders.back().fillItem(*this, os);
		}

	}
}

bool Task::MoveTask() {
	
	if (Orders.empty()) {
		return false;
	}

	if (pNextTask != nullptr && Orders.back().getItemFillState(getName())) {
		*pNextTask += std::move(Orders.back());
		Orders.pop_back();

	} return true;
	
}

void Task::setNextTask(Task& task) {
	pNextTask = &task;
}

bool Task::getCompleted(CustomerOrder& src) {
	if (!Orders.empty() && Orders.back().getItemFillState(getName())) {
		src = std::move(Orders.back());
		Orders.pop_back();
		return true;
	}
	return false;
}

void Task::Validate(std::ostream& os) {
	os << getName() << std::endl;
	if (pNextTask != nullptr) {
		os << pNextTask->getName() << std::endl;
	}
}

Task& Task::operator+=(CustomerOrder&& newOrder) {
	Orders.push_front(std::move(newOrder));
	return *this;
}