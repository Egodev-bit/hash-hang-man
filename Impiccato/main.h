#pragma once

#include<string>
#include<iostream>
#include <fstream>
#include <limits>
#include <random>

#define maxWord 1124
#define letters 26
#define trys 8;

using namespace std;

class imp
{
    enum stato{vinto, perso, inGame};

    struct lettera {
        char h;
        bool b;
    };

    struct point {
        lettera* l;
        point* p;
    };

    lettera* parola = nullptr;
    point *hash[letters];

    int len = -1;
    int tentativi = trys;
    stato s = inGame;
    string provate = "";

    fstream& GotoLine(std::fstream& file, int num) {
        file.seekg(std::ios::beg);
        for (int i = 0; i < num - 1; ++i) {
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        return file;
    }

    void insert(point* &pi, lettera *let);

    void loadWord();

    int ha(char h);

    void scopri(point * &pi);

    void stampaParola();

    void indovina(char h);

    void printImp();

public:

    imp();

    void play();

    void reset();

};

