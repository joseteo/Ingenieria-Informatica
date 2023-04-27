#include "algorithm.h"


void algorithm::ordenar_code(){
    sort(code, code + num_class, comparar);
}

void algorithm::create_class(){
    num_class = pow(2, num_elementos_init);
    clase = new set <Resultado> [num_class];
    code = new int [num_class];
    for (int i = 0; i < num_class; i++){
        code[i] = i;
    }
    ordenar_code();
}

algorithm::algorithm(const vector <int> & elementos_init, int objetivo){

    num_elementos_init  = elementos_init.size();

    create_class();

    for (int i = 1; i <= num_elementos_init; i++){
        Resultado elemental(elementos_init[i-1], code[i], NULL, NULL, -1);
        clase[code[i]].insert(elemental);
    }
    this->objetivo = objetivo;
}

algorithm::~algorithm(){
    delete [] clase;
    delete [] code;
    delete mejor_resultado;
}

void algorithm::resolver(){

    mejor_resultado = new Resultado(*(clase[code[1]].begin()));
    for (int i = 2; i <= num_elementos_init; i++){
        if ( abs(mejor_resultado->get_resultado() - objetivo) > abs(clase[code[i]].begin()->get_resultado() - objetivo) ){
            delete mejor_resultado;
            mejor_resultado = new Resultado(*(clase[code[i]].begin()));
        }
    }

    int subclass_usadas, numero_subclass, num_unos;
    bool *usados = new bool[num_class];

    for (int i = num_elementos_init + 1; i < num_class && mejor_resultado->get_resultado() != objetivo; i++){
        subclass_usadas = 0;
        num_unos = numero_unos(code[i]);
        numero_subclass = pow(2,num_unos-1) - 1;
        for (int k = 1; k < i; k++)
            usados[code[k]] = false;

        for (int j = 1; subclass_usadas < numero_subclass && mejor_resultado->get_resultado() != objetivo; j++){
            if ( (code[j] & code[i]) == code[j] && usados[code[i] - code[j]] == false){
                subclass_usadas++;
                usados[code[j]] = usados[code[i] - code[j]] = true;
                generar_resultados(code[i], code[j]);
            }
        }
    }
    delete [] usados;
}

void algorithm::generar_resultados(int i, int j){

    int k = i - j;
    Resultado *elemento;
    set <Resultado>::iterator m;
    set <Resultado>::iterator n;

    for (m = clase[j].begin(); m != clase[j].end(); m++){
        for (n = clase[k].begin(); n != clase[k].end(); n++){
            elemento = new Resultado(m->get_resultado() + n->get_resultado(), i, &(*m), &(*n), 1);
            clase[i].insert(*elemento);
            if (abs(elemento->get_resultado() - objetivo) < abs(mejor_resultado->get_resultado() - objetivo)){
                delete mejor_resultado;
                mejor_resultado = elemento;
            }else{
                delete elemento;
            }

            if (n->get_resultado() > 1 && m->get_resultado() > 1){
                elemento = new Resultado(m->get_resultado() * n->get_resultado(), i, &(*m), &(*n), 2);
                clase[i].insert(*elemento);

                if (abs(elemento->get_resultado() - objetivo) < abs(mejor_resultado->get_resultado() -objetivo)){
                    delete mejor_resultado;
                    mejor_resultado = elemento;
                }else{
                    delete elemento;
                }
            }

            if (m->get_resultado() - n->get_resultado() > 0){
                elemento = new Resultado(m->get_resultado() - n->get_resultado(), i, &(*m), &(*n), 3);
                clase[i].insert(*elemento);
                if (abs(elemento->get_resultado() - objetivo) < abs(mejor_resultado->get_resultado() -objetivo)){
                    delete mejor_resultado;
                    mejor_resultado = elemento;
                }else{
                    delete elemento;
                }
            }else if (m->get_resultado() - n->get_resultado() < 0){
                elemento = new Resultado(n->get_resultado() - m->get_resultado(), i, &(*n), &(*m), 3);
                clase[i].insert(*elemento);
                if (abs(elemento->get_resultado() - objetivo) < abs(mejor_resultado->get_resultado() - objetivo)){
                    delete mejor_resultado;
                    mejor_resultado = elemento;
                }else{
                    delete elemento;
                }
            }

            if (n->get_resultado() > 1 && m->get_resultado() > 1){
                if (m->get_resultado() % n->get_resultado() == 0){
                    elemento = new Resultado(m->get_resultado() / n->get_resultado(), i, &(*m), &(*n), 4);
                    clase[i].insert(*elemento);
                    if (abs(elemento->get_resultado() - objetivo) < abs(mejor_resultado->get_resultado() - objetivo)){
                        delete mejor_resultado;
                        mejor_resultado = elemento;
                    }else{
                        delete elemento;
                    }
                }else if (n->get_resultado() % m->get_resultado() == 0){
                    elemento = new Resultado(n->get_resultado() / m->get_resultado(), i, &(*n), &(*m), 4);
                    clase[i].insert(*elemento);
                    if (abs(elemento->get_resultado() - objetivo) < abs(mejor_resultado->get_resultado() -objetivo)){
                        delete mejor_resultado;
                        mejor_resultado = elemento;
                    }else{
                        delete elemento;
                    }
                }
            }

        }
    }
}

void algorithm::mostrar_resultado(){

    if (mejor_resultado->get_resultado() == objetivo){
        cout << "El valor requerido se ha alcanzado" << endl;
    }else{
        cout << "No se ha logrado alcanzar el valor objetivo. El valor más cercano al objetivo obtenido es= " << mejor_resultado->get_resultado() << endl;
    }
    cout << "Calculos realizados= " << endl;
    mejor_resultado->mostrar_camino();
}

bool comparar(int j,int t){
    return (numero_unos(j) < numero_unos(t));
}

int numero_unos(int n){
    int potencia2 = 1;
    int num_unos = 0;

    while(potencia2 <= n){
        if ( (n & potencia2) == potencia2){
            num_unos++;
        }
        potencia2 *= 2;
    }
    return num_unos;
}
