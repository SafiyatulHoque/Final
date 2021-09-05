// Simple C++ implementation for Kruskal's
#include <bits/stdc++.h>
using namespace std;

#define V 8
int parent[V];

int find(int i)
{
	while (parent[i] != i)
		i = parent[i];
	return i;
}

void union1(int i, int j)
{
	int a = find(i);
	int b = find(j);
	parent[a] = b;
}

void kruskalMST(int cost[][V])
{
	int mincost = 0;

	for (int i = 0; i < V; i++)
		parent[i] = i;

	int edge_count = 0;
	cout<<"Edge \tWeight\n";
	while (edge_count < V - 1) {
		int min = INT_MAX, a = -1, b = -1;
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (find(i) != find(j) && cost[i][j] < min) {
					min = cost[i][j];
					a = i;
					b = j;
				}
			}
		}

		union1(a, b);
		
		printf("%d - %d \t  %d \n",
			 a, b, min);
		edge_count++;
		mincost += min;
	}
	printf("\nMinimum cost= %d \n", mincost);
}


int main()
{
	int cost[][V] = { { INT_MAX, 6, 7, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX },
						{ 6, INT_MAX, 8, 9, INT_MAX, 14, INT_MAX, INT_MAX },
						{ 7, 8, INT_MAX, 5, 4, INT_MAX, INT_MAX, INT_MAX },
						{ INT_MAX, 9, 5, INT_MAX, 6, 10, INT_MAX, INT_MAX },
						{ INT_MAX, INT_MAX, 4, 6, INT_MAX, INT_MAX, 7, INT_MAX },
						{ INT_MAX, 14, INT_MAX, 10, INT_MAX, INT_MAX, 11, 8 },
						{ INT_MAX, INT_MAX, INT_MAX, INT_MAX, 7, 11, INT_MAX, 6 },
						{ INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 8, 6, INT_MAX } }; //adjacency matrix

	// Print the solution
	kruskalMST(cost);

	return 0;
}
