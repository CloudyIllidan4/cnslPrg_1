#pragma once
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

using json = nlohmann::json;

auto is_primitive(json& jsonIn)
{

	//if (jsonIn.type() == json::value_t::boolean)

	if (jsonIn.is_boolean())
	{
		jsonIn = !jsonIn;
		return jsonIn;
	}
	else if (jsonIn.is_string())
	{
		json::string_t&& tempStr = jsonIn.template get<json::string_t>();
		std::reverse(tempStr.begin(), tempStr.end());
		//std::cout << " - in begin - " << *jsonIn.begin() << " - type - " << *jsonIn.type_name() << std::endl;
		jsonIn = tempStr; // ?�� ������� ��� ������� ����� ������ (������� ������)?
		//std::cout << " - in primitive - " << jsonIn << " - type - " << jsonIn.type_name() << std::endl;
		return jsonIn; // � JSON ���������� ����� � ���������� �������
	}
	else if (jsonIn.is_number_integer())
	{
		//jsonIn =+ 1; // ?���������� ������ ������� �������� 1?
		jsonIn = jsonIn + 1;
		//std::cout << " - if int - " << jsonIn << " - type - " << *jsonIn.type_name() << std::endl;
		return jsonIn;
	}
	else if (jsonIn.is_number_float())
	{
		jsonIn = jsonIn + 1.1000f;
		std::cout << " - if flt - " << jsonIn << " - type - " << *jsonIn.type_name() << std::endl;
		return jsonIn; // �� ������ ��������� ����������� �������� (� ������� �����)
	}
	else
	{
		return jsonIn; // ������� ������ ����
	};
};

json converterFunc(json& jsonIn)
{
	try
	{

		//int n{ number_call }; // ������� ����������
		/*
		if () // ?��� ������ ��������� ����� �� �����?
		{
			std::cout << "sum of the primitives: " << n << std::endl;
		};
		*/
		//std::cout << jsonIn << std::endl;

		if (jsonIn.is_object())
		{

			/*
			json::iterator iter{ jsonIn.begin() };
			for (auto x{ iter }; x != jsonIn.end(); x++)
			{
			*/
			//json jsonResult{};
			//json jsonTemp{};

			for (auto& x : jsonIn.items())
			{

				//jsonTemp[x.key()] = x.value();
				//std::cout << x.value().type_name() << std::endl;

				std::cout << x.key() << " - " << jsonIn[x.key()] << " - 1st out message - " << *jsonIn[x.key()].type_name() << std::endl;
				jsonIn[x.key()] = converterFunc(x.value());
				//std::cout << " - " << jsonIn << " - 2 - " << std::endl;

				/*
				if (jsonTemp[x.key()].is_boolean()) {
					jsonTemp[x.key()] = !jsonTemp[x.key()];

					std::cout << jsonTemp[x.key()] << " - jsonTemp - " << jsonTemp[x.key()].type_name() << std::endl;
				}
				else
				{
					jsonResult[x.key()], number_call = converterFunc(jsonTemp[x.key()], number_call);
					std::cout << jsonResult[x.key()] << " - jsonResult - " << jsonResult[x.key()].type_name() << std::endl;

				}
				*/
				//	jsonResult[x.key()], number_call = converterFunc(jsonTemp[x.key()], number_call);
				////std::cout << std::boolalpha << jsonResult.contains(x.key()) << std::endl;
				//std::cout << jsonResult[x.key()] << " - jsonResult - " << jsonResult[x.key()].type_name() << std::endl;
				////return converterFunc(jsonTemp);
				//return jsonResult;
				//jsonResult[x.key()].operator=(converterFunc(jsonTemp));
				//std::cout << x.key() << std::endl;	

			};
			//std::cout << jsonIn << " -  - " << *jsonIn.type_name() << std::endl;
			return jsonIn;

			//json jsonTemp = [x.key(), x.value()];
			//json jsonTemp = json::parse([x.key(), x.value()]);
			//return converterFunc(jsonTemp);
		}
		/*
		/*
		else if (jsonIn.is_number())
		{
			if (jsonIn.is_number_integer())
			{
				number_call++;
				auto limit = jsonIn.size() - 1;
				json jsonOut{};
				std::cout << limit << std::endl;

				for (int j{}; j <= (limit); j++)
				{
					jsonOut[j] = jsonIn[limit - j];
				};
				return jsonOut;
			};
			if (jsonIn.is_number_float())
			{
				number_call++;
				return jsonIn;
			};
		}
		*/
		/*
		else if (jsonIn.is_string())
		{
			number_call++;
			auto tempString = jsonIn.template get<json::string_t>();
			std::reverse(tempString.begin(), tempString.end());
			/*
			auto limit = jsonIn.size() - 1;
			json jsonOut{};
			for (int j{}; j <= (limit); j++)
				{
					jsonOut[j] = jsonIn[limit - j];
				};
			
			return tempString, number_call;
		}
		*/
		/*
		else if (jsonIn.is_array())
		{
			number_call++;
			//std::cout << limit << std::endl;
			//auto jsonOut = jsonIn.operator[](0);
			//std::cout << (jsonIn.type() == json::value_t::array) << std::endl;
			auto limit = jsonIn.size() - 1;
			json jsonOut{};
			for (int j{}; j <= (limit); j++)
			{
				jsonOut[j] = jsonIn[limit - j];
			};
			return jsonOut, number_call;
		}
		*/
		else
		{

			//number_call++;
			//std::cout << "the type of the value N " << number_call << ": " << jsonIn << " - " << jsonIn.type_name() << std::endl;
			//std::cout << jsonIn.type_name() << std::endl;

			return is_primitive(jsonIn);
		};
	}
	catch (const char* e)
	{
		std::cerr << e;
	};
};