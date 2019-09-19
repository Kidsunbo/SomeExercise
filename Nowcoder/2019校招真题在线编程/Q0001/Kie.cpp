#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;


/*

In this question, I can't guarantee that the more difficult the job is, the more salary will be paid.
So I have to store the maximum value before to finish this task and reduce the time complexity.

*/
int main() {
	int jobNum = 0;
	int guyNum = 0;
	cin >> jobNum >> guyNum;
	vector<pair<int, int>> jobs(jobNum);
	for (int i = 0; i < jobNum; i++) {
		cin >> jobs[i].first >> jobs[i].second; // first is difficulty and the second is salary
	}
	vector<int> guys(guyNum);
	vector<pair<int, int>> guys_temp(guyNum);
	for (int i = 0; i < guyNum; i++) {
		cin >> guys_temp[i].first;
		guys_temp[i].second = i;
	}
	sort(jobs.begin(), jobs.end(), [](auto a, auto b) {return a.first < b.first; });
	sort(guys_temp.begin(), guys_temp.end(), [](auto a, auto b) {return a.first < b.first; });

	int job_index = 0;
	int last_salary = 0;
	for (auto& guy:guys_temp) {
		while (true) {
			if (job_index >= jobNum||jobs[job_index].first > guy.first) {
				guys[guy.second] = last_salary;
				break;
			}
			last_salary = max(last_salary, jobs[job_index].second);
			job_index++;
		}
	}
	for (auto& i : guys) {
		cout << i << endl;
	}
	return 0;
}