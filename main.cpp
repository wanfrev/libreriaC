#include <iostream>
#include <string>
#include "LinkedData.h" // Incluimos tu librería

// Clase Car para usar en la lista
class Car {
private:
    std::string brand;
    std::string model;
    int year;

public:
    Car(const std::string& b, const std::string& m, int y)
        : brand(b), model(m), year(y) {}

    void print() const {
        std::cout << brand << " " << model << " (" << year << ")" << std::endl;
    }
};

int main() {
    // Creamos una lista enlazada de coches
    LinkedData<Car> carList;

    // Agregamos coches a la lista
    carList.add(Car("Toyota", "Corolla", 2020));
    carList.add(Car("Ford", "Mustang", 2021));
    carList.add(Car("Tesla", "Model 3", 2022));

    std::cout << "Total de coches: " << carList.size() << "\n\n";

    // Mostrar el primero
    std::cout << "Primer coche:\n";
    carList.first().print();

    // Mostrar el siguiente
    std::cout << "\nSiguiente coche:\n";
    carList.next().print();

    // Mostrar el último
    std::cout << "\nÚltimo coche:\n";
    carList.last().print();

    // Eliminar el segundo coche (índice 1)
    std::cout << "\nEliminando coche en posición 1...\n";
    carList.remove(1);

    std::cout << "\nLista después de eliminar:\n";
    carList.first().print();
    carList.next().print();

    std::cout << "\nTotal de coches después de eliminar: " << carList.size() << std::endl;

    return 0;
}
