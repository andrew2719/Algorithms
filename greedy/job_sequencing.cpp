// C++ code for the above approach

#include <algorithm>
#include <iostream>
using namespace std;

// A structure to represent a job
struct Job {

	char id; // Job Id
	int dead; // Deadline of job
	int profit; // Profit if job is over before or on deadline
	int slot=0;		
};

// Comparator function for sorting jobs
bool comparison(Job a, Job b)
{
	return (a.profit > b.profit);
}

// Returns maximum profit from jobs
void printJobScheduling(Job arr[], int n)
{
	// Sort all jobs according to decreasing order of profit
	sort(arr, arr + n, comparison);

    int result[n]; // To store result (Sequence of jobs)
    int slot[n];  // To keep track of free time slots

    // Initialize all slots to be free
    for (int i = 0; i < n; i++)
        slot[i] = 0;

    // Iterate through all given jobs
    for(int i=0;i<n;i++){
        for(int j=min(n,arr[i].dead)-1;j>=0;j--){

            if(!slot[j]){
                slot[j] = i+1;
                result[j] = i;
                arr[i].slot = j+1;
                break;
            }
        }
    }


    cout<<"INDEX\tPROFIT\tDEADLINE\tSLOT ALLOTTED\n";
    for(int i=0;i<n;i++){
        cout<<arr[i].id<<"\t"<<arr[i].profit<<"\t"<<arr[i].dead<<"\t";
        if(arr[i].slot)
            cout<<"["<<arr[i].slot-1<<"-"<<arr[i].slot<<"]\n";
        else
            cout<<"REJECTED\n";
    }
 
}

// Driver's code
int main()
{
	Job arr[] = { { 'a', 2, 100 },
				{ 'b', 1, 19 },
				{ 'c', 2, 27 },
				{ 'd', 1, 25 },
				{ 'e', 3, 15 } };

	int n = sizeof(arr) / sizeof(arr[0]);

	printJobScheduling(arr, n);
	return 0;
}

