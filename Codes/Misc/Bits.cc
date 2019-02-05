#define npop(n) __builtin_popcountll(n) // nº de bits 1
#define ntz(n) __builtin_ctzll(n)       // nº de zeros à direita
#define nlz(n) __builtin_clz(n)         // nº de zeros à esquerda add 'll' para long long

x & (x - 1)   // desativa o bit 1 mais a direita; se ans = 0, x = 0 ou x = 2^k

x | (x + 1)   // ativa o bit 0 mais a direita

x & (x + 1)   // desativa a sequencia de 1's mais a direita (101011 -> 101000)
              // se ans = 0, x = 2^n - 1 ou x = 0 ou x = -1 (todos os bits setados)

x | (x - 1)   // ativa a sequencia de 0's mais a direita (101000 -> 101111)

~x & (x + 1)  // um único bit 1 no 0 mais a direita (10101 -> 00010)

~x | (x - 1)  // um único bit 0 no 1 mais a direita (10101 -> 11110)

x & -x        // isola o bit 1 mais a direita

1 << (31 - nlz(x))  // isola o bit 1 mais a esquerda

// desativa a sequencia de bits 1 mais a direita (010111000 -> 010000000)
((x | (x - 1)) + 1) & x   // se ans = 0, x = 2^j - 2^k, j >= k >= 0
((x & -x) + x) & x        // outra fórmula

// retorna o xor de todos os números de 0 a n
int nxor(int n){
  int ans[] = {n, 1, n+1, 0};
  return ans[n % 4];
}

// conta qtd de bits 1 na posição i (direita para esquerda) de 0 a n
int nbits(int n, int i){
  int x = ((n >> i) << i) & ~(1 << i);            // maior múltiplo de 2^i com bit 0 em i
  return x / 2 + max(0, n - x + 1 - (1 << i));    // qtde até x + diff de x até n
}
