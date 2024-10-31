#include "functions.hpp"

using namespace std;

int main()
{
    string fileName = "matrix1.txt";
    vector<vector<int>> matrix = loadMatrix(fileName);

    string fileNamePackages = "packages1.csv";
    vector<Package> packages = loadPackages(fileNamePackages);

    sort(packages.begin(), packages.end(), [](const Package &a, const Package &b)
    {
        if(a.priority != b.priority)
            return a.priority > b.priority;
        else
            return a.mass > b.mass;
    });

    Vehicle deliveryVehicle(0, 100);
    ofstream outputFile("excessPackages.txt");

    cout << "---------------------------------------" << endl;
    
    deliveryVehicle.addPackages(packages, outputFile);

    cout << "Dostavno vozilo je napunjeno sa " << deliveryVehicle.getPackagesMass() << " kg paketa." << endl << endl;

    int matrixSize = matrix.size(); // Broj čvorova u grafu
    int totalPackages = packages.size();
    int deliveredPackages = 0;

    int niz[matrix.size()] = {};

    while (!deliveryVehicle.getPackages().empty())
    {
        auto &currentPackages = deliveryVehicle.getPackages();
        int currentAddress = deliveryVehicle.getCurrentAddress();

        Package nextPackage = currentPackages.front();

        // Provjeri da li adresa paketa postoji u gradu
        if (nextPackage.address < 0 || nextPackage.address >= matrixSize)
        {
            cout << "*Adresa " << nextPackage.address << " ne postoji u gradu. Paket " << nextPackage.name << " se preskace." << endl;
            deliveryVehicle.removePackage(nextPackage);
            continue;
        }

        vector<int> distances = findShortestPaths(matrix, currentAddress);

        // Dostavi paket i ažuriraj pređeni put
        cout << "Dostavljanje paketa: " << nextPackage.name << " na adresu " << nextPackage.address << " s prioritetom: " << nextPackage.priority << endl;
        niz[currentAddress]++;

        deliveryVehicle.setCurrentAddress(nextPackage.address);
        deliveryVehicle.removePackage(nextPackage);

        // Ako postoji put do adrese, dodaj pređeni put i povećaj broj isporučenih paketa
        if (distances[nextPackage.address] != numeric_limits<int>::max())
        {
            deliveryVehicle.addTraveledWay(distances[nextPackage.address]);
            deliveredPackages++;
        }
        else
            cout << "**Nema puta do adrese " << nextPackage.address << endl;

        // Ispis trenutno pređenog puta
        cout << "Trenutno predjeni put: " << deliveryVehicle.getTraveledWay() << " km." << endl;
    }

    cout << endl << "Ukupno predjeni put: " << deliveryVehicle.getTraveledWay() << " km." << endl << endl;
    
    double deliveryPercentage = 100.00 * deliveredPackages / totalPackages;
    cout << "Procenat isporucenih paketa: " << deliveryPercentage << "%" << endl;

    for (int i = 0; i < matrix.size(); i++)
        cout << "*************Na adresu: " << i << " je isporuceno " << niz[i] << " paketa." << endl;

    cout << "---------------------------------------" << endl;

    return 0;
}