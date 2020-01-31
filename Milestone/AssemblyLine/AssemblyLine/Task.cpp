#include "Task.h"

// Constructor
Task::Task(std::string &str): Item(str) {
  pNextTask = nullptr;
}

// Fills the last order on the order queue.
void Task::RunProcess(std::ostream &os) {
  while (!Orders.empty()) {                                                         // Check if customer orders are empty.
    while (Orders.back().getItemFillState(this->getName()) == false) {              // Verify the fill status of the last CustomerOrder.
      Orders.back().fillItem(*this, os);                                            // Fill the item.
    }
    if (pNextTask != nullptr) {
      *pNextTask += std::move(Orders.back());
      Orders.pop_back();                                                            // Remove last element from deque.
    }
  }                                                                                 // Continue to loop until all elements are removed from deque.
}

// Moves the completed task to the next part of the assembly line.
bool Task::MoveTask() {
  if (!Orders.empty()) {                                                            // Checks to see if Orders deque is not empty.
    if (pNextTask) {
      if (Orders.back().getItemFillState(this->getName())) {
        *pNextTask += std::move(Orders.back());
        Orders.pop_back();                                                          // Remove last element from deque.
      }
    }
    return true;
  }
  else {
    return false;                                                                   // Return false if deque is empty.
  }
}

// Sets up the pointer to the next task if the tasks names line up.
void Task::setNextTask(Task& task) {
  pNextTask = &task;
}

// Removes the last CustomerOrder from the queue, places it in src and returns true.
bool Task::getCompleted(CustomerOrder &src) {
  if (!Orders.empty()) {
    src = std::move(Orders.back());                                                 // Removes the last CustomerOrder.
    Orders.pop_back();                                                              // Removes the last element from deque.
    return true;
  }
  else {
    return false;
  }
}

void Task::Validate(std::ostream &os) {
  os << "Current Task Item: " << getName() << "Next: ";
  os << (pNextTask ? pNextTask->getName() : "***End of Items***");
  os << std::endl;
}

// Moves the newOrder onto the front of the CustomerOrder queue.
Task& Task::operator+=(CustomerOrder &&newOrder) {
  Orders.push_front(std::move(newOrder));
  return *this;
}