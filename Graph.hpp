#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "GraphBase.hpp"
#include <list>
#include <limits.h>
#include <queue>
#include <map>

class Edge { 
public:
    Edge(std::string label1, unsigned long _weight) : //constructor
        endpoint{label1}, weight{_weight} {}
    ~Edge() = default; //destructor
    std::string get_endpoint() const { return endpoint; } //get the endpoint 
    unsigned long get_weight() const { return weight; } //get the weight 
private: // data members
    std::string endpoint; //endpoints 
    unsigned long weight; //weight of the edge
};

class Vertex {
public:
    Vertex(std::string held = "") : element{held} {}; //constructor
    ~Vertex() = default; //destructor

    std::string operator*() { return element; }; //return element at vertex
    
    void push_back_edge(Edge* e) { edge_list.push_back(e); } //push the edge back 
    void remove_edge(Edge* edge) { edge_list.remove(edge); } //remove the edge 

    std::list<Edge*> get_edge_list() { return edge_list; } //returns the edge list 
private:
    std::string element;
    std::list<Edge*> edge_list; //list of the edges 
};

class Graph : public GraphBase {
public:
    Graph() = default;//constructor
    ~Graph(); //destructor
    Vertex at(std::string label); //returns the element of a vertex 
    std::vector<Vertex> get_adjacency_list() const { return adjacency_list; } 

    virtual void addVertex(std::string label); //inserts a new vertex to store the element
    virtual void removeVertex(std::string label);  //remove vertex containing the element and all its incident edges
    virtual void addEdge(std::string label1, std::string label2, unsigned long weight); //insert a new edge 
    virtual void removeEdge(std::string label1, std::string label2); // remove the edge 
    virtual unsigned long shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path); //calculates the shortestPath of the verticies
private:
    std::vector<Vertex> adjacency_list; //holds Vertex objects
};

#endif