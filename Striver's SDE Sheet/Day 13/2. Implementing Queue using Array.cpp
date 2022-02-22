/* 

The structure of the class is
class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};
 */

//Function to push an element x in a queue.
void MyQueue :: push(int x)
{
    // if(count==n)
    // {
    //     return;
    // }
    arr[rear]=x;
    rear++;
    // count++;
}

//Function to pop an element from queue and return that element.
int MyQueue :: pop()
{
//     if(count==-1)
//     {
//         return -1;
//     }

    if(front==rear)
    {
        return -1;
    }
    int temp=front;
    front++;
    return arr[temp];
}





// using oops 
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
class Queue
{
	int *arr;
	int qfront;
	int qrear;
	int currsize;
	int maxsize;
public:
	// Constructor
	Queue()
	{
		arr = new int[16];
		qfront = -1;
		qrear = -1;
		currsize = 0;
	}

	Queue(int maxSize) {
		( * this).maxsize = maxsize;
		arr = new int[maxSize];
		qfront = -1;
		qrear = -1;
		currsize = 0;
	}

	void push(int ele)
	{
		if (currsize == maxsize)
		{
			cout << "Queue Full" << endl;
			exit(1);
		}
		if (qrear == -1)
		{
			qfront = 0;
			qrear = 0;
		}
		else
		{
			qrear = (qrear + 1) % maxsize;
		}

		arr[qrear] = ele;
		cout << " New Element is  " << " " << ele << endl;
		currsize++;
	}

	int pop()
	{
		if (qfront == -1)
		{
			cout << "Queue is empty no Element present" << endl;
		}
		int temp = arr[qfront];
		if (currsize == 1)
		{
			qfront = -1;
			qrear = -1;
		}
		else
		{
			qfront = (qfront + 1) % maxsize;
		}
		currsize--;
		return temp;
	}

	int Top()
	{
		if (qfront == -1)
		{
			cout << "Queue is empty" << endl;
		}
		return arr[qfront];
	}

	int size()
	{
		return currsize;
	}
};

int main() {
	Queue q(6);
	q.push(4);
	q.push(14);
	q.push(24);
	q.push(34);
	cout << "The peek of the queue before deleting any element " << q.Top() << endl;
	cout << "The size of the queue before deletion " << q.size() << endl;
	cout << "The first element to be deleted " << q.pop() << endl;
	cout << "The peek of the queue after deleting an element " << q.Top() << endl;
	cout << "The size of the queue after deleting an element " << q.size() << endl;

	return 0;
}
