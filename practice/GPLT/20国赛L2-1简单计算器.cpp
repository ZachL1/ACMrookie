#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

int main(){
    int n;cin>>n;
    stack<int> s1;
    stack<char> s2;
    
    int temp;
    for(int i=0; i<n; ++i){
        scanf("%d", &temp);
        s1.push(temp);
    }
    for(int i=1; i<n; ++i){
        getchar();
        scanf("%c", &temp);
        s2.push(temp);
    }
    
    int n1,n2,op;
    while(s1.size()>1 && !s2.empty()){
        n1=s1.top();s1.pop();
        n2=s1.top();s1.pop();
        op=s2.top();s2.pop();
        if(op=='/' && n1==0){
            printf("ERROR: %d/0\n", n2);
            return 0;
        }
        
        switch(op){
            case '+': temp=n2+n1;break;
            case '-': temp=n2-n1;break;
            case '*': temp=n2*n1;break;
            case '/': temp=n2/n1;break;
        }
        s1.push(temp);
    }
    cout << s1.top() << endl;
    return 0;
}