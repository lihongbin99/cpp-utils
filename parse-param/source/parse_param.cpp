#include "../include/parse_param.h"

namespace lihongbin {
    string param_exec;
    unordered_map<string, string> param_short{};
    unordered_map<string, string> param{};

    void param_parse(int argc, char *argv[]) {
        string name;
        string value;

        param_exec = argv[0];
        
        for (int i = 1; i < argc; ++i) {
            if (*(argv[i]) == '-') {
                if (*(argv[i]+1) != '-') {
                    name = argv[i]+1;
                    value = argv[++i];
                    param_short.insert(make_pair(name, value));
                } else {
                    name = argv[i]+2;
                    value = argv[++i];
                    param.insert(make_pair(name, value));
                }
            }
        }
    }

    string param_get_exec() {
        return param_exec;
    }

    bool param_get(string name, string *value) {
        if (param_short.find(name) != param_short.end()) {
            *value = param_short[name];
            return 1;
        }
        if (param.find(name) != param.end()) {
            *value = param[name];
            return 1;
        }
        return 0;
    }

    bool param_get_all(unordered_map<string, string> *param_map) {
        param_map->insert(param_short.begin(), param_short.end());
        for (auto begin = param.begin(); begin != param.end(); ++begin) {
            if (param_map->find(begin->first) == param_map->end()) {
                param_map->insert(make_pair(begin->first, begin->second));
            }
        }
    return 1;
    }

}
