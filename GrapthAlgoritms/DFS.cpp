#include "pch.h"
#include "DFS.h"
using namespace std;

void DFS(list<int>* L, list<TPare>* T, int n,int v, int count, int* visited) 
{
	int w;
	visited[v] = 1;
	
	list<int>::iterator it = L[v].begin();
	while (it != L[v].end())
	{
		w = *it;
		if (!visited[w]) 
		{
			TPare pare(v, w);
			T[count].push_back(pare);
			DFS(L, T, n, w, count, visited);
		}
		++it;
		
	}

} 
int RoundDFS(list<int>* L, list<TPare>* T, int n)
{
	int v;
	int* visited = new int[n];
	for (v = 0; v < n; ++v)
		visited[v] = 0;
	int count = 0;
	for (v = 0; v < n; ++v)
		if (!visited[v]) {
			++count;
			DFS(L, T, n, v, count, visited);
		}
	return count;
}
