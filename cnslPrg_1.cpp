// cnslPrg_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include "cnslPrg_1.h"

using json = nlohmann::json;

int main()
{
    // Чтение JSON файла
    //setlocale(LC_ALL, "ru"); // установка локализации для вывода на русском
    //std::string pathInExample = "./InputJSON/exampleJSON.json"; // путь к JSON-файлу с примером N1
    //std::string pathInExample = "./InputJSON/ClientConfig.json"; // путь к JSON-файлу с примером N2
    std::string pathInExample = "./InputJSON/simpleJSON.json"; // путь к JSON-файлу с примером N3
    std::fstream flIn;
    flIn.open(pathInExample);
    json dataIn = json::parse(flIn);
    //std::cout << data << std::endl;
    flIn.close();

    // Преобразование содержимого
    
    //size_t i{ dataIn.size() };

    json dataOut = converterFunc(dataIn); // применяем нашу рекурсивную функцию конвертации
    
    //std::cout << dataOut << std::endl;
    
    /*
    //std::cout << dataIn.is_object() << std::endl;
    //json::const_reverse_iterator iter1{ dataIn.crbegin() };
    json::const_iterator iter2{ dataIn.begin() };
    //std::cout << *iter1 << std::endl;
    for (auto x{ iter2 }; x != dataIn.end(); x++)
        //json::value_t::object;

        //for (iter1; iter1 != iter2; iter1++)
    {
        /*
        std::cout << x.key() << '\n'
                << x.value() << std::endl;
                
        json valueJSON = x.value();
        //json::array_t tempBuff{};
        json::string_t stringValue{};
        //auto valSize{ valueJSON.size() }; // указывает на количество значений, а не на число символов в них
        //std::cout << std::boolalpha;
        //std::cout << valueJSON.is_number_integer() << std::endl;
        //std::is_same< valueJSON, json::number_float_t>::value;
        
        if (valueJSON.is_number_integer()) // если тип значения JSON такой, то меняем значение вот так ->
        //if (typeid valueJSON === json:object_t) 
        {
            valueJSON.operator=(333);
            //std::cout << valueJSON << std::endl;
        };
        if (valueJSON.is_number_float())
        {
            //std::cout << valueJSON << std::endl;
        };
        if (valueJSON.is_string())
        {

            std::string tempString{ valueJSON };
            

            for (auto k{0}; k <= tempString.size(); k++)
            {
                //stringValue.operator[]() = tempString[k];
                //tempValue[k].operator=(valueJSON.at(k));                       
            };
            std::cout << stringValue << std::endl;
            /*
            for (auto k{ 0 }; k <= valSize; k++)
            {
                valueJSON[k].operator=(tempValue[valSize - k]);
            };
            
            //std::cout << valueJSON << std::endl;
        };
        if (valueJSON.is_array())
        {
            /*
            json::array_t tempBuffer{};
            auto arrSize{ valueJSON.size() };
            for (auto k{ 0 }; k <= arrSize; k++)
            {
                tempBuffer[arrSize - k] = valueJSON[k];
            }
            std::cout << tempBuffer << arrSize << std::endl;
            
        };
        dataOut[x.key()].operator=(stringValue);
        //dataOut.update(x);
        //dataOut[x.key()] = x.value();
        
        //dataOut[i - 1][i] = x.value();
        
    };
    */

    // Запись в новый JSON
    std::string pathOutExample = "./OutJSON/ClientConfig_.json";
    std::fstream flOut{};
    flOut.open(pathOutExample, std::ios::out);
    flOut << dataOut;
    flOut.close();

    return 0xFF; // Флаг успешного выполнения
};
