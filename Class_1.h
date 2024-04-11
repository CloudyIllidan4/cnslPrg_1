#pragma once
#include <fstream>
#include "MyExceptionClass.h"
#include <iostream>

class Class_1 : nlohmann::json
{
public:
	Class_1() {};
	nlohmann::json is_primitive(nlohmann::json& jsonIn);
	nlohmann::json converterFunc(nlohmann::json& jsonIn);

	//nlohmann::json emptyBox{};
//private:
	std::exception exceptionTypeFunc(nlohmann::json& jsonIn);
};