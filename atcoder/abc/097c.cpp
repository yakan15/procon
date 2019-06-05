#include <bits/stdc++.h>

using namespace std;

int main(void){
    string s;
    int k;
    cin >> s >> k;
    char x;
    char filter='a';
    vector<int> lst;
    set<string> st;
    while(true){
        x='z';
        for(int i=0;i<s.size();i++){
            if(s.at(i)<x&&filter<=s.at(i)){x=s.at(i);}
            // cout << s.at(i) << endl;
        }
        // cout << "x: " << x << endl;
        // cout << x << endl;
        for(int i=0;i<s.size();i++){
            if(s.at(i)==x){lst.push_back(i);}
        }
        // for(int i=0;i<lst.size();i++){
        //     cout << lst.at(i) << endl;
        // }
        for(int j=0;j<lst.size();j++){
            for(int i=1;i<=s.size()&&lst.at(j)+i-1<s.size()&&i<=k;i++){
                // cout << j << endl;
                string sbstr = s.substr(lst.at(j),i);
                if(st.find(sbstr)==st.end()){
                    // cout << sbstr << endl;
                    st.insert(sbstr);
                }
            }
        }
        // cout << st.size() << endl;
        if(st.size()>=k){break;}
        // cout << filter << endl;
        filter=char(max(int(filter),int(x))+1);
        lst.clear();
        if(filter>'z'){break;}
    }
    vector<string> vs(st.begin(), st.end());
    sort(vs.begin(),vs.end());
    // for(int i=0;i<vs.size();i++){
    cout << vs.at(k-1) << endl;
    // }
}
