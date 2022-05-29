#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include <vector>

using namespace std;

int level;
string input;
vector<string> base;
void fill_base();

void get_level() {
    system("cls");
    cout << "Текущий уровень: " << level + 1 << endl;
};

void rem_forb_chars(string& k) {
    k.erase(remove(k.begin(), k.end(), ' '), k.end());
    k.erase(remove(k.begin(), k.end(), ','), k.end());
    k.erase(remove(k.begin(), k.end(), '.'), k.end());
    k.erase(remove(k.begin(), k.end(), ':'), k.end());
    k.erase(remove(k.begin(), k.end(), '?'), k.end());
};

void pause() {
    cout << endl << "Нажмите любую клавишу...";
    cin.get();
};

int main()
{
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
    setlocale(LC_ALL, "Russian");

    fill_base();

    size_t last = 0;
    level = 0;

    cout << "Введите номер начального предложения: ";
    cin >> level;
    level --;
    cin.get();
    
    while (level < base.size()) {
    
    get_level();
    string temp = base[level];
    if (last == 0) cout << "Текст: " << base[level] << endl;

    last = temp.find(' ', last + 1);

    if (last < temp.length()) {
        temp.erase(last);
        string temp2 = temp;
        do {
            cout << temp2;
            pause();

            get_level();
            input = "";
            getline(cin, input);
            
            rem_forb_chars(input);
            rem_forb_chars(temp);

            
        } while (_stricmp(input.c_str(), temp.c_str()) != NULL);
    }
    else {
        cout << "Отлично!";
        ++level;
        last = 0;    
        pause();
    }
    } 

    if (base.size() == 0) cout << "Нет исходных данных ("; else cout << "Текст выучен! Можете отдохнуть :)";
    pause();
    return 0;
}

void fill_base() {
    ifstream file("data.txt");
    int i = 0;
    string str;
    if (file.is_open()) {
        while (!file.eof())
        {

            getline(file, str);
            str.append(" ");
            base.push_back(str);
            i++;
        }
    }
    
};
