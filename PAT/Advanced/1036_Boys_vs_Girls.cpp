#include <set>
#include <iostream>
#include <string>

using namespace std;

struct people{
    string name, ID;
    char gender;
    int grade;

    bool empty() const{
        return name.empty();
    }
    bool operator< (people& p) const{
        return this->grade < p.grade;
    }
};

istream& operator>>(istream& is, people& p){
    return is >> p.name >> p.gender >> p.ID >> p.grade;
}
ostream& operator<<(ostream& os, const people& p){
    if (p.empty()) return os << "Absent";
    return os << p.name << " " << p.ID;
}

int main()
{
    people female, male, temp;
    male.grade = 101;
    female.grade = -1;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> temp;
        if (temp.gender == 'M' && temp < male){
            male = temp;
        }
        if (temp.gender == 'F' && female < temp){
            female = temp;
        }
    }

    cout << female << endl;
    cout << male << endl;
    cout << ((female.empty() || male.empty()) ? "NA" : to_string(female.grade-male.grade)) << endl;

    return 0;
}