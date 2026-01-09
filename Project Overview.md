# 🚑 Intelligent Ambulance Dispatch and Route Optimization
### Design and Analysis of Algorithms – Course Project

> An algorithmic solution for selecting the best ambulance and computing the fastest route using graph algorithms to minimize emergency response time.

---

## 📌 Project Overview

Emergency medical response time plays a critical role in saving lives. In large cities, manually deciding which ambulance should respond and which route to take is inefficient and error-prone.

This project models a **city road network as a weighted graph** and applies **Dijkstra’s Algorithm** to compute shortest travel times. A **Greedy Selection Algorithm** is then used to choose the ambulance that can reach the emergency location in minimum time.

---

## 🎯 Problem Definition

When an emergency call is received, the control center must:

- Decide which ambulance should respond  
- Find the fastest route through the city road network  
- Handle large graphs with many junctions and roads  
- Make quick and optimal decisions  

The system must efficiently compute:
- Shortest travel times on a weighted graph  
- Best ambulance among multiple available ambulances  

---

## 👥 Users

- Ambulance control room operators  
- Emergency response teams  

---

## 🌍 Real-World Modeling

| Real World Entity | Graph Representation |
|------------------|----------------------|
| City junctions | Nodes (Vertices) |
| Roads | Edges |
| Travel time / distance | Edge weights |
| Ambulance locations | Source nodes |
| Emergency incident | Destination node |

