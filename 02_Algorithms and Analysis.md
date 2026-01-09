# Analysis of Algorithms

The following algorithms were studied and analyzed for solving the **Intelligent Ambulance Dispatch and Route Optimization** problem. Each algorithm was evaluated based on its suitability for shortest path computation, efficiency, scalability, and real-time applicability.

---

## 1. Dijkstra’s Algorithm

Dijkstra’s algorithm was analyzed because it is one of the most widely used algorithms for finding the shortest path in a weighted graph with non-negative edge weights. In the ambulance dispatch problem, the road network is represented as a graph where nodes denote junctions and edges represent roads with positive travel times.  

Dijkstra’s algorithm efficiently computes the minimum travel time from a source node (emergency location) to all other nodes. This makes it highly suitable for estimating ambulance response times. Its guaranteed optimality and good performance make it ideal for real-time emergency applications.
```sql
DIJKSTRA(n, source)
    INF ← very large number
    dist[0 … n−1] ← INF

    dist[source] ← 0

    Create a min-priority queue PQ
    Insert (0, source) into PQ

    WHILE PQ is not empty DO
        (currentDist, u) ← Extract minimum from PQ

        IF currentDist > dist[u] THEN
            CONTINUE
        END IF

        FOR each edge (u → v) with weight w in adjacency list of u DO
            IF dist[v] > dist[u] + w THEN
                dist[v] ← dist[u] + w
                Insert (dist[v], v) into PQ
            END IF
        END FOR
    END WHILE

    RETURN dist
END DIJKSTRA

```


**Analysis**
- **Time Complexity:** O((V + E) log V)  
- **Space Complexity:** O(V + E)

---

## 2. Bellman–Ford Algorithm

The Bellman–Ford algorithm was studied because it supports graphs with negative edge weights and can detect negative cycles. Although this makes it more flexible than Dijkstra’s algorithm, it is not suitable for the ambulance dispatch system since travel times on roads cannot be negative.  

Additionally, the algorithm has a much higher time complexity, which makes it inefficient for large city road networks and unsuitable for real-time emergency response.
### 📌 Pseudocode – Bellman–Ford Algorithm

```sql
BEGIN
    SET INF = very large value
    CREATE array dist[0 … n-1]

    FOR each vertex i FROM 0 TO n-1 DO
        dist[i] ← INF
    END FOR

    dist[source] ← 0

    -- Relax all edges (n − 1) times
    FOR i FROM 1 TO n-1 DO
        FOR each vertex u FROM 0 TO n-1 DO
            IF dist[u] ≠ INF THEN
                FOR each edge (u, v, w) IN graphAdj[u] DO
                    IF dist[v] > dist[u] + w THEN
                        dist[v] ← dist[u] + w
                    END IF
                END FOR
            END IF
        END FOR
    END FOR

    RETURN dist
END
```



**Analysis**
- **Time Complexity:** O(V × E)  
- **Space Complexity:** O(V)

---

## 3. Breadth First Search (BFS)

Breadth First Search was analyzed as it can find shortest paths in unweighted graphs. However, real-world road networks are weighted, as different roads have different travel times and distances.  

Since BFS does not support weighted edges, it cannot accurately compute the shortest travel-time routes required for ambulance routing.
### 📌 Pseudocode – Breadth First Search (BFS) Algorithm

```sql
BEGIN
    SET INF = very large value
    CREATE array dist[0 … n-1]
    CREATE empty queue Q

    FOR each vertex i FROM 0 TO n-1 DO
        dist[i] ← INF
    END FOR

    dist[source] ← 0
    ENQUEUE(Q, source)

    WHILE Q is not empty DO
        u ← DEQUEUE(Q)

        FOR each edge (u, v) IN graphAdj[u] DO
            IF dist[v] = INF THEN
                dist[v] ← dist[u] + 1     -- each edge has cost 1
                ENQUEUE(Q, v)
            END IF
        END FOR
    END WHILE

    RETURN dist
END
```


**Analysis**
- **Time Complexity:** O(V + E)  
- **Space Complexity:** O(V)

---

## 4. Depth First Search (DFS)

Depth First Search was considered as a basic graph traversal technique. While DFS is useful for exploring connectivity within a graph, it does not guarantee the shortest path between two nodes.  

Because ambulance routing requires the minimum travel time between locations, DFS does not satisfy the problem requirements and was therefore not considered further.
### 📌 Pseudocode – DFS-Based Shortest Path Algorithm

