# Json_Parser
This C ++ program is written in Visual Studio. It accepts an "input.json" file with data in json format as input. At the output, it creates the file "output.json"
with the data in the form of a key - value. 
To work with data in the specified format, the nlohmann library is used. 
The choice of this library for me was determined by several factors: clarity, cross-platform, minimal memory consumption, compatibility with STL, with MinGW, easy connection. 
To use the library,you need to download the file json.hpp from https://github.com/nlohmann/json/releases and add it to the file to the project folder 
Having included it in the file #include "json.hpp"., you can use the namespace of this library - using json = nlohmann::json;
