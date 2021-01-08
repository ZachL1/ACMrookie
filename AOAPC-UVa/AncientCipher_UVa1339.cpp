//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cstring>
//#include <string>
//#include <map>
//#include <set>
//#define _for(i,a,b) for( int i=(a); i<(b); ++i)
//#define _rep(i,a,b) for( int i=(a); i<=(b); ++i)
//typedef long long LL;
//using namespace std;
//
//int aa[300];
//int bb[300];
//
//int main() {
//	freopen("input.txt","r", stdin);
//	freopen("output.txt", "w", stdout);
//
//
//	set<char> a;
//	set<char> b;
//	char temp;
//	while (scanf("%c", &temp)!=EOF) {
//		a.clear(); b.clear();
//		a.insert(temp);
//		while (scanf("%c", &temp) && temp != '\n') {
//			a.insert(temp);
//		}
//		while (scanf("%c", &temp) && temp != '\n') {
//			b.insert(temp);
//		}
//
//		if (a.size() != b.size()) {
//			cout << "NO" << endl;
//			continue;
//		}
//
//		auto ita = a.begin(), itb = b.begin();
//		int c = *ita - *itb;
//		while (ita != a.end()) {
//			if (*ita - *itb != c) {
//				cout << "NO";
//				break;
//			}
//			++ita;
//			++itb;
//		}
//		if (ita == a.end()) cout << "YES";
//		cout << endl;
//	}
//
//
//	/*string a, b;
//	while (getline(cin, a)) {
//		getline(cin, b);
//		memset(aa, 0, sizeof(aa));
//		memset(bb, 0, sizeof(bb));
//		int la = 0, lb = 0;
//
//		for (auto i : a) {
//			if (aa[i] == 0) {
//				la++;
//				aa[i] = 1;
//			}
//		}
//		for (auto i : b) {
//			if (bb[i] == 0) {
//				lb++;
//				bb[i] = 1;
//			}
//		}
//		if (la == lb) {
//			cout << "YES";
//		}
//		else
//			cout << "NO";
//		cout << endl;*/
//
//
//
//		//if (a.length() != b.length()) {
//		//	cout << "NO" << endl;
//		//	continue;
//		//}
//
//		//int i;
//		//for (i = 'A'; i <= 'Z'; i++) {
//		//	memset(bb, 0, sizeof(bb));
//		//	int co = a[0] - i;
//		//	int j;
//		//	for (j = 0; j < a.length(); j++) {
//		//		bool is = false;
//		//		_for(k, 0, b.length()) {
//		//			if (bb[k] == 0 && a[j]-co == b[k]) {
//		//				bb[k] = 1;
//		//				is = true;
//		//				break;
//		//			}
//		//		}
//		//		if (!is) {// 如果有一个没法映射，此次不可行
//		//			break;
//		//		}
//		//	}
//		//	if (j == a.length()) {
//		//		cout << "YES" << endl;
//		//		break;
//		//	}
//		//}
//		//if (i > 'Z')
//		//	cout << "NO" << endl;
//	//}
//	return 0;
//}