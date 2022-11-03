#include <iostream>

#include "include/parse_ini.h"
#include "../parse-param/include/parse_param.h"

using namespace std;

int main(int argc, char *argv[]) {
    lihongbin::param_parse(argc, argv);

    string conf;
    bool has_conf = lihongbin::param_get("conf", &conf);
    if (!has_conf) {
        cout << "not conf" << endl;
        return 0;
    }
    cout << "conf: " << conf << endl;

    lihongbin::Err parse_conf_err = lihongbin::ini_parse(conf);
    if (parse_conf_err.code) {
        cout << "parse conf error: " << parse_conf_err.msg << endl;
        return 0;
    }

    string name2;
    bool has_name2 = lihongbin::ini_get("name2", "abc", &name2);
    if (!has_name2) {
        cout << "not name2" << endl;
    } else {
        cout << "name2: " << name2 << endl;
    }

    auto ini_map = lihongbin::ini_get_all();
    for (auto b1 = ini_map->begin(); b1 != ini_map->end(); ++b1) {
        for (auto b2 = b1->second.begin(); b2 != b1->second.end(); ++b2) {
            cout << b1->first << "." << b2->first << "=" << b2->second << endl;
        }
    }

    return 0;
}
