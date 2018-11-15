#include <iostream>
#include <vector>
#include <bits/stdc++.h>
# define INF 0x3f3f3f3f
using namespace std;
typedef pair<int, int> iPair;
typedef std::vector<std::vector<iPair> > Graph;



void add_edges(Graph &graph, int from, int to, int weight, bool is_undirected){
    graph[from].push_back(make_pair(to, weight));
    if(is_undirected) graph[to].push_back(make_pair(from, weight));
}


int get_distance(std::vector<int> cummulative_distance, int weight, int u){

    int total = weight - cummulative_distance[u];
    if(total < 0) total = 0;

    return total + cummulative_distance[u];
}


void shortestPath(Graph graph, int src, int target) {

    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

    vector<int> dist(graph.size(), INF);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()){

        int u = pq.top().second;
        pq.pop();

        for(int i = 0; i < graph[u].size(); i++){

            int v = graph[u][i].first;
            int weight = graph[u][i].second;
            int total = get_distance(dist, weight, u);

            if(dist[v] > total){
                dist[v] = total;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    std::cout << dist[target] << std::endl;
}



int main(){

    Graph graph(5);

    add_edges(graph, 0, 1, 60, false);
    add_edges(graph, 2, 4, 70, false);
    add_edges(graph, 0, 3, 120, false);
    add_edges(graph, 3, 4, 150, false);
    add_edges(graph, 1, 2, 80, false);

    shortestPath(graph, 0, 4);

    return 0;
}
