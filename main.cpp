#include <iostream>
#include <cstdlib>

using namespace std;

class Nodo
{
public:
    Nodo(int informacion = 0,
         Nodo *izq = NULL,
         Nodo *der = NULL)
    {
        mInformacion = informacion;
        mIzq = izq;
        mDer = der;
    }

    int mInformacion;
    Nodo *mIzq;
    Nodo *mDer;
};

void inserta(Nodo *nodo, int informacion)
{
    if (informacion < nodo->mInformacion) {
        if (nodo->mIzq == NULL) {
            Nodo *otro = new Nodo(informacion);
            nodo->mIzq = (otro);
        } else {
            inserta(nodo->mIzq, informacion);
        }
    } else {
        if (informacion > nodo->mInformacion) {
            if (nodo->mDer == NULL) {
                Nodo *otro = new Nodo(informacion);
                nodo->mDer = (otro);
            } else {
                inserta(nodo->mDer, informacion);
            }
        } else {
            cout << "el nodo ya se encuentra en el arbol" << endl;
        }
    }
}

void elimina(Nodo **nodo, int informacion)
{
    if (*nodo != NULL) {
        if (informacion < (**nodo).mInformacion) {
            elimina(&(**nodo).mIzq, informacion);
        } else {
            if (informacion > (**nodo).mInformacion) {
                elimina(&(**nodo).mDer, informacion);
            } else {
                Nodo *otro = *nodo;
                if (otro->mDer == NULL) {
                    *nodo = otro->mIzq;
                } else {
                    if (otro->mIzq == NULL) {
                        *nodo = otro->mDer;
                    } else {
                        Nodo *aux = otro->mIzq;
                        Nodo *aux1 = aux;
                        while (aux->mDer != NULL) {
                            aux1 = aux;
                            aux = aux->mDer;
                        }
                        otro->mInformacion = (aux->mInformacion);
                        otro = aux;
                        aux->mDer = (aux->mIzq);
                    }
                }
            }
        }
    } else {
        cout << "el nodo no se encuentra en el arbol" << endl;
    }
}

void preorden(Nodo *nodo)
{
    if (nodo != NULL) {
        cout << nodo->mInformacion << endl;
        preorden(nodo->mIzq);
        preorden(nodo->mDer);
    }
}

void inorden(Nodo *nodo)
{
    if (nodo != NULL) {
        inorden(nodo->mIzq);
        cout << nodo->mInformacion << endl;
        inorden(nodo->mDer);
    }
}

void postorden(Nodo *nodo)
{
    if (nodo != NULL) {
        postorden(nodo->mIzq);
        postorden(nodo->mDer);
        cout << nodo->mInformacion << endl;
    }
}

enum
{
    INSERTA = 1,
    ELIMINA,
    PREORDEN,
    INORDEN,
    POSTORDEN,
    SALIR
};

void imprimeMenu()
{
    cout << endl;
    cout << "1 inserta" << endl;
    cout << "2 elimina" << endl;
    cout << "3 preorden" << endl;
    cout << "4 inorden" << endl;
    cout << "5 postorden" << endl;
    cout << "6 salir" << endl;
}

int main()
{
    int informacion;
    int opcion;

    cout << "Inserta el valor de la raiz: ";
    cin >> informacion;
    Nodo *raiz = new Nodo(informacion);

    while (true) {
        imprimeMenu();
        cout << "Opcion? ";
        cin >> opcion;
        switch (opcion) {
        case INSERTA:
            cout << "informacion? ";
            cin >> informacion;
            inserta(raiz, informacion);
            break;
        case ELIMINA:
            cout << "informacion? ";
            cin >> informacion;
            elimina(&raiz, informacion);
            break;
        case PREORDEN:
            preorden(raiz);
            break;
        case INORDEN:
            inorden(raiz);
            break;
        case POSTORDEN:
            postorden(raiz);
            break;
        case SALIR:
            return 0;
        }
    }
    return 0;
}

