#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;
template<class UnaryFunction>

void get_value(const json& j, UnaryFunction f)
{
	for (auto it = j.begin(); it != j.end(); ++it)
	{
		if (it->is_structured())
		{
			recursive_iterate(*it, f);
		}
		else
		{
			f(it);
		}
	}
}
int main(int argc, char** argv) {
	std::ifstream i("input.json");
	json j = json::parse(i);
	std::multimap<std::string, json> map;

	get_value(j, [&](json::const_iterator it)
		{
			map.insert({ it.key(), it.value() });
		});
	std::ofstream o("output.json ");
	for (auto i : map)
	{
		std::cout << i.first << "\t " << i.second << '\n';
	}
	for (auto i : map)
	{
		o << i.first << "\t " << i.second << '\n';
	}
	return 0;
};