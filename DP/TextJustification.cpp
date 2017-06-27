#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int justify(string *words, int len, int width)
{
	int cost[len][len];

	for(int i=0;i<len;i++)
	{
		cost[i][i] = width - words[i].size();
		for(int j=i+1;j<len;j++)
		{
			cost[i][j] = cost[i][j-1] - words[j].size() - 1;
		}
	}

	for(int i=0;i<len;i++)
	{
		for(int j=i;j<len;j++)
		{
			if(cost[i][j] < 0)
			{
				cost[i][j] = INT_MAX;
			}
			else
			{
				cost[i][j] = cost[i][j] * cost[i][j];
			}
		}
	}

	int costArr[len];
	int res[len];

	for(int i=len-1;i>=0;i--)
	{
		costArr[i] = cost[i][len-1];
		res[i] = len;
		for(int j=len-1;j>i;j--)
		{
			if(cost[i][j-1] == INT_MAX)
			{
				continue;
			}
			if(costArr[j] + cost[i][j-1] < costArr[i])
			{
				costArr[i] = costArr[j] + cost[i][j-1];
				res[i] = j;
			}
		}
	}

	int i = 0;
	int j = 0;
	string result;
	while(j<len)
	{
		j = res[i];
		for(int k=i;k<j;k++)
		{
			result += words[k] + " ";
		}
		result += "\n";
		i = j;
	}
	cout<<result;
	return costArr[0];
}

int main()
{
	string words[] = {"Tushar","Roy","likes","to","code"};
	int width = 10;
	int len = 5;
	cout<<justify(words,len,width)<<"\n";
	return 0;
}