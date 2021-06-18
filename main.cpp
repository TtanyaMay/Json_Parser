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
			get_value(*it, f);
		}
		else
		{
			f(it);
		}
	}
}

int main(int argc, char** argv)
{
	std::ifstream file("input.json");
	if (!file.is_open())
	{
		std::cerr << "Unable to open file\n";
		throw 1;
	}
	json j;
	file >> j;

	std::multimap<std::string, json> map;
	for (auto const& val : j["a"])
	{
		get_value(val, [&](json::const_iterator it)
			{
				std::cout << "a." << it.key() << "\t" << it.value() << std::endl;
				std::string s = "a." + it.key();
				map.insert({ s, it.value() });
			});
	}
	for (auto const& val : j["c"])
	{
		get_value(j["c"], [&](json::const_iterator it)
			{
				std::cout << "c." << it.key() << "\t" << it.value() << std::endl;
				std::string s = "c." + it.key();
				map.insert({ s, it.value() });
			});
	}
	for (auto const& val : j["d"]) {
		get_value(j["d"], [&](json::const_iterator it)
			{
				std::cout << "d" << " " << "\t" << it.value() << std::endl;
				std::string s = "d";
				map.insert({ s, it.value() });
			});
	}
	std::ofstream o("output.json ");
	for (auto i : map)
	{
		o << i.first << "\t " << i.second << '\n';
	}
	return 0;
};
