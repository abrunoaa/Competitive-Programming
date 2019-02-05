#include <algorithm>
#include <iostream>
#include <utility>
#include <numeric>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <climits>
#include <utility>

using namespace std;


int main() {

    freopen("../input.txt","r", stdin);
    freopen("../out.txt","w", stdout);

    int cases = 1;
    int n;
    string mens, baseCripto, baseApres;

    cin >> n;

    while ( n-- ) {

        cin >> mens >> baseCripto >> baseApres;

        int base1 = baseCripto.size();
        unsigned long long valor = 0;
        for (int i = 0; i < int(mens.size()); ++i)
            valor += baseCripto.find( mens[ mens.size() - 1 - i ] ) * pow(base1, i);

        string newValue;
        int base2 = baseApres.size();
        while (true) {
            newValue = char((valor % base2) + 48) + newValue;
            valor /= base2;
            if (int(valor) < base2) {
                if (valor != 0)
                    newValue = char((valor % base2) + 48) + newValue;
                break;
            }
        }

        printf("Caso #%d: ", cases++);
        for (int i = 0; i < int(newValue.size()); ++i) {
            printf("%c", baseApres[ newValue[i] - 48 ] );
        }
        printf("\n");
    }

    return 0;
}
