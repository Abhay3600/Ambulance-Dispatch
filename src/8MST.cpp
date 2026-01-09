#include <iostream>
#include <vector>
#include <limits>

using namespace std;

/*
 Intelligent Ambulance Dispatch System
 ------------------------------------
 - Prim’s algorithm builds Minimum Spanning Tree
 - DFS computes distances in MST
 - NOTE: MST paths are not guaranteed shortest paths
*/

struct Edge
{
    int to;
    int weight;
};

vector<vector<Edge>> graphAdj;
vector<vector<Edge>> mstAdj;

// DFS on MST to compute distances
void dfsMST(int u, int parent, vector<int> &dist)
{
    for (const Edge &edge : mstAdj[u])
    {
        int v = edge.to;
        int w = edge.weight;

        if (v == parent) continue;

        dist[v] = dist[u] + w;
        dfsMST(v, u, dist);
    }
}

// Prim’s Algorithm + DFS (same interface)
vector<int> primMSTDistances(int n, int source)
{
    const int INF = numeric_limits<int>::max();

    vector<int> key(n, INF);
    vector<bool> inMST(n, false);
    vector<int> parent(n, -1);

    key[0] = 0;

    // Prim’s Algorithm
    for (int count = 0; count < n - 1; count++)
    {
        int u = -1;
        for (int i = 0; i < n; i++)
        {
            if (!inMST[i] && (u == -1 || key[i] < key[u]))
                u = i;
        }

        inMST[u] = true;

        for (const Edge &edge : graphAdj[u])
        {
            int v = edge.to;
            int w = edge.weight;

            if (!inMST[v] && w < key[v])
            {
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    // Build MST adjacency list
    mstAdj.assign(n, {});
    for (int v = 1; v < n; v++)
    {
        int u = parent[v];
        if (u != -1)
        {
            mstAdj[u].push_back({v, key[v]});
            mstAdj[v].push_back({u, key[v]});
        }
    }

    // Compute distances from source using DFS on MST
    vector<int> dist(n, INF);
    dist[source] = 0;
    dfsMST(source, -1, dist);

    return dist;
}

int main()
{
    int n, m;
    cout << "Enter number of junctions and roads:\n";
    cin >> n >> m;

    if (n <= 0 || m < 0)
    {
        cout << "Error: Invalid graph size.\n";
        return 0;
    }

    graphAdj.resize(n);

    cout << "Enter roads (u v travel_time):\n";
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        if (u < 0 || u >= n || v < 0 || v >= n || w <= 0)
        {
            cout << "Error: Invalid road input.\n";
            return 0;
        }

        graphAdj[u].push_back({v, w});
        graphAdj[v].push_back({u, w});
    }

    int A;
    cout << "Enter number of ambulances:\n";
    cin >> A;

    if (A <= 0)
    {
        cout << "Error: No ambulances available.\n";
        return 0;
    }

    vector<int> ambulanceNodes(A);
    cout << "Enter ambulance locations:\n";
    for (int i = 0; i < A; i++)
    {
        cin >> ambulanceNodes[i];
        if (ambulanceNodes[i] < 0 || ambulanceNodes[i] >= n)
        {
            cout << "Error: Invalid ambulance location.\n";
            return 0;
        }
    }

    int Q;
    cout << "Enter number of emergency calls:\n";
    cin >> Q;

    while (Q--)
    {
        int incident;
        cout << "\nEnter incident location:\n";
        cin >> incident;

        if (incident < 0 || incident >= n)
        {
            cout << "Error: Invalid incident location.\n";
            continue;
        }

        vector<int> dist = primMSTDistances(n, incident);

        int bestAmbulance = -1;
        int minTime = numeric_limits<int>::max();

        for (int i = 0; i < A; i++)
        {
            if (dist[ambulanceNodes[i]] < minTime)
            {
                minTime = dist[ambulanceNodes[i]];
                bestAmbulance = i;
            }
        }

        cout << "----------------------------------\n";
        if (bestAmbulance == -1 || minTime == numeric_limits<int>::max())
        {
            cout << "No ambulance can reach the incident.\n";
        }
        else
        {
            cout << "Selected Ambulance ID: " << bestAmbulance << "\n";
            cout << "Ambulance Location Node: "
                 << ambulanceNodes[bestAmbulance] << "\n";
            cout << "Estimated Minimum Travel Time: "
                 << minTime << "\n";
        }
        cout << "----------------------------------\n";
    }

    return 0;
}
