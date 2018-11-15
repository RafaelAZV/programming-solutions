#include <iostream>
#include <vector>
using namespace std;
typedef std::vector<std::vector<int> > Graph;

void add_edges(Graph &graph, int from, int to, bool is_undirected){
    graph[from].push_back(to);
    if(is_undirected) graph[to].push_back(from);
}

void dfs_util(Graph graph, std::vector<bool> &visited, int current_vertex, int *set_size){

    visited[current_vertex] = true;

    for(int i = 0; i < graph[current_vertex].size(); i++){
        if(!visited[graph[current_vertex][i]]){
            *set_size = *set_size + 1;
            dfs_util(graph, visited, graph[current_vertex][i], set_size);
        }
    }
}


int dfs(Graph graph, int vertex_number){

    std::vector<bool> visited (vertex_number, false);
    std::vector<int> sets_sizes;

    int possibilities = 0;
    int sets_found = 0;
    int first_set = 0;
    int sets_sum = 0;

    for(int i = 0; i < graph.size(); i++){

        if(!visited[i]) {
            int set_size = 1;
            dfs_util(graph, visited, i, &set_size);
            sets_sizes.push_back(set_size);
        }
    }

    for(int i = 0; i < sets_sizes.size(); i++){
        possibilities += sets_sizes[i]*sets_sum;
        sets_sum += sets_sizes[i];
    }

    return possibilities;
}


int journeyToMoon(int n, vector<vector<int>> astronaut) {

    Graph graph (n);

    for(int i = 0; i < astronaut.size(); i++)
        add_edges(graph, astronaut[i][0], astronaut[i][1], true);

    return dfs(graph, n);

}


int main(){

    std::vector<std::vector<int> > astronaut(1);
    astronaut[0] = {0, 2};

    std::cout << journeyToMoon(4, astronaut) << std::endl;
    return 0;
}
