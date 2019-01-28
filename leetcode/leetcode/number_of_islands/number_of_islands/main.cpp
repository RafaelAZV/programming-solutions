#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool check_boundaries(vector<vector<char>> &grid, int i, int j){

	if(i < 0 || i >= grid.size()) return false;
	if(j < 0 || j >= grid[0].size()) return false;

	return true;
}


void dfs(vector<vector<char>> &grid, int i, int j){

	grid[i][j] = '2';
    //right
	if(check_boundaries(grid, i, j + 1) && grid[i][j + 1] == '1') dfs(grid, i, j + 1);
	//left
	if(check_boundaries(grid, i, j - 1) && grid[i][j - 1] == '1') dfs(grid, i, j - 1);
	//down
	if(check_boundaries(grid, i + 1, j) && grid[i + 1][j] == '1') dfs(grid, i + 1, j);
	//up
	if(check_boundaries(grid, i - 1, j) && grid[i - 1][j] == '1') dfs(grid, i - 1, j);

}


int numIslands(vector<vector<char>>& grid){

	int count = 0;
	if(grid.empty()) return 0;
	if(grid[0].empty()) return 0;

	for(int i = 0; i < grid.size(); i++){
		for(int j = 0; j < grid[0].size(); j++){
			if(grid[i][j] == '1'){
				dfs(grid, i, j);
				count++;
			}
		}
	}

	return count;
}


int main(){

	vector<char> row1 = {'1', '1', '1', '1', '0'};
	vector<char> row2 = {'1', '1', '0', '1', '0'};
	vector<char> row3 = {'1', '1', '0', '0', '0'};
	vector<char> row4 = {'0', '0', '0', '0', '0'};
	vector<vector<char>> grid;

	grid.push_back(row1);
	grid.push_back(row2);
	grid.push_back(row3);
	grid.push_back(row4);

	std::cout << numIslands(grid);

    return 0;
}
