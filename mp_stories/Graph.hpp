#include "Graph.h"
#include "Edge.h"
#include "Vertex.h"

#include <string>
#include <iostream>


/////////////USE ADJLIST algotithm in slides////////////


/**
* @return The number of vertices in the Graph
*/
template <class V, class E>
unsigned int Graph<V,E>::numVertices() const {
  //use adjacency matrix
  // TODO: Part 2
  return vertexMap.size();
}


/**
* The degree of the vertex. For directed: Sum of in-degree and out-degree
* @return Returns the degree of a given vertex.
* @param v Given vertex to return degree.
*/
template <class V, class E>
unsigned int Graph<V,E>::degree(const V & v) const {
  // TODO: Part 2
  //iterate through edges
  //find the number of edges with v as source_ or dest_

  //brute force algorithm///////////////////////
  // unsigned int degreeNum = 0;
  // edgeListIter it = edgeList.begin();
  // for (it = edgeList.begin(); it != edgeList.end(); it++){
  //   if(it->dest_ == v|| it->source_  == v){
  //     degreeNum++;
  //   }
  // }
  // return degreeNum;
  ///////////////////////////////////
  ///psuedocode
  unsigned int degreeNum = 0;
  char * Key = v->key;
  auto edgeList= unordered_map.find(Key);
  return edgeList.size();

}


/**
* Inserts a Vertex into the Graph.
* @param key The key of the Vertex to insert
* @return The inserted Vertex
*/
template <class V, class E>
V & Graph<V,E>::insertVertex(std::string key) {
  // TODO: Part 2
  V & v = *(new V(key));


  //???when we insert a vertex do we not create edges? 0 egdges in adjList

  //insert into vertex map
  vertexMap.insert(v);

  //initialize entry into adjList empty list
  adjList.push_back(std::list<edgeListIter>> list());
  return v;
}


/**
* Removes a given Vertex
* @param v The Vertex to remove
*/
template <class V, class E>
void Graph<V,E>::removeVertex(const std::string & key) {
  // TODO: Part 2
  auto vertIt = vertexMap.find(key);
  //remove vertex from map
  vertexMap.erase(key);

  //remove all edges with v from edgeListIter

  ////IS THIS OK??  EFFICIENT//////////
  auto it = edgeList.begin();
  for (it = edgeList.begin(); it != edgeList.end(); it++){
    if(it->dest_ == vertIt-|| it->source_  == v){
      edgeList.erase(key);
    }
  }

  //erase from ADJLIST
  adjustList.erase(key);

  return;

}


/**
* Inserts an Edge into the Graph.
* @param v1 The source Vertex
* @param v2 The destination Vertex
* @return The inserted Edge
*/
template <class V, class E>
E & Graph<V,E>::insertEdge(const V & v1, const V & v2) {
  // TODO: Part 2

  //insert edge into edgeList
  E & e = *(new E(v1, v2));
  edgeList.insert(e);


  //insert edge into adjList
  ////IS v1->key correct??///////
  auto edgeIter = edgeList.find(e);


  auto v1adjList = adjList.find(v1->key);
  v1adjList.push_back(edgeIter);

  auto v2adjList = adjList.find(v2->key);
  v2adjList.push_back
  +

  return e;
}


/**
* Removes an Edge from the Graph. Consider both the undirected and directed cases.
* min(degree(key1), degree(key2))
* @param key1 The key of the source Vertex
* @param key2 The key of the destination Vertex
*/
template <class V, class E>
void Graph<V,E>::removeEdge(const std::string key1, const std::string key2) {
  // TODO: Part 2
  V V1, V2;
  V1 = vertexMap.find(key1);
  V2 = vertexMap.find(key2);

  edgeListIter it = edgeList.begin();
  for (it = edgeList.begin(); it != edgeList.end(); it++){
    if ((it->dest_ == V1) && (it->source_ == V2) || (it->dest_ == V2) && (it->source_ == V1))
    {
      edgeList.erase(it);
    }
  }
  return;
}


/**
* Removes an Edge from the Graph given by the location of the given iterator into the edge list.
* @param it An iterator at the location of the Edge that
* you would like to remove
*/
template <class V, class E>
void Graph<V,E>::removeEdge(const edgeListIter & it) {
  // TODO: Part 2
  edgeList.erase(it);
  return;
}


/**
* Return the list of incident edges from a given vertex.
* For the directed case, consider all edges that has the vertex as either a source or destination.
* @param key The key of the given vertex
* @return The list edges (by reference) that are adjacent to the given vertex
*/
template <class V, class E>
const std::list<std::reference_wrapper<E>> Graph<V,E>::incidentEdges(const std::string key) const {
  // TODO: Part 2
  std::list<std::reference_wrapper<E>> edges;
  return edges;
}


/**
* Return whether the two vertices are adjacent to one another. Consider both the undirected and directed cases.
* When the graph is directed, v1 and v2 are only adjacent if there is an edge from v1 to v2.
* @param key1 The key of the source Vertex
* @param key2 The key of the destination Vertex
* @return True if v1 is adjacent to v2, False otherwise
*/
template <class V, class E>
bool Graph<V,E>::isAdjacent(const std::string key1, const std::string key2) const {
  // TODO: Part 2
  return false;
}
