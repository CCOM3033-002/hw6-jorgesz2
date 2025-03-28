/*
HW 6: Figuras en 3D
Nombre: Jorge Suris Zayas - jorgesz2
Núm. Est: 401-24-8161
Colaboraciones:
google donde esta Pi en cmath: "math constant pi in c++" -> M_PI
*/
/*
Este programa usa overloading funciones
    para calcular el volumen y area de superficia
    de un cilindro, esfera o prisma rectabgular
    (6 funciones totales)
*/

#include <iostream>
#include <cmath>

using namespace std;

int escogaFigura();
int escogaFormula();
void clearBuffer();


double getMeasure(std::string, std::string);
bool isValid(double);



// Funciones de volumen

//  Cilindro: radio, altura
double volumen(double, double);
// Esfera: radio
double volumen(double);
// Prisma rectangular: largo, ancho(radio), altura
double volumen(double, double, double);


// Funciones de area de superficia

// Cilindro:: radio, altura
double areaSuperficia(double);
// Esfera: radio
double areaSuperficia(double, double);
// Prisma rectangular: largo, ancho(radio), altura
double areaSuperficia(double, double, double);



int main(){
    // Pregunta la figura: 2 = Cil, 3 = Esfera, 1 = PR
    int figura = escogaFigura();

    // Pregunta Volumen o Area de superficia - 1 = V, 2 = A(s)
    int formula = escogaFormula();

    // Pregunta los dimensiones de la figura
    std::string shape;
    double total;
    double lar;
    double rad;
    double alt;
    switch (figura){
        case 1:
            shape = "de la prisma rectangular";
            lar = getMeasure(shape, "el largo");
            rad = getMeasure(shape, "el ancho");
            alt = getMeasure(shape, "la altura");

            if (formula == 1){
                total = volumen(lar, rad, alt);
            }
            else {
                total = areaSuperficia(lar, rad, alt);
            }
            break;
        case 2:
            shape = "del cilindro";
            alt = getMeasure(shape, "la altura");
            rad = getMeasure(shape, "el radio");

            if (formula == 1){
                total = volumen(rad, alt);
            }
            else {
                total = areaSuperficia(rad, alt);
            }
            break;
        case 3:
            shape = "de la esfera";
            rad = getMeasure(shape, "el radio");

            if (formula == 1){
                total = volumen(rad);
            }
            else {
                total = areaSuperficia(rad);
            }
            break;
    }


    //desplega el valor de la figura deseo
    std::cout << std::endl << (formula == 1 ? "El volumen" : "La area de superficia")
        << " " << shape << " es " << total << std::endl;

    return 0;
}


int escogaFigura(){
    bool escoga = false;
    int figura = 0;

    do{
        std::cout << "Escoga una figura:\n"
            << "\ta. Cilindro\n"
            << "\tb. Esfera\n"
            << "\tc. Prisma rectangular\n"
            << "Seleccion: ";
        char seleccion;
        std::cin >> seleccion;
        
        // Clear keyboard buffer
        clearBuffer();

        // Input Validation
        switch (seleccion){
            case 'a': // Cilindro
                figura = 2;
                escoga = true;    
                break;
            case 'b': // Esfera
                figura = 3;
                escoga = true;
                break;
            case 'c': // Prisma Rectangular
                figura = 1;
                escoga = true;
                break;
            default:
                std::cout << seleccion << " no es un opcion valido.\n"
                    << "Por favor escoga \'a\', \'b\' o \'c\'." << std::endl;
                break;
        }
    
    } while (!escoga);
    return figura;
}


int escogaFormula(){
    bool escoga = false;
    int formula = 0;

    do{
        std::cout << "\nEscoga entre los siguientes opciones:\n"
        << "\ta. Volumen\n"
        << "\tb. Area de superficia\n"
        << "Seleccion: ";
        char seleccion;
        std::cin >> seleccion;
        
        // Clear keyboard buffer
        clearBuffer();

        // Input Validation
        switch (seleccion){
        case 'a': // Volumen
            formula = 1;
            escoga = true;    
            break;
        case 'b': // Area(S)
            formula = 2;
            escoga = true;
            break;
        default:
            std::cout << seleccion << " no es un opcion valido.\n"
                << "Por favor escoga \'a\' o \'b\'." << std::endl;
            break;
        }
    
    } while (!escoga);
    return formula;
}

// Clear keyboard buffer
void clearBuffer(){
    std::string key_buff;
    getline(std::cin, key_buff);
}

double getMeasure(std::string figura, std::string metric){
    double num = 0.0;
    do{
        std::cout << "\nEntre " << metric << " " << figura << ": ";
        std::cin >> num;
        clearBuffer();
        
    } while(!isValid(num)); //input validation - n > 0

    return num;
}

//input validation - n > 0
bool isValid(double n){
    bool valid = (n > 0.0);
    if (!valid){
        std::cout << n << " no es valido, por favor entre un numero real que es mayor que zero."
            << std::endl;
    }
    return valid;
}


double volumen(double radio, double altura){
    // Cilindro: V=(pi)*(r^2)*h
    return (pow(radio,2.0)*altura*M_PI);
}


double volumen(double radio){
    // Esfera: V=(4/3)*(pi)*(r^3)
    return ((4.0/3.0)*M_PI*pow(radio,3.0));
}


double volumen(double largo, double ancho, double altura){
    // Prisma rectangular V=l*w*h
    return (largo*ancho*altura);
}


double areaSuperficia(double radio, double altura){
    // Cilindro: A(s)=2*(pi)*(r^2) + 2*(pi)*r*h
    return (2.0*M_PI*pow(radio, 2.0) + 2.0*M_PI*radio*altura);
}


double areaSuperficia(double radio){
    // Esfera: A(s)=4*(pi)*(r^2)
    return (4.0*M_PI*pow(radio, 2.0));
}


double areaSuperficia(double largo, double ancho, double altura){
    // Prisma rectangular: A(s)=2*(l*w + l*h + w*h)
    return 2.0*(largo*ancho + largo*altura + ancho*altura);
}