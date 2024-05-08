#include "NothingToRemove.h"

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <cstring>

NothingToRemove::NothingToRemove(const std::string& message) : std::logic_error(message) {}