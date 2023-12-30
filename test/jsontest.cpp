#include <fstream>
#include <iostream>
#include "utils/json.hpp"
#include <vector>
#include <unordered_set>
#include <unordered_map>

using json = nlohmann::json;

// https://github.com/nlohmann/json

int main()
{
    std::ifstream f("test.json");
    json data = json::parse(f);
    f.close();

    std::cout << data["name"] << std::endl;
    std::cout << data.dump() << std::endl;
    data["name"] = "fc";

    int age = data["age"].get<int>();
    std::cout << age << std::endl;

    std::ofstream o("test2.json");
    o << data.dump(4) << std::endl;
    o.close();
    
    std::vector<int> v = {1, 2, 3};
    json j(v);
    std::cout << j.dump() << std::endl;

    std::unordered_set<int> s = {1, 2, 3};
    json j2(s);
    std::cout << j2.dump() << std::endl;

    std::unordered_map<std::string, int> m = {{"one", 1}, {"two", 2}, {"three", 3}};
    json j3(m);
    std::cout << j3.dump() << std::endl;

    return 0;
}