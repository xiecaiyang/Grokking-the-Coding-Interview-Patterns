/* Challenge 2, Hard
Problem Statement
We are given a list of Jobs. Each job has a Start time, an End time, and a CPU load when it is running.
Our goal is to find the maximum CPU load at any time if all the jobs are running on the same machine.
Example 1:
Jobs: [[1,4,3], [2,5,4], [7,9,6]]
Output: 7
Explanation: Since [1,4,3] and [2,5,4] overlap, their maximum CPU load (3+4=7) will be when both the
jobs are running at the same time i.e., during the time interval (2,4).
Example 2:
Jobs: [[6,7,10], [2,4,11], [8,12,15]]
Output: 15
Explanation: None of the jobs overlap, therefore we will take the maximum load of any job which is 15.
Example 3:
Jobs: [[1,4,2], [2,4,1], [3,6,5]]
Output: 8
Explanation: Maximum CPU load will be 8 as all jobs overlap during the time interval [3,4].
*/

#include <vector>
#include <queue>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "pattern04_merge_intervals.hpp"

using namespace std;

class CPUTask {
private:

public:
	int start;
	int end;
	int load;

	CPUTask() {};
	CPUTask(int a, int b, int c) : start(a), end(b), load(c) {};

	bool operator<(CPUTask other) {
		return this->end > other.end;
	}

};

/* ------two customized priority_queue sort------- */
// Method ¢Ù
struct cmp {
	bool operator()(CPUTask a, CPUTask b) {
		return a.end > b.end;
	}
};
// Method ¢Ú
//bool operator<(CPUTask a, CPUTask b) {
//	return a.end > b.end;
//}

bool compare_CPUTask(CPUTask a, CPUTask b) {
	if (a.start < b.start)
		return true;
	else if (a.start == b.start) {
		return a.end < b.end;
	}
	else
		return false;
}

static int solver(vector<CPUTask> jobs) {
	sort(jobs.begin(), jobs.end(), compare_CPUTask);
	priority_queue<CPUTask,vector<CPUTask>, cmp> myq;
	//vector<CPUTask> workingCPU;
	int max_load = 0;
	int cur_load = 0;
	for (int i = 0; i < jobs.size(); ++i) {
		while (!myq.empty() && myq.top().end <= jobs[i].start) {
			cur_load -= myq.top().load;
			myq.pop();
			//pop_heap(workingCPU.begin(), workingCPU.end());
			//workingCPU.pop_back();			
		}
		myq.push(jobs[i]);
		//workingCPU.push_back(jobs[i]);
		//push_heap(workingCPU.begin(), workingCPU.end());
		cur_load += jobs[i].load;

		max_load = max(max_load, cur_load);
	}


	return max_load;
}

void maximum_cpu_load() {
	vector<CPUTask> input{ { 1,4,2 },{ 2,3,1 },{ 3,6,5 } };

	int ans = solver(input);

	cout << ans << endl;
	system("pause");

}