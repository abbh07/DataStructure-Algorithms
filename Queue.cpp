#include <iostream>
#define max 10


using namespace std;

class queue
{
    private:
        int Front,rear;
        int arr[max];
    public:
        queue()
        {Front=rear=-1;}
        void enqueue(int);
        int dequeue();
        void display();
};

void queue::enqueue(int item)
{
    if(rear==max-1)
        cout<<"Queue Full!"<<endl;
    else
    {
        rear++;
        arr[rear]=item;
        if(Front==-1)
            Front=0;

    }
}
int queue::dequeue()
{
    int data;
    if(Front==-1)
        return -2;
    else
    {
        data=arr[Front];
        arr[Front]=0;
        if(rear==Front)
            Front=rear=-1;
        else
            Front++;

        return data;
    }


}

void queue::display()
{
    if(Front==-1)
    cout<<"Queue Empty!"<<endl;
    else
    {
        for(int i=Front;i<=rear;i++)
            cout<<arr[i]<<endl;
    }

}
int main()
{

    queue q1;
    int item,choice;

    while(choice!=4)
    {
        cout<<"Enter your choice"<<endl;
        cout<<"1. Enqueue"<<endl<<"2. Dequeue"<<endl<<"3. Display"<<endl<<"4. Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:cout<<"Enter the element to be enqueued"<<endl;
                    cin>>item;
                    q1.enqueue(item);

                    break;
            case 2: item=q1.dequeue();
                    if(item==-2)
                        cout<<"Queue Empty!"<<endl;
                    else
                    {
                        cout<<"Element dequeued is"<<endl;
                        cout<<item<<endl;
                    }

                    break;
            case 3:cout<<"The elements of the queue are:"<<endl;
                    q1.display();
                    break;
            case 4:choice=4;
                    break;
            default:cout<<"Invalid choice"<<endl;
        }
    }

    return 0;
}
