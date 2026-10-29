// строки.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//





#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;


int romanDigit(char c)
{
    switch (c)
    {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    }
    return 0;
}


int romanToInt(string s)
{
    int result = 0;

    for (int i = 0; i < (int)s.length(); i++)
    {
        int current = romanDigit(s[i]);

        if (i + 1 < (int)s.length() &&
            current < romanDigit(s[i + 1]))
        {
            result -= current;
        }
        else
        {
            result += current;
        }
    }

    return result;
}

int main()
{
    string line, word;
    vector<string> roman;
    vector<int> numbers;

    cout << "Enter Roman numbers: ";
    getline(cin, line);

    stringstream ss(line);

    while (ss >> word)
    {
        roman.push_back(word);
        numbers.push_back(romanToInt(word));
    }

    if (numbers.empty())
    {
        cout << "Empty string!" << endl;
        return 0;
    }

    long long sum = 0;
    int minIndex = 0;
    int maxIndex = 0;

    for (int i = 0; i < (int)numbers.size(); i++)
    {
        if (numbers[i] % 2 == 0)
        {
            sum += numbers[i];
        }

        if (numbers[i] < numbers[minIndex])
        {
            minIndex = i;
        }

        if (numbers[i] > numbers[maxIndex])
        {
            maxIndex = i;
        }
    }

  
    string temp = roman[minIndex];
    roman[minIndex] = roman[maxIndex];
    roman[maxIndex] = temp;

    cout << "Sum of even numbers: " << sum << endl;
    cout << "Modified string: ";

    for (int i = 0; i < (int)roman.size(); i++)
    {
        if (i > 0)
            cout << " ";

        cout << roman[i];
    }

    cout << endl;

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
