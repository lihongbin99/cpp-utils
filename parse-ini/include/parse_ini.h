#pragma once

#include <iostream>
#include <fstream>
#include <unordered_map>
#include "../../cpp-utils/include/cpp_utils.h"

namespace lihongbin {
    using namespace std;

    Err ini_parse(string iniFile);
    bool ini_get(string section, string name, string *value);
    unordered_map<string, unordered_map<string, string>>* ini_get_all();
}
