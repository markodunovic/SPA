#include "AVLTree.hpp"

using namespace std;

void bubbleSortGrowing(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void insertionSortDecreasing(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(int array[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (array[j] > array[j + 1])
                swap(array[j], array[j + 1]);
}

int main()
{
    cout << "-----------------------------" << endl;
    // Ispis sadržaja prije sortiranja
    ifstream readFile("text2.txt");
    cout << "Sadrzaj tekstualnog fajla prije sortiranja: " << endl;
    string currentWord;
    while (readFile >> currentWord)
        cout << currentWord << " ";
    cout << endl;
    readFile.close();


    ifstream inFile("text2.txt");
    ofstream outFile("duplikati2.txt");
    set<string> words;
    string word;
    AVLTree tree;

    // Čitanje svake riječi iz tekstualnog fajla i umetanje u stablo, ili smještanje u duplikati.txt
    while (inFile >> word)
    {
        if (!words.insert(word).second)
            outFile << word << endl;
        else
            tree.insert(word);
    }
    inFile.close();
    outFile.close();

    // Ispis stabla nakon sortiranja, preklopljen operator << za AVLTree
    cout << "Rezultat sortiranja rijeci (iz tekstualnog fajla) po abecedi primjenom AVL stabla je:" << endl;
    cout << tree << endl;

    // Ispis dužina riječi
    cout << "Duzina rijeci: ";
    vector<int> wordLengths = tree.wordLengths();
    for (int length : wordLengths)
        cout << length << " ";
    cout << endl;

    // Bubble sort u rastućem redoslijedu
    bubbleSortGrowing(wordLengths);
    cout << "Bubble Sort (Growing): ";
    for (int length : wordLengths)
        cout << length << " ";
    cout << endl;

    // Insertion sort u opadajućem redoslijedu
    insertionSortDecreasing(wordLengths);
    cout << "Insertion Sort (Decreasing): ";
    for (int length : wordLengths)
        cout << length << " ";
    cout << endl;

    // Brojanje različitih duplikata
    ifstream outputFile("duplikati2.txt");
    string current;
    int count = 0;
    while (outputFile >> current)
        count++;
    cout << "Broj duplikata je: " << count << endl;

    cout << "-----------------------------" << endl;

    int niz[5] = {5, 1, 4, 2, 8};

    // sort niz using bubble sort algorithm
    bubbleSort(niz, 5);
    // print niz in sortedarray.txt file
    ofstream sortedFile("sortedarray.txt");
    for (int i = 0; i < 5; i++)
        sortedFile << niz[i] << " ";
    sortedFile.close();

    return 0;
}
