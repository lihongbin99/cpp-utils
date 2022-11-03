#include "../include/cpp_utils.h"

namespace lihongbin {

    string trim(string s)  {
        string temp = string(s);
        return trim_self(temp);
    }

    string& trim_self(string& s) {
        if (!s.empty())  {
            s.erase(0,s.find_first_not_of(" "));
            s.erase(s.find_last_not_of(" ") + 1);
        }
        return s;
    }

}