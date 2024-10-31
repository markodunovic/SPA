#include "functions.hpp"

using namespace std;

vector<vector<int>> loadMatrix(const string &fileName)
{
    ifstream txtFile(fileName);
    vector<vector<int>> matrix;
    int n;
    if (txtFile)
    {
        txtFile >> n;
        matrix.resize(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                txtFile >> matrix[i][j];
        txtFile.close();
    }
    return matrix;
}

vector<Package> loadPackages(const string &fileName)
{
    vector<Package> packages;
    ifstream file(fileName);

    if (!file.is_open())
    {
        cout << "Greska prilikom otvaranja fajla: " << fileName << endl;
        return packages;
    }

    string line;
    getline(file, line);

    while (getline(file, line))
    {
        istringstream iss(line);
        string token;

        Package package;

        getline(iss, token, ',');
        package.name = token;

        getline(iss, token, ',');
        package.description = token;

        getline(iss, token, ',');
        package.address = stoi(token);

        getline(iss, token, ',');
        package.mass = stoi(token);

        getline(iss, token, ',');
        package.priority = stoi(token);

        packages.push_back(package);
    }

    file.close();
    return packages;
}

vector<int> findShortestPaths(const vector<vector<int>>& matrix, int start)
{
    int n = matrix.size();
    vector<int> dist(n, numeric_limits<int>::max());
    vector<bool> visited(n, false);
    dist[start] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        int u = -1;

        for (int i = 0; i < n; i++)
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;

        visited[u] = true;

        for (int v = 0; v < n; v++)
            if (!visited[v] && matrix[u][v] && dist[u] + matrix[u][v] < dist[v])
                dist[v] = dist[u] + matrix[u][v];
    }

    return dist;
}