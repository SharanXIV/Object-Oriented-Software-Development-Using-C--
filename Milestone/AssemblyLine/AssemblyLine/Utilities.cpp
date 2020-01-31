#include <iostream>
#include "Utilities.h"

char Utilities::delimiter;

// Constructor
Utilities::Utilities() {
  field_width = 1;
}

// Sets the field width of the current object to fw.
void Utilities::setFieldWidth(size_t fw) {
  field_width = fw;
}

// Returns the field width of the current object.
size_t Utilities::getFieldWidth() const {
  return this->field_width;
}

// Extracts the token using the starting point, delimiter and sets a flag to continue extracting.
const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
  std::string token;
  int delim_pos = str.find(delimiter, next_pos);                   // Find the position of the next delimiter from 'next_pos'.

  if (delim_pos == -1) {                                           // If delimiter is not found, set the delimiter to the end of the line.
    delim_pos = str.size();
  }

  token = str.substr(next_pos, (delim_pos - next_pos));            // Store the string starting from 'next_pos' to position of delimiter.

  if (token == "") {                                               // Checks to see if token is empty. (takes whitespace as token).
    more = false;                                                  // If so, it sets the flag to false and reports exception.
    throw "Error: There is no token between delimiters.";
  }
  else {
    more = true;
  }

  if (str.substr(next_pos).find(delimiter) == std::string::npos) { // Check to see if string is at the end, setting more to false.
    more = false;                                                  
  }
  else {
    more = true;
  }

  if (field_width < token.size()) {                                // See if field width needs to be adjusted to the size of the token.
    field_width = token.size();
  }

  next_pos = delim_pos + 1;                                        // Adjust the starting location to after the previously used delimiter.

  return token;
}

// Sets the delimiter for this class to the character received.
void Utilities::setDelimiter(const char delim) {
  delimiter = delim;
}

// Returns the delimiter character of the current object.
const char Utilities::getDelimiter() const {
  return this->delimiter;
}