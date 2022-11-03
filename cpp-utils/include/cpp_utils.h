#pragma once

#include <string>

namespace lihongbin {
    using namespace std;

    struct Err {
        int    code;
        string msg;
    };

    string trim(string s);
    string& trim_self(string& s);

}