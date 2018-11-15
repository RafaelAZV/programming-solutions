#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int, int> iPair;
typedef std::vector<std::vector<iPair> > Graph;

void add_edges(Graph &graph, int from, int to, int weight, bool is_undirected){
    graph[from].push_back(make_pair(to, weight));
    if(is_undirected) graph[to].push_back(make_pair(from, weight));
}

void primMST(Graph graph, int vertex_number, int src){

    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

    vector<int> key(vertex_number, INF);

    vector<int> parent(vertex_number, -1);

    vector<bool> inMST(vertex_number, false);

    pq.push(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty()){

        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for(int i = 0; i < graph[u].size(); i++){

        	int v = graph[u][i].first;
        	int weight = graph[u][i].second;

        	if(inMST[v] == false && key[v]  > weight){
        		key[v] = weight;
        		pq.push(make_pair(key[v], v));
        		parent[v] = u;
        	}
        }
    }

    int result = 0;
    for(int i = 0; i < key.size(); i++){
    	if(key[i] != INF){
    		result += key[i];
    	}
    }

    std::cout << result << std::endl;
}

int main(){

    int vertex_number = 5, edges_number = 6;
    int from, to, weight;
    Graph graph(vertex_number);

    add_edges(graph, 0, 1, 3, true);
    add_edges(graph, 0, 2, 4, true);
    add_edges(graph, 3, 1, 6, true);
    add_edges(graph, 4, 1, 2, true);
    add_edges(graph, 1, 2, 5, true);
    add_edges(graph, 2, 4, 7, true);

    primMST(graph, vertex_number, 1);

    return 0;
}
