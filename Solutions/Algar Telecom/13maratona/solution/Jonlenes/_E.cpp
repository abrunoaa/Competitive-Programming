//12:07
//12:09
//12:16
//12:22

#include <iostream>
using namespace std;


int main() {

    //freopen("../input.txt","r", stdin);
    //freopen("../out.txt","w", stdout);

    int n;

    cin >> n;

    while (n--) {

        int t1m = 0;
        int t1v = 0;
        int t2m = 0;
        int t2v = 0;

        scanf("%d x %d %d x %d ", &t1m, &t2v, &t2m, &t1v);

        if (t1m + t1v != t2m + t2v) {
            if (t1m + t1v > t2m + t2v) cout << "Time 1\n";
            else cout << "Time 2\n";
        } else {
            if (t1v > t2v) cout << "Time 1\n";
            else if (t1v < t2v) cout << "Time 2\n";
            else cout << "Penaltis\n";
        }
    }

    return 0;
}
