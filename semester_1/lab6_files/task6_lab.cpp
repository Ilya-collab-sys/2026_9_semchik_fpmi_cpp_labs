// task6_lab.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <algorithm>


std::string getCurrentTimestamp() {
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);

    std::ostringstream oss;
    oss << std::put_time(localTime, "%d.%m.%Y %H:%M:%S");
    return oss.str();
}


void writeLog(std::ofstream& logFile, const std::string& message) {
    if (logFile.is_open()) {
        logFile << getCurrentTimestamp() << " | " << message << std::endl;
    }
}


int romanCharToInt(char c) {
    switch (c) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0;
    }
}


int romanToInt(const std::string& s) {
    int total = 0;
    int n = static_cast<int>(s.length());
    for (int i = 0; i < n; ++i) {
        int current = romanCharToInt(s[i]);
        if (i + 1 < n && current < romanCharToInt(s[i + 1])) {
            total -= current;
        }
        else {
            total += current;
        }
    }
    return total;
}


std::string processLine(const std::string& line, std::ofstream& logFile) {
    if (line.empty()) {
        writeLog(logFile, "line is empty, skipping");
        return "";
    }

   
    writeLog(logFile, "parsing roman numbers from line");
    std::istringstream iss(line);
    std::vector<std::string> romans;
    std::vector<int> values;
    std::string token;

    while (iss >> token) {
        romans.push_back(token);
        values.push_back(romanToInt(token));
    }

    if (romans.empty()) {
        writeLog(logFile, "no roman numbers found");
        return "";
    }

   
    int evenSum = 0;
    size_t minIdx = 0;
    size_t maxIdx = 0;

    for (size_t i = 0; i < values.size(); ++i) {
        if (values[i] % 2 == 0) {
            evenSum += values[i];
        }
        if (values[i] < values[minIdx]) {
            minIdx = i;
        }
        if (values[i] > values[maxIdx]) {
            maxIdx = i;
        }
    }

    writeLog(logFile, "even numbers sum: " + std::to_string(evenSum));
    writeLog(logFile, "min value: " + romans[minIdx] + " (" + std::to_string(values[minIdx]) + "), max value: " + romans[maxIdx] + " (" + std::to_string(values[maxIdx]) + ")");

  
    std::swap(romans[minIdx], romans[maxIdx]);

   
    std::string swappedLine;
    for (size_t i = 0; i < romans.size(); ++i) {
        if (i > 0) swappedLine += " ";
        swappedLine += romans[i];
    }

    writeLog(logFile, "swapped line: \"" + swappedLine + "\"");

  
    return "Sum of even: " + std::to_string(evenSum) + " | Modified line: " + swappedLine;
}

int main() {
    std::ofstream logFile("log.txt");
    if (!logFile.is_open()) {
        std::cerr << "Critical error: cannot open log.txt" << std::endl;
        return 1;
    }

    writeLog(logFile, "opening file \"input.txt\"");
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        writeLog(logFile, "error: cannot open file \"input.txt\"");
        writeLog(logFile, "program has ended with code 1");
        return 1;
    }
    writeLog(logFile, "file \"input.txt\" has been opened successfully");

    writeLog(logFile, "opening file \"output.txt\"");
    std::ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        writeLog(logFile, "error: cannot open file \"output.txt\"");
        inputFile.close();
        writeLog(logFile, "program has ended with code 1");
        return 1;
    }
    writeLog(logFile, "file \"output.txt\" has been opened successfully");

    writeLog(logFile, "reading lines from \"input.txt\"");
    std::string line;

    while (std::getline(inputFile, line)) {
        writeLog(logFile, "got line: \"" + line + "\"");

        std::string processedResult = processLine(line, logFile);

        writeLog(logFile, "writing result to \"output.txt\"");
        outputFile << processedResult << std::endl;
    }

    inputFile.close();
    outputFile.close();

    writeLog(logFile, "program has ended with code 0");
    logFile.close();

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
