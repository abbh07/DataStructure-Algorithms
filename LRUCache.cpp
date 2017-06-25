//http://practice.geeksforgeeks.org/problems/lru-cache/1

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

class LRUCache
{
public:
    LRUCache(int );
 
    int get(int );
 
    void set(int , int );
};

struct node
{
    node* next;
    node* prev;
    int key;
    int value;
};

unordered_map<int,node*> m;
int cap;
node *head = NULL;
node *last = NULL;

void remove(node* n)
{
    if(n->prev != NULL)
    {
        
        n->prev->next = n->next;
    }
    else
    {
        head = n->next;
    }
    
    if(n->next != NULL)
    {
        
        n->next->prev = n->prev;
    }
    else
    {
        last = n->prev;
    }
}

void setHead(node* n)
{
    n->next = head;
    n->prev = NULL;
    if(head != NULL)
    {
        head->prev = n;
    }
    head = n;
    if(last == NULL)
    {
        last = head;
    }
}


/*Inititalize an LRU cache with size N */
LRUCache::LRUCache(int N)
{
    ::cap = N;
    head = NULL;
    last = NULL;
    m.clear();
}

/*Sets the key x with value y in the LRU cache */
void LRUCache::set(int x, int y) 
{
    if(m.count(x)==1)
    {
        node *temp = m[x];
        temp->value = y;
        remove(temp);
        setHead(temp);
    }
    else
    {
        node* n = new node();
        n->key = x;
        n->value = y;
        n->next = n->prev = NULL;
        if(m.size()>=cap)
        {
            m.erase(last->key);
            remove(last);
            setHead(n);
        }
        else
        {
            setHead(n);
        }
        m[x] = n;
    }
}

/*Returns the value of the key x if 
present else returns -1 */
int LRUCache::get(int x)
{
    if(m.count(x) == 1)
    {
        node *n = m[x];
        remove(n);
        setHead(n);
        return n->value;
    }
    else
    {
        return -1;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    LRUCache *l  = new LRUCache(n);
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        string a;
        cin>>a;
        if(a=="SET")
        {
            int aa,bb;
            cin>>aa>>bb;
            l->set(aa,bb);
        }else if(a=="GET")
        {
            int aa;
            cin>>aa;
            cout<<l->get(aa)<<" ";
        }
    }
    cout<<endl;
    }
}

