#include <iostream>

using namespace std;
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int k;
    int n;
    string s;
    cin >> n;
    cin >> k;
    cin >> s;
    printf("%s",s);
    s[k] = tolower(s[k]);
    cout << s << endl;
    return 0;

}