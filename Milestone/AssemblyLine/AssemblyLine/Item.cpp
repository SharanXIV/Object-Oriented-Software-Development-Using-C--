#include <string>
#include "Item.h"
#include "Utilities.h"

unsigned int Item::field_width;

// Constructor
Item::Item(std::string& record) {
  Utilities item;
  size_t startingPoint = 0;
  bool isMore;

  this->name = item.extractToken(record, startingPoint, isMore);                       // Extract item name from string.

  if (item.getFieldWidth() > this->field_width) {                                      // Validate the field width and adjust if needed.
    this->field_width = item.getFieldWidth();
  }
  if (isMore) {
    this->serialNumber = std::stoi(item.extractToken(record, startingPoint, isMore));  // Extract item serial number from string if previous extraction was successful.
  }
  if (isMore){
    this->Quantity = std::stoi(item.extractToken(record, startingPoint, isMore));      // Extract item quantity from string if previous extraction was successful.
  }
  if (isMore) {
    this->description = item.extractToken(record, startingPoint, isMore);              // Extract item description from string if previous extraction was successful.
  }
}

// Returns the name of the current Item object.
const std::string& Item::getName() const {
  return this->name;
}

// Returns the next serial number to be used on the assembly line.
const unsigned int Item::getSerialNumber() {
  return this->serialNumber++;
}

// Returns the remaining quantity of the current Item object.
const unsigned int Item::getQuantity() {
  return this->Quantity;
}

// Validates if the quantity is greater than zero and decreases the quantity by one.
void Item::updateQuantity() {
  if (this->Quantity > 0) {
    this->Quantity -= 1;
  }
}

// Writes the name and serialNumber of the Item object to the os. If full status is requested, it will include the quantity and description of the Item object.
void Item::display(std::ostream& os, bool full) const {
  os << std::left << std::setw(field_width) << this->name << " [" << this->serialNumber << "] ";
  
  if (full) {
    os << "Quantity " << std::setw(2) << this->Quantity << "  Description: " << this->description << std::endl;
  }
} 