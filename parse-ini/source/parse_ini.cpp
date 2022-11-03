#include "../include/parse_ini.h"

namespace lihongbin {

    unordered_map<string, unordered_map<string, string>> ini_map{};

    Err ini_parse(string ini_file) {
        Err result = Err{0, ""};

        fstream io(ini_file, ios_base::in);
        if (!io.is_open()) {
            return Err{1, "ini open file error: " + ini_file};
        }

        char buf[1024 * 64]{0};
        string prev_section;
        while (io.getline(buf, sizeof(buf))) {
            string line = buf;
            lihongbin::trim_self(line);

            if (line.size() <= 0 || line[0] == ';') {
                continue;
            }

            if (line[0] == '[') {
                if (line[line.size()-1] != ']') {
                    result = Err{1, "ini section not ]: " + line};
                    break;
                }
                string section = line.substr(1, line.size()-2);
                lihongbin::trim_self(section);
                
                if (ini_map.find(section) == ini_map.end()) {
                    ini_map.insert(make_pair(section, unordered_map<string, string>{}));
                }
                prev_section = section;
            } else {
                size_t index = line.find_first_of("=");
                if (index == string::npos) {
                    result = Err{1, "ini config not =: " + line};
                    break;
                }
                string name = line.substr(0, index);
                lihongbin::trim_self(name);
                string value = line.substr(index+1);
                lihongbin::trim_self(value);

                if (ini_map.find(prev_section) == ini_map.end()) {
                    ini_map.insert(make_pair(prev_section, unordered_map<string, string>{}));
                }
                ini_map[prev_section].insert(make_pair(name, value));
            }
        }

        io.close();
        return result;
    }

    bool ini_get(string section, string name, string *value) {
        if (ini_map.find(section) == ini_map.end()) {
            return 0;
        }
        auto configs = ini_map[section];
        if (configs.find(name) == configs.end()) {
            return 0;
        }
        *value = configs[name];
        return 1;
    }

    unordered_map<string, unordered_map<string, string>>* ini_get_all() {
        return &ini_map;
    }

}
