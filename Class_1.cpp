#include <nlohmann/json.hpp>
#include <iostream>

using json = nlohmann::json;

class Class_1
{
	public:
		json is_primitive(json& jsonIn)
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
					for (auto& x : jsonIn.items())
					{
						//std::cout << x.key() << " - " << jsonIn[x.key()] << " - 1st out message - " << *jsonIn[x.key()].type_name() << std::endl;
						jsonIn[x.key()] = converterFunc(x.value());
						//std::cout << " - " << jsonIn << " - 2nd out message - " << std::endl;
						////std::cout << std::boolalpha << jsonIn.contains(x.key()) << std::endl;
						//std::cout << x.key() << std::endl;	
					};
					//std::cout << jsonIn << " -  - " << *jsonIn.type_name() << std::endl;
					return jsonIn;
					//return converterFunc(jsonTemp);
				}
				else if (jsonIn.is_array())
				{
					int maxIndex = (jsonIn.size() == 0) ? 0 : (jsonIn.size() - 1);
					//std::cout << " - array size - " << maxIndex << std::endl;
					json tempArray{};
					for (int j{}; j <= (maxIndex); j++)
					{
						tempArray[j] = converterFunc(jsonIn[maxIndex - j]);
						//std::cout << " - array value - " << tempArray[j] << " - type - " << *tempArray[j].type_name() << std::endl;
					};
					jsonIn = tempArray;
					return jsonIn;
				}
				else
				{
					//number_call++;
					//std::cout << "the type of the value N " << number_call << ": " << jsonIn << " - " << jsonIn.type_name() << std::endl;
					return is_primitive(jsonIn);
				};
			}
			catch (const char* e)
			{
				std::cerr << e;
			};
		};
};