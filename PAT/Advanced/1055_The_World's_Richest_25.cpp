//
//  1055_The_World's_Richest_25.cpp
//  workspace
//
//  Created by Zach Duan on 2022/5/8 14:17 AM.
//  GitHub: https://github.com/zachL1
//  Copyright © 2022 CSUFT. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct people {
	string name;
	int age, worth;
};
istream& operator>> (istream& is, people& p) {
	return is >> p.name >> p.age >> p.worth;
}
ostream& operator<< (ostream& os, people& p) {
	return os << p.name << " " << p.age << " " << p.worth;
}

bool cmp(people& l, people& r) {
	if (l.worth != r.worth) return l.worth > r.worth;
	else if (l.age != r.age) return l.age < r.age;
	else return l.name < r.name;
}

int main() {
	int N, K;
	cin >> N >> K;

	vector<people> peoples;
	people temp;
	while (N--) {
		cin >> temp;
		peoples.push_back(temp);
	}
	sort(peoples.begin(), peoples.end(), cmp);

	for (int i = 1; i <= K; ++i) {
		bool non = true;
		int amin, amax, M;
		cin >> M >> amin >> amax;

		printf("Case #%d:\n", i);
		for (people& p : peoples) {
			if (amin <= p.age && p.age <= amax) {
				if (M-- == 0) break;
				non = false;
				cout << p << endl;
			}
		}
		if (non) cout << "None\n";
	}
	return 0;
}