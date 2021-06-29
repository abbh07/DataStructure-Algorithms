#include <iostream>
#include <vector>

using namespace std;

// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/tutorial/

void initialize(vector<int> &disjoint_set, int n)
{
    for (int i = 0; i < n; i++)
    {
        disjoint_set[i] = i;
    }
}

// Finding root using path compression.
// Set each i to point to its grandparent thereby halving the length of the path.
int root(vector<int> &disjoint_set, int element)
{
    while (disjoint_set[element] != element)
    {
        disjoint_set[element] = disjoint_set[disjoint_set[element]];
        element = disjoint_set[element];
    }
    return element;
}

// Logarithmic time because balanced tree.
void weighted_union(vector<int> &disjoint_set, vector<int> &set_size, int element1, int element2)
{
    int root_1 = root(disjoint_set, element1);
    int root_2 = root(disjoint_set, element2);

    if (set_size[root_1] < set_size[root_2])
    {
        disjoint_set[root_1] = disjoint_set[root_2];
        set_size[root_2] += set_size[root_1];
    }
    else
    {
        disjoint_set[root_2] = disjoint_set[root_1];
        set_size[root_1] += set_size[root_2];
    }
}

// Linear time.
void set_union(vector<int> &disjoint_set, int element1, int element2)
{
    int root_1 = root(disjoint_set, element1);
    int root_2 = root(disjoint_set, element2);
    disjoint_set[root_1] = root_2;
}

bool find(vector<int> &disjoint_set, int element1, int element2)
{
    if (root(disjoint_set, element1) == root(disjoint_set, element2))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    // Set of size 20;
    int n = 20;
    // Disjoint set
    vector<int> disjoint_set(n);
    // Vector holding set size
    vector<int> set_size(n, 1);

    initialize(disjoint_set, n);

    weighted_union(disjoint_set, set_size, 2, 3);
    weighted_union(disjoint_set, set_size, 3, 5);
    weighted_union(disjoint_set, set_size, 6, 3);
    weighted_union(disjoint_set, set_size, 7, 10);

    cout << find(disjoint_set, 3, 2) << endl;
    cout << find(disjoint_set, 6, 3) << endl;
    cout << find(disjoint_set, 6, 2) << endl;
    cout << find(disjoint_set, 10, 7) << endl;
    cout << find(disjoint_set, 10, 6) << endl;
}