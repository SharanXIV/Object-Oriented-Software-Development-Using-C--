#include <vector>
#include "CustomerOrder.h"
#include "Utilities.h"
#include "Item.h"

// Constructor
CustomerOrder::CustomerOrder() {                                        // Set safe empty state.
  Name = "";
  Product = "";
  ItemCount = 0;
  ItemList = nullptr;
  field_width = 0;
}

// Overloaded Constructor
CustomerOrder::CustomerOrder(std::string& record) {
  Utilities item;
  size_t startingPoint = 0;
  bool isMore = true;
  std::vector <ItemInfo> v;

  Name = item.extractToken(record, startingPoint, isMore);              // Extract the name from record.

  if (field_width < item.getFieldWidth()) {                             // Set the field width to the name.
    field_width = item.getFieldWidth();
  }

  Product = item.extractToken(record, startingPoint, isMore);           // Extract the product from record.

  while (isMore) {                                                      // Extract the parts from record and add into the vector.
    std::string part = item.extractToken(record, startingPoint, isMore);
    v.push_back(part);
  }
  
  ItemList = new ItemInfo*[v.size()];                                   // Find the size and dynamically allocate memory.
  
  for (unsigned int i = 0; i < v.size(); i++) {
    ItemList[i] = nullptr;                                              // Initialize to nullptr. (Don't store garbage addresses)
  }

  for (auto i : v) {                                                    // Loop through vector and populate.
    ItemList[ItemCount++] = new ItemInfo(i.ItemName);
  }
}

// Destructor
CustomerOrder::~CustomerOrder() {
  for (int i = 0; i < ItemCount; i++) {                                 // Deallocate any dynamic memory used.
    delete ItemList[i];
    ItemList[i] = nullptr;                                              // Set addresses to null. Good for memory management.
  }

  ItemList = nullptr;                                                   // Set safe empty state.
  Name = "";
  Product = "";
  ItemCount = 0;
  field_width = 0;
}

// Move Constructor
CustomerOrder::CustomerOrder(CustomerOrder&& src) {
  *this = std::move(src);
}

// Move Assignment Operator
CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) {
  if (this != &src) {                                                   // Check for self-assignment

    //if (ItemList != nullptr) {                              		      // Note to self: This is handled in destructor.
    //  for (unsigned int i = 0; i < ItemCount; i++) {
    //    delete ItemList[i];
    //  }
    //  delete ItemList;
    //}

    // Move data over from source.
    Name = src.Name;
    Product = src.Product;
    ItemCount = src.ItemCount;
    ItemList = src.ItemList;
    field_width = src.field_width;

    // Set source to safe empty state.
    src.Name = "";
    src.Product = "";
    src.ItemCount = 0;
    src.ItemList = nullptr;
    src.field_width = 0;
  }

  return *this;
}

// Member functions

// Returns true if order completely filled, false otherwise
bool CustomerOrder::getOrderFillState() {
  for (unsigned int i = 0; i < ItemCount; i++) {                        // Loop through each item to find where FillState is false.
    if (ItemList[i]->FillState == false) {
      return false;
    }
  }
  return true;
}

// Returns true if the given item has been filled
bool CustomerOrder::getItemFillState(std::string itemName) {
  for (unsigned int i = 0; i < ItemCount; i++) {
    if (ItemList[i]->ItemName == itemName) {                            // Loop through each item to find matching ItemName with string argument.
      return ItemList[i]->FillState;                                    // Return FillState status.
    }
  }

  return true;
}

// Fills the customer order item if the inventory on Item is available
void CustomerOrder::fillItem(Item& _item, std::ostream& os) {
  for (unsigned int i = 0; i < ItemCount; i++) {
    if (ItemList[i]->ItemName == _item.getName() /*&& ItemList[i]->FillState == false*/) {
      ItemList[i]->SerialNumber = _item.getSerialNumber();
      ItemList[i]->FillState = true;

      os << "Filled " << Name << ", " << Product << "[" << ItemList[i]->ItemName << "]" << std::endl;
    }
  }
}

// Displays the details of the CustomerOrder to the ostream object provided
void CustomerOrder::Display(std::ostream& os) {
  os << Name << std::endl;
  os << Product << std::endl;

  for (unsigned int i = 0; i < ItemCount; i++) {
    os << "[" << ItemList[i]->SerialNumber << "]" << ItemList[i]->ItemName << " - " << (ItemList[i]->FillState ? "FILLED" : "MISSING") << std::endl;
  }
}