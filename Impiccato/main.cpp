#include "main.h"
using namespace std;

int imp::ha(char h) {
    return (int(h) % letters);
}

void imp::insert(point* &pi, lettera *let){
    if (pi != nullptr) {
        insert(pi->p, let);
    }
    else {
        pi = new point;
        pi->l = let;
        pi->p = nullptr;
    }
}

void imp::indovina(char h)
{
    if (string::npos == provate.find(h)) {
        provate += h;
        provate += ", ";
    }
    int b = ha(h);
    if (hash[b] == nullptr) {
        tentativi--;
    }

    if (tentativi > 0) {
        scopri(hash[b]);
    }
    else {
        s = perso;
    }
}

void imp::printImp()
{
    char soluzioneBrutta[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    string dir = "img/";
    dir += soluzioneBrutta[tentativi];
    dir += ".txt";

    ifstream file(dir);
    string str;
    string file_contents;
    while (getline(file, str))
    {
        file_contents += str;
        file_contents.push_back('\n');
    }
    cout << file_contents;
}

void imp::play()
{
    while (s == inGame) {
        char h;
        cin >> h;
        indovina(h);
        system("cls");
        stampaParola();
    }
    if (s == vinto) {
        cout << "HAI VINTO!!!" << endl;
    }
    else {
        cout << "SEI MORTO" << endl << "La parola era: ";
        for (int i = 0; i < len; i++)
        {
            cout << parola[i].h;
        }
        cout << endl;
    }
}

void imp::reset()
{
    system("cls");
    len = -1;
    tentativi = trys;
    s = inGame;
    provate = "";
    parola = nullptr;
    for (int i = 0; i < letters; i++)
    {
        hash[i] = nullptr;
    }
    loadWord();
}

void imp::loadWord()
{
    string word = "";
    fstream file("Parole.txt");
    srand(time(NULL) * 75 + 13);

    GotoLine(file, (rand() % (maxWord + 1) ) );
    file >> word;
    len = word.size();
    parola = new lettera[len];
    
    //cout << word << endl;
    for (int i = 0; i < len; i++){
        parola[i].h = word[i];
        parola[i].b = false;
        insert(hash[ha(word[i])], &parola[i]);
    }
    indovina(word[0]);
    stampaParola();
}

void imp::scopri(point*& pi)
{
    if (pi != nullptr) {
        pi->l->b = true;
        scopri(pi->p);
    }
}

imp::imp() 
{
    loadWord();
}

void imp::stampaParola()
{
    printImp();
    cout << "Parola: ";
    bool scoperta = true;
    for (size_t i = 0; i < len; i++)
    {
        if (parola[i].b) {
            cout << parola[i].h;
        }
        else {
            cout << "_";
            scoperta = false;
        }
    }
    s = scoperta ? vinto : s;
    cout << endl << "Lettere provate: " << provate << "  Tentativi rimasti: " << tentativi << endl;    
}


