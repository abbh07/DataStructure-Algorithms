#include <iostream>
#define MAX 20

using namespace std;

class queue
{
private:
	int front;
	int rear;
	int arr[MAX];
public:
	queue()
	{
		front = 0;
		rear = -1;
	}
	void enqueue(int);
	int dequeue();
	int isEmpty();
};

void queue::enqueue(int val)
{
	if(rear == MAX-1)
	{
		cout<<"Queue full!\n";
		return;
	}
	arr[++rear] = val;
}

int queue::dequeue()
{
	if(front>rear)
	{
		cout<<"Queue Empty!\n";
		return -1;
	}
	return arr[front++];
}

int queue::isEmpty()
{
	if(front>rear)
		return 1;
	else
		return 0;
}



class Node
{
private:
	int vertex;
	Node* next;
public:
	Node* head[20] = {NULL};
	int visited[20];
	int n;
	Node()
	{
		next = NULL;
	}
	Node* addRear(Node*,int);
	void createGraph(Node* head[]);
	void display(Node*);
	void dfs(int);
	void bfs(int);
	void adjList(Node* head[]);

};

Node* Node::addRear(Node* n,int v)
{
	Node* temp = new Node();
	temp->vertex = v;
	Node* temp2 = n;
	if(n == NULL)
		return temp;
	else
	{
		while(temp2->next != NULL)
		{
			temp2 = temp2->next;
		}
		temp2->next = temp;
		return n;
	}
}

void Node::createGraph(Node* head[])
{
	cout<<"Enter the number of vertices\n";
	cin>>n;
	int v;
	for(int i=0;i<n;i++)
	{
		while(1)
		{
			cout<<"Enter the next adjacent vertex for vertex "<<i<<endl;
			cin>>v;
			if(v==-1)
				break;
			head[i] = addRear(head[i],v);
		}
	}
}

void Node::dfs(int item)
{
	Node* temp;
	cout<<item<<"\t";
	visited[item] = 1;
	for(temp = head[item];temp;temp = temp->next)
	{
		if(visited[temp->vertex] == 0)
			dfs(temp->vertex);
	}
}

void Node::bfs(int item)
{
	queue q;
	Node* temp;
	visited[item] = 1;
	cout<<item<<"\t";
	q.enqueue(item);
	while(q.isEmpty() != 1)
	{
		item = q.dequeue();
		for(temp = head[item];temp;temp=temp->next)
		{
			if(visited[temp->vertex] == 0)
			{
				cout<<temp->vertex<<"\t";
				q.enqueue(temp->vertex);
				visited[temp->vertex] = 1;
			}
		}
	}
}

void Node::display(Node* n)
{
	while(n !=NULL)
	{
		cout<<n->vertex<<"\t";
		n = n->next;
	}
}

void Node::adjList(Node* head[])
{
	cout<<"Adjacency List:\n";
	for(int i=0;i<n;i++)
	{
		cout<<"For vertex: "<<i<<"\n";
		display(head[i]);
		cout<<endl;
	}
}

int main()
{
	Node graph;
	graph.createGraph(graph.head);
	graph.adjList(graph.head);
	cout<<"Depth first search:\n";
	for(int j = 0;j<graph.n;j++)
	{
		for(int i=0;i<graph.n;i++)
		{
			graph.visited[i] = 0;
		}
		cout<<"From vertex "<<j<<" is ";
		graph.dfs(j);
		cout<<endl;
	}
	cout<<"Breadth first search:\n";
	for(int j=0;j<graph.n;j++)
	{
		for(int i=0;i<graph.n;i++)
		{
			graph.visited[i] = 0;
		}
		cout<<"From vertex "<<j<<" is ";
		graph.bfs(j);
		cout<<endl;
	}
	return 0;

}
