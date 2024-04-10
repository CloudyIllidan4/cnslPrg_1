#pragma once
#include <fstream>
#include "MyExceptionClass.h"
#include <iostream>

class Class_1
{
public:
	Class_1(nlohmann::json& jsonIn)
	{
		nlohmann::json classObject{ jsonIn };
		nlohmann::json::exception* exceptionObject{};
	};
	nlohmann::json is_primitive(nlohmann::json& jsonIn);
	nlohmann::json converterFunc(nlohmann::json& jsonIn);

	//nlohmann::json emptyBox{};
//private:
	nlohmann::json exceptionTypeFunc(nlohmann::json& jsonIn);
};