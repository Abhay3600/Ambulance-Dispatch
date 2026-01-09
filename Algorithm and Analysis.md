# Analysis of Algorithms

The following algorithms were studied and analyzed for solving the **Intelligent Ambulance Dispatch and Route Optimization** problem. Each algorithm was evaluated based on its suitability for shortest path computation, efficiency, scalability, and real-time applicability.

---

## 1. Dijkstra’s Algorithm

Dijkstra’s algorithm was analyzed because it is one of the most widely used algorithms for finding the shortest path in a weighted graph with non-negative edge weights. In the ambulance dispatch problem, the road network is represented as a graph where nodes denote junctions and edges represent roads with positive travel times.  

Dijkstra’s algorithm efficiently computes the minimum travel time from a source node (emergency location) to all other nodes. This makes it highly suitable for estimating ambulance response times. Its guaranteed optimality and good performance make it ideal for real-time emergency applications.

**Analysis**
- **Time Complexity:** O((V + E) log V)  
- **Space Complexity:** O(V + E)

---

## 2. Bellman–Ford Algorithm

The Bellman–Ford algorithm was studied because it supports graphs with negative edge weights and can detect negative cycles. Although this makes it more flexible than Dijkstra’s algorithm, it is not suitable for the ambulance dispatch system since travel times on roads cannot be negative.  

Additionally, the algorithm has a much higher time complexity, which makes it inefficient for large city road networks and unsuitable for real-time emergency response.

**Analysis**
- **Time Complexity:** O(V × E)  
- **Space Complexity:** O(V)

---

## 3. Breadth First Search (BFS)

Breadth First Search was analyzed as it can find shortest paths in unweighted graphs. However, real-world road networks are weighted, as different roads have different travel times and distances.  

Since BFS does not support weighted edges, it cannot accurately compute the shortest travel-time routes required for ambulance routing.

**Analysis**
- **Time Complexity:** O(V + E)  
- **Space Complexity:** O(V)

---

## 4. Depth First Search (DFS)

Depth First Search was considered as a basic graph traversal technique. While DFS is useful for exploring connectivity within a graph, it does not guarantee the shortest path between two nodes.  

Because ambulance routing requires the minimum travel time between locations, DFS does not satisfy the problem requirements and was therefore not considered further.

**Analysis**
- **Time Complexity:** O(V + E)  
- **Space Complexity:** O(V)

---

## 5. Floyd–Warshall Algorithm

The Floyd–Warshall algorithm computes shortest paths between all pairs of vertices in a graph. While this provides complete distance information, it involves unnecessary computation for the ambulance dispatch problem, which only requires shortest paths from a specific source.  

Its very high time complexity makes it impractical for large graphs and unsuitable for real-time emergency systems.

**Analysis**
- **Time Complexity:** O(V³)  
- **Space Complexity:** O(V²)

---

## 6. Greedy Selection Algorithm

A greedy selection algorithm was analyzed for selecting the best ambulance among multiple available ambulances. Once the shortest travel time for each ambulance is known, choosing the ambulance with the minimum response time is a greedy decision.  

This locally optimal choice also results in a globally optimal solution, making greedy selection efficient and well-suited for ambulance dispatch decisions.

**Analysis**
- **Time Complexity:** O(A × (V + E) log V)  
- **Space Complexity:** O(V)

---

## 7. Dynamic Programming

Dynamic programming techniques were studied because they are effective for problems with overlapping subproblems and optimal substructure. However, shortest path problems on large and dynamic road networks are better handled by specialized graph algorithms.  

Dynamic programming does not provide any performance benefit for real-time route computation and was therefore found unsuitable for this application.

**Analysis**
- **Time Complexity:** O(V × E)  
- **Space Complexity:** O(V²)

---

## 8. Minimum Spanning Tree Algorithms (Prim’s and Kruskal’s)

Minimum spanning tree algorithms were analyzed because they minimize the total cost required to connect all nodes in a graph. However, these algorithms do not guarantee the shortest path between a specific source and destination.  

Since ambulance dispatch requires finding the shortest route from an ambulance to an emergency location, MST algorithms were not appropriate.

**Analysis**
- **Time Complexity:** O(E log V)  
- **Space Complexity:** O(V + E)

---

## 9. Brute Force Approach

The brute force approach was analyzed as a baseline method in which all possible paths are explored to determine the shortest one. While this approach guarantees correctness, its exponential time complexity makes it infeasible even for moderately sized graphs.  

As a result, this approach is impractical for real-world or real-time ambulance dispatch systems.

**Analysis**
- **Time Complexity:** O(V!)  
- **Space Complexity:** O(V)

---

## 10. Priority Queue Based Greedy Routing

Priority queue based greedy routing was analyzed as an optimization technique commonly used in shortest path algorithms. By always selecting the node with the smallest tentative distance, this approach reduces unnecessary computations and improves overall efficiency.  

This technique forms the core of Dijkstra’s algorithm and plays a crucial role in achieving high performance for shortest path computation.

**Analysis**
- **Time Complexity:** O(E log E)  
- **Space Complexity:** O(V + E)

---

## Conclusion

From the analysis, it is evident that **Dijkstra’s Algorithm combined with Greedy Selection** is the most suitable approach for the ambulance dispatch problem. It provides optimal routing, efficient computation, and scalability, which are essential for real-time emergency response systems.
