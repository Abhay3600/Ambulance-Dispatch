#include <iostream>
#include <vector>
#include <limits>

using namespace std;

/*
 Intelligent Ambulance Dispatch System
 ------------------------------------
 - City is represented as a weighted undirected graph
 - Bellman-Ford algorithm computes shortest travel times
 - Greedy approach selects the best ambulance
 - Includes basic error detection
*/

struct Edge
{
    int to;
    int weight;

};

vector<vector<Edge>> graphAdj;

// Bellman-Ford Algorithm (same interface as Dijkstra)
vector<int> dijkstra(int n, int source)
{
    const int INF = numeric_limits<int>::max();
    vector<int> dist(n, INF);

    dist[source] = 0;

    // Relax edges (n - 1) times
    for (int i = 0; i < n - 1; i++)
    {
        for (int u = 0; u < n; u++)
        {
            if (dist[u] == INF)
                continue;

            for (const Edge &edge : graphAdj[u])
            {
                int v = edge.to;
                int w = edge.weight;

                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    // Optional: Negative cycle detection (not printed to keep output same)
    /*
    for (int u = 0; u < n; u++)
    {
        if (dist[u] == INF) continue;
        for (const Edge &edge : graphAdj[u])
        {
            if (dist[edge.to] > dist[u] + edge.weight)
            {
                cout << "Negative weight cycle detected.\n";
            }
        }
    }
    */

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

        vector<int> dist = dijkstra(n, incident);

        int bestAmbulance = -1;
        int minTime = numeric_limits<int>::max();

        // Greedy selection
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
