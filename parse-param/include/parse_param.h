#pragma once

#include <unordered_map>

namespace lihongbin {
    using namespace std;
    void param_parse(int argc, char *argv[]);
    string param_get_exec();
    bool param_get(string name, string *value);
    bool param_get_all(unordered_map<string, string> *param_map);
}
