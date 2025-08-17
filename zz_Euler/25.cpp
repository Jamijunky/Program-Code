#include <iostream>
using namespace std;

string addS(const string& a, const string& b) {
    string r; int i=a.size()-1, j=b.size()-1, c=0;
    while (i>=0 || j>=0 || c) {
        int s=c;
        if (i>=0) s+=a[i--]-'0';
        if (j>=0) s+=b[j--]-'0';
        r.push_back(char('0'+(s%10)));
        c=s/10;
    }
    reverse(r.begin(), r.end());
    return r;
}

int main() {
    string f1="1", f2="1";
    int idx=2;
    while ((int)f2.size() < 1000) {
        string f3=addS(f1,f2);
        f1=f2; f2=f3; ++idx;
    }
    cout << idx << '\n';
    return 0;
}
