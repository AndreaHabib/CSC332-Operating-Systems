#include <iostream>
#include <random>
#include <ctime>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

#define NUM_JOBS 10

struct RR {

	int arrival, service, terminating;

};

int main() {

	srand(time(NULL));

	int rand2 = 0;

	int time = 0;

	const int n = NUM_JOBS;

	RR arr[n];

	int tat = 0, wt = 0;

	int quantum;

	int star[n], rem_bt[n];

	cout << "Quantum: ";

	cin >> quantum;

	cout << endl;

	for (int i = 0; i < n; i++)

	{
		arr[i].service = rand() % 25 + 5;

		arr[i].arrival = rand2;

		rand2 += rand() % 10;

		rem_bt[i] = arr[i].service;

	}

	int i, context_switch = 0, remain;

	remain = n;

	for (time = 0, i = 0; remain != 0;) {

		if (rem_bt[i] <= quantum && rem_bt[i] > 0) {

			time += rem_bt[i];

			rem_bt[i] = 0;
			context_switch = 1;

		}

		else if (rem_bt[i] > 0) {

			rem_bt[i] -= quantum;

			time += quantum;

		}

		if (rem_bt[i] == 0 && context_switch == 1) {

			remain--;

			arr[i].terminating = time;

			printf("Process\t\t:\tArrival\t:\tService\t:\tTurn Around\t:\tWaiting\t:\tTerminating\n");
			printf("Process %d: \t\t%d\t\t%d\t\t%d\t\t\t%d\t\t%d\n", i + 1, arr[i].arrival, arr[i].service, time - arr[i].arrival, time - arr[i].arrival - arr[i].service, arr[i].terminating);
			cout << endl;

			wt += time - arr[i].arrival - arr[i].service;

			tat += time - arr[i].arrival;

			context_switch = 0;

		}

		if (i == n - 1)
			i = 0;
		else if (arr[i + 1].arrival <= time)
			i++;
		else
			i = 0;
	}

	

	cout << "Average Waiting time:" << (float)wt / n << endl;

	cout << "Average Turn Around Time:" << (float)tat / n << endl;

	

	return 0;

}

//Quantum: 1
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 1 : 0               12              39                      27              39
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 3 : 10              10              76                      66              86
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 7 : 25              14              113                     99              138
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 4 : 11              17              132                     115             143
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 2 : 6               20              143                     123             149
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 6 : 18              19              143                     124             161
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 5 : 11              23              162                     139             173
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 9 : 31              25              159                     134             190
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 10 : 33              25              158                     133             191
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 8 : 25              29              169                     140             194
//
//Average Waiting time : 110
//Average Turn Around Time : 129.4

//Quantum: 2
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 5 : 16              13              121                     108             137
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 2 : 2               24              167                     143             169
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 8 : 30              16              149                     133             179
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 10 : 46              15              136                     121             182
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 7 : 25              20              167                     147             192
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 9 : 38              18              156                     138             194
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 1 : 0               27              195                     168             195
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 6 : 16              23              190                     167             206
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 3 : 11              27              196                     169             207
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 4 : 15              27              195                     168             210
//
//Average Waiting time : 146.2
//Average Turn Around Time : 167.2

//Quantum: 5
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 2 : 2               10              58                      48              60
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 4 : 10              8               58                      50              68
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 5 : 12              15              101                     86              113
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 6 : 12              15              106                     91              118
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 7 : 21              14              101                     87              122
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 9 : 23              15              109                     94              132
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 10 : 29              12              105                     93              134
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 1 : 0               18              137                     119             137
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 3 : 6               18              134                     116             140
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 8 : 22              25              128                     103             150
//
//Average Waiting time : 88.7
//Average Turn Around Time : 103.7

//Quantum: 10
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 2 : 6               10              14                      4               20
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 3 : 7               15              108                     93              115
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 5 : 23              11              103                     92              126
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 9 : 42              19              123                     104             165
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 1 : 0               26              181                     155             181
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 4 : 16              21              166                     145             182
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 6 : 32              28              158                     130             190
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 7 : 34              23              159                     136             193
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 8 : 37              25              161                     136             198
//
//Process : Arrival : Service : Turn Around : Waiting:       Terminating
//Process 10 : 42              21              157                     136             199
//
//Average Waiting time : 113.1
//Average Turn Around Time : 133