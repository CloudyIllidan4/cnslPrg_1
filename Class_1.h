#pragma once
#include <fstream>
#include <nlohmann/json.hpp>
#include <iostream>

class Class_1
{
public:
	nlohmann::json is_primitive(nlohmann::json& jsonIn);
	nlohmann::json converterFunc(nlohmann::json& jsonIn);
//private:
	const std::exception myTypeException{ "the transmitted value type is not supported, set default (null)" };
};