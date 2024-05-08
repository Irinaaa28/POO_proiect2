#include "NonExistentGarment.h"

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <cstring>

NonExistentGarment::NonExistentGarment(const std::string& message) : std::invalid_argument(message) {}