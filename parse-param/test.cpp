#include <iostream>

#include "include/parse_param.h"

using namespace std;

int main(int argc, char *argv[]) {
    lihongbin::param_parse(argc, argv);

    string exec = lihongbin::param_get_exec();
    cout << "exec: " << exec << endl;

    string a;
    bool has_a = lihongbin::param_get("a", &a);

    if (has_a) {
        cout << "a: " << a << endl;
    } else {
        cout << "not a" << endl;
    }

    string A;
    bool has_A = lihongbin::param_get("A", &A);

    if (has_A) {
        cout << "A: " << A << endl;
    } else {
        cout << "not A" << endl;
    }

    string z;
    bool has_z = lihongbin::param_get("z", &z);

    if (has_z) {
        cout << "z: " << z << endl;
    } else {
        cout << "not z" << endl;
    }

    unordered_map<string, string> params;
    lihongbin::param_get_all(&params);
    for (auto begin = params.begin(); begin != params.end(); ++begin) {
        cout << begin->first << ": " << begin->second << endl;
    }

    return 0;
}
