#include <iostream>
#define MAXTAM 500
using namespace std;
struct Pilha {
    char c[MAXTAM];
    int topo = 0;
};
void empilhar(Pilha &p, string array);
void removerElem(Pilha &p, char caractere);
void desempilhar(Pilha &p);
int main() {
    char caractere;
    Pilha p;
    string cadeia;
    cout << "entre com o array de caracteres a ser implantado na pilha" << endl;
    getline(cin, cadeia, '\n');
    empilhar(p, cadeia);
    cout << "entre com o caractere a ser removido da pilha" << endl;
    cin >> caractere;
    removerElem(p, caractere);
    return 0;
}
void empilhar(Pilha &p, string cadeia) {
    if(p.topo == MAXTAM) {
        cout << "Pilha cheia!" << endl;
    } else {
        for(int i = 0; i < cadeia.length(); i++) {
            p.c[p.topo] = cadeia.at(i);
            p.topo++;
        }
    }
}
void removerElem(Pilha &p, char caractere) {
    Pilha pAux;
    if(p.topo == 0) {
        cout << "Pilha vazia!" << endl;
        
    } else {
        while (p.topo != -1) {
            char cAux;
            cAux = p.c[p.topo];
            if (cAux == caractere) {
                cout << "encontrada evidência" << endl;
                // do anything
            } else {
                pAux.c[pAux.topo] = cAux;
                pAux.topo++;
            }
            p.topo--;
        }
    }
    desempilhar(pAux);
}
void desempilhar(Pilha &p) {
    cout << "mostrando pilha sem o elemento que foi removido" << endl;
    while(p.topo != 0) {
        cout << p.c[p.topo] << " ";
        p.topo--;
    }
}