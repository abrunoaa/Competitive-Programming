#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main() {
	
	freopen("Ain.txt","r", stdin);
    freopen("Aout.txt","w", stdout);
	
	string s;
	int count;
	
	while (cin >> s >> count) {
		
		vector<long long> vet[count];
		
		int idx1 = s.find_last_of("[");
		int idx2 = s.find_first_of("]");

		long valor = atol( s.substr(idx1 + 1, idx2 - idx1 - 1).c_str() );
		for (int i = 0; i < count; ++i) 
			vet[i].push_back(valor);
		
		char sinal;
		int c;
		
		while (true) {
		
			s = s.substr(0, idx1);
			if (s.size() == 0) break;
			sinal = s[s.size() - 1];
			idx1 = s.find_last_of("[");
			idx2 = s.size() - 2;
			valor = atol( s.substr(idx1 + 1, idx2 - idx1).c_str() );
		
			for (int i = 0; i < count; ++i) {
				if (sinal == '+') {
					if (i == 0)
						vet[i].push_back(valor);
					else 
						vet[i].push_back( vet[ i - 1 ][ vet[i - 1].size() - 1 ] + vet[ i - 1 ][ vet[i - 1].size() - 2 ]);
				} else {
					if (i == 0)
						vet[i].push_back(valor * vet[ i ][ vet[i].size() - 1 ]);
					else 
						vet[i].push_back( vet[ i - 1 ][ vet[i - 1].size() - 1 ] * vet[ i ][ vet[i].size() - 1 ]);
				}
			}
		}
		
		c = vet[0].size() - 1;
		for (int i = 0; i < count; ++i) {
			if (i) printf(" ");
			cout << vet[i][c];
		}
		printf("\n");
		
	}
	
	return 0;
}
