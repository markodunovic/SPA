#pragma once
#include <string>
#include <vector>

typedef struct Package
{
    std::string name;
    std::string description;
    int address;
    int mass;
    int priority;
} Package;

class Vehicle
{
private:
    int currentAddress;
    int traveledWay;
    const int maxMass;
    int packagesMass;
    std::vector<Package> packages;
public:
    Vehicle(const int &postAddress, int maxMass) : currentAddress(postAddress), traveledWay(0), maxMass(maxMass), packagesMass(0) {}
    int getCurrentAddress() const
    {
        return this->currentAddress;
    }
    int getTraveledWay() const
    {
        return this->traveledWay;
    }
    const int getMaxMass() const
    {
        return this->maxMass;
    }
    int getPackagesMass() const
    {
        return this->packagesMass;
    }
    const std::vector<Package> &getPackages() const
    {
        return this->packages;
    }
    void setCurrentAddress(int address)
    {
        this->currentAddress = address;
    }
    void addPackage(const Package &other)
    {
        this->packages.push_back(other);
        this->packagesMass += other.mass;
    }
    void addPackages(const std::vector<Package> &packages, std::ofstream &outputFile)
    {
        for (const auto &package : packages)
        {   
            if(this->getMaxMass() - this->getPackagesMass() >= package.mass)
            {
                this->addPackage(package);
                std::cout << "Paket " << package.name << " dodat u dostavno vozilo." << std::endl;
            }
            else
            {
                std::cout << "Paket " << package.name << " ne moze stati u vozilo i dodat je u tekstualni fajl." << std::endl;
                outputFile << "Paket: " << package.name << " Opis: " << package.description << " Adresa: " << package.address << " Masa: " << package.mass << " Prioritet: " << package.priority << std::endl;
            }
        }
        outputFile.close();
        std::cout << std::endl;
    }
    void removePackage(const Package& package)
    {
        auto it = find_if(packages.begin(), packages.end(), [&package](const Package& p)
        {
            return p.name == package.name && p.address == package.address;
        });
        if (it != packages.end())
        {
            packagesMass -= it->mass;
            packages.erase(it);
        }
    }
    void addTraveledWay(int way)
    {
        traveledWay += way;
    }
};