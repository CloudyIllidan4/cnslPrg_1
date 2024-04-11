#include "Class_1.h"

using json = nlohmann::json;

json Class_1::is_primitive(json& jsonIn)
{
	try
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
			jsonIn = tempStr; // ?не понятно как сделать через ссылку (выводит ошибку)?
			//std::cout << " - in primitive - " << jsonIn << " - type - " << jsonIn.type_name() << std::endl;
			return jsonIn; // в JSON записывает ключи в алфавитном порядке
		}
		else if (jsonIn.is_number_integer())
		{
			//jsonIn =+ 1; // ?записывает вместо текущих значений 1?
			jsonIn = jsonIn + 1;
			//std::cout << " - if int - " << jsonIn << " - type - " << *jsonIn.type_name() << std::endl;
			return jsonIn;
		}
		else if (jsonIn.is_number_float())
		{
			jsonIn = jsonIn + 1.1000f;
			//std::cout << " - if flt - " << jsonIn << " - type - " << *jsonIn.type_name() << std::endl;
			return jsonIn; // не всегда корректно высчитывает значения (в дробной части)
		}
		else if (jsonIn.is_null())
		{
			return jsonIn;
		}
		/*
		else if (jsonIn.is_discarded())
		{
			jsonIn += null;
			return jsonIn;
		}
		*/
		else
		{
			//throw json::exception();
			//myExceptionClass exceptionInstance_1{};
			throw exceptionTypeFunc(jsonIn);
			//return jsonIn;
		};
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Exception for " << jsonIn << "value: " << ex.what() << std::endl;
		//jsonIn.back() = json::binary({1,2,3});
		return jsonIn;
	};
};

json Class_1::converterFunc(json & jsonIn)
{
			//try
		//	{
				//int n{ number_call }; // счетчик примитивов
				/*
				if () // ?был сделан последний вызов из стека?
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
					json::size_type maxIndex = (jsonIn.size() == 0) ? 0 : (jsonIn.size() - 1);
					//std::cout << " - array size - " << maxIndex << std::endl;
					json tempArray{};
					for (json::size_type j{}; j <= (maxIndex); j++)
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
				/*
			}
			catch (const json::exception& ex)
			{
				std::cerr << "Exception ID: " << ex.id << ", Error: " << ex.what() << std::endl;
				return jsonIn;
			};
			*/
};

std::exception Class_1::exceptionTypeFunc(json& jsonIn)
{
	//json::type_error myTypeException;
	//char exceptionMessage = "the transmitted value type is not supported";
	std::string exceptionMessage{ "the transmitted value type" };
	//exceptionMessage += ("the transmitted value type ");
	//, std::to_string(jsonIn.type()) + "for this Id is not supported");
	char* buffer{};
	sprintf(buffer, "%s%d", exceptionMessage.c_str(), jsonIn.type());
	//std:: result(buffer);
	int exceptionId = jsonIn.size();
	std::exception myException{ buffer, exceptionId };
	return myException;
};

Class_1::Class_1()
{
	Class_1 classObject{};
};
