// project 6.33.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <conio.h>
#include <Windows.h>

using namespace std;

int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
        fstream file;
        file.open("D:\\TXT.txt", ios_base::in | ios_base::out);
        file.seekp(0);
        vector<string>  line;

        while (!file.eof()) 
        {
            char buf[1024];
            file.getline(buf, sizeof(buf), '\n');
            line.push_back(buf);
        }
        file.close();
        file.clear();

        // подсчитываем максимальные строки
        int _max = 0;
        for (int i = 0; i < line.size(); i++) {
            if (line[i].length() > _max)
                _max = line[i].length();
        }
        for (vector<string>::iterator p = line.begin(); p != line.end(); *p++) 
        {
            if ((*p).length() == _max)
                cout << (*p).c_str() << endl;
        }


        for (int k = 0; k < line.size(); k++)
            reverse(line[k].begin(), line[k].end());


        // сохраним в файл реверсированные строки
        file.open("D:\\TXT.txt", ios_base::out);
        file.seekg(0);
        for (int v = 0; v < line.size(); v++) 
        {
            file.write(line[v].c_str(), line[v].length());
            file.put('\n');
        }
        file.flush();
        file.close();

        cin.get();
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
