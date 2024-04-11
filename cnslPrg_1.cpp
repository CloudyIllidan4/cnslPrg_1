// cnslPrg_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include "Class_1.h"

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
    Class_1 *MainClass = new Class_1();
    json dataOut = MainClass.converterFunc(dataIn); // применяем нашу рекурсивную функцию конвертации
    //std::cout << dataOut << std::endl;

    // Запись в новый JSON
    std::string pathOutExample = "./OutJSON/ClientConfig_.json";
    std::fstream flOut{};
    flOut.open(pathOutExample, std::ios::out);
    flOut << dataOut;
    flOut.close();

    return 0xFF; // Флаг успешного выполнения
};
