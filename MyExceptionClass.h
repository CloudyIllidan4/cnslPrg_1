#pragma once
#include <nlohmann/json.hpp>

class MyExceptionClass : nlohmann::json::exception
{
private:

public:
	MyExceptionClass(char& whatMessage, int& exceptionId)
	{
		nlohmann::json::exception* exceptionObject{};
		exceptionObject->what() = "btr";
		this.id;
		setWhatMessage(char& message) {

		};
	
	};
	
};

