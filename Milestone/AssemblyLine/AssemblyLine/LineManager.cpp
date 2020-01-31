#include "LineManager.h"
#include "Utilities.h"

LineManager::LineManager(std::string &filename, std::vector<Task*> &tasks, std::vector<CustomerOrder> &custOrders) {
  std::fstream file(filename);

  if (file.is_open()) {                                                   // Checks if file was successfully opened.
    CustomerOrder_Count = custOrders.size();                              // Set the CustomerOrder_Count to size of customer orders.

    Utilities util;

    while (!file.eof()) {
      size_t startingPoint = 0;
      size_t itemNo = 0;
      bool isMore = true;

      std::string line;
      std::string item;
      std::string next;

      std::getline(file, line);                                           // Stores the line into the string.
      item = util.extractToken(line, startingPoint, isMore);              // Extract item from line and store in string.

      if (isMore) {
        next = util.extractToken(line, startingPoint, isMore);            // Extract next item from line and store in string.
      }

      for (int i = 0; i < tasks.size(); i++) {                            // Loop through and identify which item matches task.
        if (tasks[i]->getName() == item) {
          itemNo = i;                                                     // Assign itemNo to index.
          break;
        }
      }

      if (next.size() != 0) {                                             // Check to see if next item exists.
        for (int i = 0; i < tasks.size(); i++) {
          if (tasks[i]->getName() == next) {
            tasks[itemNo]->setNextTask(*tasks[i]);                        // Set next task.
            break;
          }
        }
      }
      else {
        tasks[itemNo]->setNextTask(*AssemblyLine[0]);                     // Set next task to first element in AssemblyLine vector.
      }

      AssemblyLine.push_back(tasks[itemNo]);                              // Push into the AssemblyLine vector.
    }

    for (int i = 0; i < custOrders.size(); i++) {
      ToBeFilled.push_back(std::move(custOrders[i]));                     // To do: Still causing issues when moving (losing data).
    }
  }
}

bool LineManager::Run(std::ostream& os) {
  for (int i = 0; i < ToBeFilled.size(); i++) {                           // If there are any CustomerOrder objects in the ToBeFilled queue.
    *AssemblyLine[0] += std::move(ToBeFilled[i]);                         // Move the last CustomerOrder object onto the starting point of the AssemblyLine.
    Completed.emplace_back();                                             // Appends a new element to the end of the container. 
  }

  for (int i = 0; i < AssemblyLine.size(); i++) {                         // Loop through all Tasks on the AssemblyLIne and run one cycle of the Tasks process.
    AssemblyLine[i]->RunProcess(os);

    if (i == AssemblyLine.size() - 1) {
      for (int j = 0; j < ToBeFilled.size(); j++) {
        AssemblyLine[0]->getCompleted(Completed[j]);
      }
    }
  }

  if (Completed.size() == ToBeFilled.size()) {                            // Executes when completed orders are the same size as to-be-filled orders.
    os << std::endl << "COMPLETED" << std::endl;

    for (int i = 0; i < Completed.size(); i++) {                          // Loop through display function and should show all filled orders.
      Completed[i].Display(os);
    }

    return true;                                                          // Return true if all objects have been filled.
  }

  return false;
}
