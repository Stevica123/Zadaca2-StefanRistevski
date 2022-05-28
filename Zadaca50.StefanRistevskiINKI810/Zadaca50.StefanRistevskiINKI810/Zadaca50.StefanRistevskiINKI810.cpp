
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

// Koristenje na funkcija za naogjanje najgolema cifra od broj na indeks
int najgolemaCifra(int indeks) {
    int arr[3];
    int najgolem = 0;

    arr[0] = indeks / 100;
    arr[1] = indeks % 100; arr[1] = arr[1] / 10;
    arr[2] = indeks % 10;

    for (unsigned int i = 0; i < 4; i++) {
        if (arr[i] > najgolem) najgolem = arr[i];
    }

    return najgolem;
}


int main()
{
    int indeks, broj;
    const string sodrzina = "INKI810Stefan Imagine Dragons First things first I'm say all the words inside my head";
    vector<int> encrypted;
    string imeNaDatoteka;
    ofstream datoteka;

    cout << "Vasiot indeks e: INKI";
    cin >> indeks;
    imeNaDatoteka = "INKI" + to_string(indeks) + ".Proekt3.txt";
    broj = najgolemaCifra(indeks);

    // Ispolnuvanje na vektorot so ascii kod pomesten za "broj" mesta od originalniot string "sodrzina"

    for (unsigned int i = 0; i < sodrzina.size(); i++) {
        encrypted.push_back((int)sodrzina.at(i) + broj);
    }

    // Sortiranje na vektorot po golemina od najmal do najgolem broj

    sort(encrypted.begin(), encrypted.end());

    // Pecatenje na vektorot

    for (unsigned int i = 0; i < encrypted.size(); i++) {
        cout << encrypted[i] << " ";
    }


    // Otvaranje na datoteka
    datoteka.open(string(imeNaDatoteka).c_str());

    // Pisuvanje na datotekata
    for (unsigned int i = 0; i < encrypted.size(); i++) {
        datoteka << encrypted[i] << " ";
        // Dodavanje prazni linii za da ne bide celata sodrzina vo eden red
        if (i % 15 == 0 && i != 0) {
            datoteka << endl;
        }
    }

    // Zatvaranje na datotekata
    datoteka.close();

    return 0;
}