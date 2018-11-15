#include <iostream>
#include <vector>
using namespace std;

void add_edges(std::vector<std::vector<int>> &graph, int from, int to, bool is_undirected){
    std::cout << from << std::endl;
    std::cout << to << std::endl;
	from = from - 1;
	to = to - 1;
	graph[from].push_back(to);
	if(is_undirected) graph[to].push_back(from);

}

int dfs_util(std::vector<std::vector<int>> graph, std::vector<bool> visited, int current, int children_total, int *cuts){

	visited[current] = true;
	int children_in_path = 0;

	if(graph[current].size() <= 1) return 1;

	else{

		for(int i = 0; i < graph[current].size(); i++){

			if(!visited[graph[current][i]]){
				children_in_path = dfs_util(graph, visited, graph[current][i], children_total, cuts);
				children_total += children_in_path;

				if(children_in_path % 2 == 0){
					*cuts = *cuts + 1;
					children_total -= children_in_path;
				}
			}
		}
	}

	return children_total + 1;
}

int dfs(std::vector<std::vector<int>> graph, int vertex_number){

	std::vector<bool> visited (vertex_number);

	int current_cut = 0;
	int total_cuts = 0;
    visited[0] = true;

    for(int i = 0; i < graph[0].size(); i++){
        current_cut = dfs_util(graph, visited, graph[0][i], current_cut, &total_cuts);
        if(current_cut%2 == 0) total_cuts++;
        current_cut = 0;
	}

	return total_cuts;
}

int evenForest(int t_nodes, int t_edges, vector<int> t_from, vector<int> t_to) {

	std::vector<std::vector<int>> graph (t_nodes);

	for(int i = 0; i < t_edges; i++) add_edges(graph, t_from[i], t_to[i], true);
    std::cout << "here";
	return dfs(graph, t_nodes);
}



int main()
{
    std::vector<int> t_from = {1,1,1,2,2,3,6,8,8};
    std::vector<int> t_to = {2,3,6,5,7,4,8,9,10};

    evenForest(10, 9, t_from, t_to);


    return 0;
}
