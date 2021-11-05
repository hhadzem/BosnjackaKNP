#include<iostream>
#include<string>
#include<string.h>
using namespace std;
bool inBound(int x){
	if(x < 0 || x > 6)
		return false;
	return true;
}
struct Point{ int x; int y; };
bool visited[7][7];
Point to{6, 0};
string desc;
 
inline void solve(int from_x, int from_y, int &counter, unsigned int moves){
	int rem = 48 - moves; 
	if(moves > 49)
		return;
	if(abs(from_x - to.x) + abs(from_y - to.y) > rem)
		return;
	if(from_x == to.x && from_y == to.y){
		if(moves == desc.length()){
			counter++;
		}
		return;
	}
	
	if(from_x != 0 && !visited[from_x-1][from_y]
			&& from_x != 6  && !visited[from_x+1][from_y]
			&& (from_y == 0 || visited[from_x][from_y-1])
			&& (from_y == 6 || visited[from_x][from_y+1]))
		return;
	if(from_y != 0 && !visited[from_x][from_y-1]
			&& from_y != 6 && !visited[from_x][from_y+1]
			&& (from_x == 0 || visited[from_x-1][from_y])
			&& (from_x == 6 || visited[from_x+1][from_y]))
		return;
	
	visited[from_x][from_y] = true;
	if(desc[moves] == 'U'){ if(from_x != 0 && !visited[from_x-1][from_y])
		solve(from_x-1, from_y, counter, moves + 1);}
	else if(desc[moves] == 'D'){ if(from_x != 6 && !visited[from_x+1][from_y])
		solve(from_x+1, from_y, counter, moves + 1);}
	else if(desc[moves] == 'R'){ if(from_y != 6 && !visited[from_x][from_y+1])
		solve(from_x, from_y+1, counter, moves + 1);}
	else if(desc[moves] == 'L'){ if(from_y != 0 && !visited[from_x][from_y-1])
		solve(from_x, from_y-1, counter, moves + 1);}
	else{
		if(from_x != 0 && !visited[from_x-1][from_y])
			solve(from_x-1, from_y, counter, moves + 1);
		if(from_x != 6 && !visited[from_x+1][from_y])
			solve(from_x+1, from_y, counter, moves + 1);
		if(from_y != 6 && !visited[from_x][from_y+1])
			solve(from_x, from_y+1, counter, moves + 1);
		if(from_y != 0 && !visited[from_x][from_y-1])
			solve(from_x, from_y-1, counter, moves + 1);
	}
	visited[from_x][from_y] = false;
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> desc;
	int counter = 0;
	solve(0,0, counter, 0);
	cout << counter << endl;
	return 0;
}
