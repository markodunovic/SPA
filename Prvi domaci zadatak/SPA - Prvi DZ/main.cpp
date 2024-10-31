#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "SLL.hpp"
#include "DLL.hpp"
#include "PriorityQueue.hpp"
#include "Queue.hpp"
#include "auxiliaryFunctions.hpp"
#include "converterToPrefix.hpp"
#include "converterToJSON.hpp"

using namespace std;

int main()
{
    // 1. KORAK
    SLL lista;
    ifstream newfile("ulaz2.txt");
    if(newfile.is_open())
    {
        string temp;
        while(getline(newfile, temp))
            lista.append(temp);
    }
    newfile.close();

    // 2. KORAK
    PriorityQueue prQueue;
    Queue usualQueue;

    lista.addToQueues(prQueue, usualQueue);

    // 3. i 4. KORAK
    prQueue.infixToPrefix();

    DLL dlista;

    // -----Pocetak mjerenja-----
    auto start = chrono::high_resolution_clock::now();

    prQueue.convertToJSON(dlista);

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "Vrijeme trajanja konverzije: " << duration.count() << " ms" << endl;
    // -----Kraj mjerenja-----

    dlista.showFileNames();
    cout << endl;

    // 5., 6. i 7. KORAK
    string endProgram = "POCETAK";
    while(endProgram != "KRAJ")
    {
        cout << "Da li zelite prikaz sadrzaja nekog od fajlova?\n(1) Da\n(2) Ne\n**Napomena: Opciju birate unosenjem cifre 1 ili 2." << endl;
        int option1;
        cin >> option1;
        if (option1 == 1)
        {
            cout << "Unesite naziv fajla: ";
            string fileName;
            cin >> fileName;
            dlista.printFileExpression(fileName);
        }

        cout << endl;
        cout << "Da li zelite unijeti svoj aritmeticki izraz koji ce biti konvertovan u JSON fajl i izracunat?\n(1) Da\n(2) Ne\n**Napomena: Opciju birate unosenjem cifre 1 ili 2." << endl;
        int option2;
        cin >> option2;
        if(option2 == 1)
        {
            cout << "**Napomena: Aritmeticki izraz se unosi bez razmaka i dozvoljeno je unosenje samo cjelobrojnih jednocifrenih brojeva, kao i operacija '+', '-', '*' i '/'." << endl;
            cout << "Unesite aritmeticki izraz: ";
            string userExp;
            cin >> userExp;
            if(isValid(userExp))
            {
                userExp = convertToPrefix(userExp);
                string copyUserExp = userExp;

                int result = calculatePrefixExpression(copyUserExp);
                cout << "Rezultat aritmetickog izraza je: " << result << endl;

                int index = 0;
                Tree *root = formExpression(userExp, index);
                string userJson = toJSON(root);
                cout << "JSON format vaseg aritmetickog izraza je:" << endl;
                cout << userJson << endl;
            }
            else
                cout << "Neispravan format unesenog aritmetickog izraza!" << endl;
        }
        cout << endl;
        cout << "Za izlazak iz programa unesite rijec \"KRAJ\", za nastavak bilo koju drugu rijec: ";
        cin >> endProgram;
        cout << endl;
    }
    return 0;
}