```sql
BEGIN
    SET INF = very large value
    CREATE array dist[0 … n-1]
    CREATE array visited[0 … n-1]

    FOR each vertex i FROM 0 TO n-1 DO
        dist[i] ← INF
        visited[i] ← FALSE
    END FOR

    dist[source] ← 0
    CALL DFS_UTIL(source)

    RETURN dist
END


PROCEDURE DFS_UTIL(u)
    visited[u] ← TRUE

    FOR each edge (u, v, w) IN graphAdj[u] DO
        IF dist[v] > dist[u] + w THEN
            dist[v] ← dist[u] + w
        END IF

        IF visited[v] = FALSE THEN
            CALL DFS_UTIL(v)
        END IF
    END FOR
END PROCEDURE
```

**Analysis**
- **Time Complexity:** O(V + E)  
- **Space Complexity:** O(V)

---

## 5. Floyd–Warshall Algorithm

The Floyd–Warshall algorithm computes shortest paths between all pairs of vertices in a graph. While this provides complete distance information, it involves unnecessary computation for the ambulance dispatch problem, which only requires shortest paths from a specific source.  

Its very high time complexity makes it impractical for large graphs and unsuitable for real-time emergency systems.
### 📌 Pseudocode – Floyd–Warshall Algorithm

```sql
BEGIN
    SET INF = very large value
    CREATE matrix dist[0 … n-1][0 … n-1]

    -- Initialize distance matrix
    FOR i FROM 0 TO n-1 DO
        FOR j FROM 0 TO n-1 DO
            IF i = j THEN
                dist[i][j] ← 0
            ELSE
                dist[i][j] ← INF
            END IF
        END FOR
    END FOR

    -- Initialize distances using adjacency list
    FOR each vertex u FROM 0 TO n-1 DO
        FOR each edge (u, v, w) IN graphAdj[u] DO
            dist[u][v] ← MIN(dist[u][v], w)
        END FOR
    END FOR

    -- Floyd–Warshall core logic
    FOR k FROM 0 TO n-1 DO
        FOR i FROM 0 TO n-1 DO
            IF dist[i][k] ≠ INF THEN
                FOR j FROM 0 TO n-1 DO
                    IF dist[k][j] ≠ INF AND
                       dist[i][j] > dist[i][k] + dist[k][j] THEN
                        dist[i][j] ← dist[i][k] + dist[k][j]
                    END IF
                END FOR
            END IF
        END FOR
    END FOR

    RETURN dist[source]
END
```

**Analysis**
- **Time Complexity:** O(V³)  
- **Space Complexity:** O(V²)

---

## 6. Greedy Selection Algorithm

A greedy selection algorithm was analyzed for selecting the best ambulance among multiple available ambulances. Once the shortest travel time for each ambulance is known, choosing the ambulance with the minimum response time is a greedy decision.  

This locally optimal choice also results in a globally optimal solution, making greedy selection efficient and well-suited for ambulance dispatch decisions.
### 📌 Pseudocode – Greedy Ambulance Selection Algorithm

```sql
BEGIN
    SET minTime ← INF
    SET bestAmbulance ← -1

    -- Select ambulance with minimum travel time
    FOR i FROM 0 TO A-1 DO
        IF dist[ambulanceNodes[i]] < minTime THEN
            minTime ← dist[ambulanceNodes[i]]
            bestAmbulance ← i
        END IF
    END FOR

    PRINT "----------------------------------"

    IF bestAmbulance = -1 OR minTime = INF THEN
        PRINT "No ambulance can reach the incident."
    ELSE
        PRINT "Selected Ambulance ID:", bestAmbulance
        PRINT "Ambulance Location Node:", ambulanceNodes[bestAmbulance]
        PRINT "Estimated Minimum Travel Time:", minTime
    END IF

    PRINT "----------------------------------"
END
```

**Analysis**
- **Time Complexity:** O(A)  
- **Space Complexity:** O(V)

---

## 7. Dynamic Programming

Dynamic programming techniques were studied because they are effective for problems with overlapping subproblems and optimal substructure. However, shortest path problems on large and dynamic road networks are better handled by specialized graph algorithms.  

Dynamic programming does not provide any performance benefit for real-time route computation and was therefore found unsuitable for this application.
### 📌 Pseudocode – Dynamic Programming Based Shortest Path Algorithm

