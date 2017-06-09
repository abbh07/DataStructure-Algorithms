<<<<<<< HEAD
=======
//O(V E)
/*
4 5
0 1 1
0 2 3
0 3 4
1 2 2
2 3 5
*/
>>>>>>> cace9e25b84914acbd10dec73cc3be494692a162
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100;
int nodes,edges;
vector<int> dis(MAX,100000);

void bellman_ford(vector<int> v[])
{
	//Starting from vertex 0
	dis[0] = 0;
	for(int i=0;i<nodes-1;i++)
	{
		int j = 0;
		while(v[j].size() != 0)
		{
			if(dis[v[j][0]] + v[j][2] < dis[v[j][1]])
			{
				dis[v[j][1]] = dis[v[j][0]] + v[j][2];
			}
			j++;
		}
	}
}

int main()
{
	cin>>nodes>>edges;
	int from, to, cost;	
	vector<int> v[MAX];

	for(int i=0;i<edges;i++)
	{
		cin>>from>>to>>cost;
		v[i].push_back(from);
		v[i].push_back(to);
		v[i].push_back(cost);
	}
	bellman_ford(v);
	for(int i=0;i<nodes;i++)
	{
		cout<<dis[i]<<" ";
	}
	cout<<endl;
	return 0;
}