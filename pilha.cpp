#include <iostream>
using std::cin;
using std::cout;

struct noh{
    int value;
    noh* topo;
};

int main(){
    int value, op;
    bool primeiraVez = true;
    noh *p, *topo = NULL, *aux;
    do{ 
        cout << "\nMENU";
        cout << "\n------------------------";
        cout << "\n1 - Push";
        cout << "\n2 - Pop";
        cout << "\n3 - Listar";
        cout << "\n4 - sair\n: ";
        cin >> op;
        cout << "\e[H\e[2J";
        switch(op){
            case 1: p = (struct noh*) malloc(sizeof(struct noh));
                    cout << "\nDigite um valor: ";
                    cin >> value;
                    p->topo = topo; //o de agora aponta para o anterior
                    p->value = value;
                    topo = p;
                break;
            case 2: if(topo != NULL){
                        topo = topo->topo; //o topo de agora vira o noh anterior
                    } else cout << "\nPilha vazia!";
                break;
            case 3: aux = topo;
                    if(aux != NULL){
                        cout << "\nPILHA: ";
                        while(aux != NULL){
                            cout << "\n" << aux->value;
                            aux = aux->topo;    
                        }
                    }else cout << "\nPilha vazia!";
                break;
            case 4: cout << "\nSaindo...";
                break;
            default: cout << "\nErro ao digitar";
        }
    }while(op != 4);
}