```sql
BEGIN
    SET INF = very large value

    -- dp[k][v] = minimum distance to reach vertex v using at most k edges
    CREATE matrix dp[0 … n-1][0 … n-1]

    FOR k FROM 0 TO n-1 DO
        FOR v FROM 0 TO n-1 DO
            dp[k][v] ← INF
        END FOR
    END FOR

    dp[0][source] ← 0

    FOR k FROM 1 TO n-1 DO
        -- Carry forward previous distances
        FOR v FROM 0 TO n-1 DO
            dp[k][v] ← dp[k-1][v]
        END FOR

        -- Relax edges
        FOR each vertex u FROM 0 TO n-1 DO
            IF dp[k-1][u] ≠ INF THEN
                FOR each edge (u, v, w) IN graphAdj[u] DO
                    IF dp[k][v] > dp[k-1][u] + w THEN
                        dp[k][v] ← dp[k-1][u] + w
                    END IF
                END FOR
            END IF
        END FOR
    END FOR

    -- Compute final shortest distances
    CREATE array dist[0 … n-1]

    FOR v FROM 0 TO n-1 DO
        dist[v] ← INF
        FOR k FROM 0 TO n-1 DO
            dist[v] ← MIN(dist[v], dp[k][v])
        END FOR
    END FOR

    RETURN dist
END
```

**Analysis**
- **Time Complexity:** O(V × E)  
- **Space Complexity:** O(V²)

---

## 8. Minimum Spanning Tree Algorithms (Prim’s and Kruskal’s)

Minimum spanning tree algorithms were analyzed because they minimize the total cost required to connect all nodes in a graph. However, these algorithms do not guarantee the shortest path between a specific source and destination.  

Since ambulance dispatch requires finding the shortest route from an ambulance to an emergency location, MST algorithms were not appropriate.
### 📌 Prim’s Algorithm + DFS on MST (Shortest Path Approximation)

**Algorithm Steps:**
1. Construct a Minimum Spanning Tree (MST) using **Prim’s Algorithm**.
2. Build an adjacency list from the MST.
3. Perform **DFS** on the MST starting from the source node.
4. Accumulate edge weights during DFS to compute distances.

---

**Analysis**
- **Time Complexity:** O(E log V)  
- **Space Complexity:** O(V + E)

---

## 9. Brute Force Approach

The brute force approach was analyzed as a baseline method in which all possible paths are explored to determine the shortest one. While this approach guarantees correctness, its exponential time complexity makes it infeasible even for moderately sized graphs.  

As a result, this approach is impractical for real-world or real-time ambulance dispatch systems.
### 📌 Pseudocode – Brute Force DFS for Shortest Path

```sql
PROCEDURE BRUTE_DFS(u, currDist)
    IF currDist ≥ dist[u] THEN
        RETURN        -- pruning
    END IF

    dist[u] ← currDist
    visited[u] ← TRUE

    FOR each edge (u, v, w) IN graphAdj[u] DO
        IF visited[v] = FALSE THEN
            CALL BRUTE_DFS(v, currDist + w)
        END IF
    END FOR

    visited[u] ← FALSE    -- backtracking
END PROCEDURE


BEGIN
    SET INF = very large value
    CREATE array dist[0 … n-1]
    CREATE array visited[0 … n-1]

    FOR each vertex i FROM 0 TO n-1 DO
        dist[i] ← INF
        visited[i] ← FALSE
    END FOR

    CALL BRUTE_DFS(source, 0)

    RETURN dist
END
```

**Analysis**
- **Time Complexity:** O(V!)  
- **Space Complexity:** O(V)

---

## 10. Priority Queue Based Greedy Routing

Priority queue based greedy routing was analyzed as an optimization technique commonly used in shortest path algorithms. By always selecting the node with the smallest tentative distance, this approach reduces unnecessary computations and improves overall efficiency.  

This technique forms the core of Dijkstra’s algorithm and plays a crucial role in achieving high performance for shortest path computation.
### 📌 Pseudocode – Priority Queue Based Greedy Routing

```sql
BEGIN
    SET INF = very large value
    CREATE array dist[0 … n-1]
    CREATE array visited[0 … n-1]
    CREATE min-priority queue PQ   -- (cost, node)

    FOR each vertex i FROM 0 TO n-1 DO
        dist[i] ← INF
        visited[i] ← FALSE
    END FOR

    dist[source] ← 0
    INSERT (0, source) INTO PQ

    WHILE PQ is not empty DO
        (cost, u) ← EXTRACT_MIN(PQ)

        IF visited[u] = TRUE THEN
            CONTINUE
        END IF

        visited[u] ← TRUE

        FOR each edge (u, v, w) IN graphAdj[u] DO
            IF visited[v] = FALSE AND dist[v] = INF THEN
                dist[v] ← dist[u] + w      -- greedy choice
                INSERT (w, v) INTO PQ
            END IF
        END FOR
    END WHILE

    RETURN dist
END
```

**Analysis**
- **Time Complexity:** O(E log E)  
- **Space Complexity:** O(V + E)

---

## Conclusion

From the analysis, it is evident that **Dijkstra’s Algorithm combined with Greedy Selection** is the most suitable approach for the ambulance dispatch problem. It provides optimal routing, efficient computation, and scalability, which are essential for real-time emergency response systems.
