#include <iostream>
#include <random>
#include <ctime>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
 
using namespace std;

#define NUM_JOBS 10

struct FCFS {

	int arrival, service, terminating, turnAround;

};

int main()

{

	srand(time(NULL));

	int rand2 = 0;

	const int n = NUM_JOBS;

	int temp;

	FCFS arr[n];

	int star[n], wt[n];

	int totwt = 0, tottat = 0;

	for (int i = 0; i < n; i++)

	{
		arr[i].service = rand() % 25 + 5;

		arr[i].arrival = rand2;
		
		rand2 += rand() % 10;

	}

	for (int i = 0; i < n; i++)

	{

		for (int j = 0; j < n; j++)

		{

			if (arr[i].arrival < arr[j].arrival)

			{

				temp = arr[i].arrival;

				arr[i].arrival = arr[j].arrival;

				arr[j].arrival = temp;

			}

		}

	}

	for (int i = 0; i < n; i++)

	{

		if (i == 0)

			star[i] = arr[i].arrival;

		else

			star[i] = arr[i - 1].terminating;

		wt[i] = star[i] - arr[i].arrival;

		arr[i].terminating = star[i] + arr[i].service;

		arr[i].turnAround = arr[i].terminating - arr[i].arrival;

	}

	cout << "Processes  " << " Arrival  " << " Service  " << " Waiting (idle)  " << " Starting  " << " Turn around time " << " Terminating  " << endl;

	for (int i = 0; i < n; i++)

	{

		cout << i + 1 << setw(14) << arr[i].arrival << setw(10)  << arr[i].service << setw(11) << wt[i] << setw(17) << star[i] << setw(11) << arr[i].turnAround << setw(18) << arr[i].terminating << endl;

		totwt += wt[i];

		tottat += arr[i].turnAround;

	}

	cout << endl;

	cout << "Average Waiting time:" << (float)totwt / n << endl;

	cout << "Average Turn Around Time:" << (float)tottat / n << endl;

	return 0;

}

//Process 1
//Arrival : 0 Service : 27 Waiting(idle) : 0 Starting : 0 Turn Around Time : 27 Terminating : 27
//Process 2
//Arrival : 1 Service : 27 Waiting(idle) : 26 Starting : 27 Turn Around Time : 53 Terminating : 54
//Process 3
//Arrival : 2 Service : 17 Waiting(idle) : 52 Starting : 54 Turn Around Time : 69 Terminating : 71
//Process 4
//Arrival : 9 Service : 18 Waiting(idle) : 62 Starting : 71 Turn Around Time : 80 Terminating : 89
//Process 5
//Arrival : 12 Service : 20 Waiting(idle) : 77 Starting : 89 Turn Around Time : 97 Terminating : 109
//Process 6
//Arrival : 18 Service : 10 Waiting(idle) : 91 Starting : 109 Turn Around Time : 101 Terminating : 119
//Process 7
//Arrival : 19 Service : 8 Waiting(idle) : 100 Starting : 119 Turn Around Time : 108 Terminating : 127
//Process 8
//Arrival : 21 Service : 12 Waiting(idle) : 106 Starting : 127 Turn Around Time : 118 Terminating : 139
//Process 9
//Arrival : 30 Service : 8 Waiting(idle) : 109 Starting : 139 Turn Around Time : 117 Terminating : 147
//Process 10
//Arrival : 32 Service : 23 Waiting(idle) : 115 Starting : 147 Turn Around Time : 138 Terminating : 170
//
//Average Waiting time : 73.8
//Average Turn Around Time : 90.8

//
//Processes   Arrival   Service   Waiting(idle)   Starting   Turn around time  Terminating
//1             0        15          0                0         15                15
//2             6         5          9               15         14                20
//3             7        18         13               20         31                38
//4            13        17         25               38         42                55
//5            20        29         35               55         64                84
//6            24        25         60               84         85               109
//7            33        12         76              109         88               121
//8            39        16         82              121         98               137
//9            43        24         94              137        118               161
//10            46         5        115              161        120               166
//
//
//Average Waiting time : 50.9
//Average Turn Around Time : 67.5
