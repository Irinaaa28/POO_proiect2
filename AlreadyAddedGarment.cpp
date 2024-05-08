#include "AlreadyAddedGarment.h"

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <cstring>

AlreadyAddedGarment::AlreadyAddedGarment(const std::string& message) : std::runtime_error(message) {}