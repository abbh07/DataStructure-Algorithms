//Recursive implementation of 'Tower of Hanoi'
//Tower of hanoi puzzle with n disks can be solved in minimum 2n−1 steps.
#include <iostream>

using namespace std;

//Assuming n-th disk is the bottommost disk
void toh(int n, char sourceTower, char auxiliaryTower, char destinationTower)
{
	//Base Case
	if(n == 1)
	{
		cout<<"Move disk 1 from "<<sourceTower<<" to "<<destinationTower<<endl;
		return;
	}
	else
	{
		toh(n-1,sourceTower,destinationTower,auxiliaryTower);
		cout<<"Move disk "<<n<<" from "<<sourceTower<<" to "<<destinationTower<<endl;
		toh(n-1,auxiliaryTower,sourceTower,destinationTower);
	}
}

int main()
{
	cout<<"Enter the number of disks:"<<endl;
	int n;
	cin>>n;
	cout<<endl;
	cout<<"A: Source Tower"<<endl;
	cout<<"B: Auxiliary Tower"<<endl;
	cout<<"C: Destination Tower"<<endl;
	cout<<endl;
	toh(n,'A','B','C');
	return 0;
} 