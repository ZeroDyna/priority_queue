#include <iostream>
#include <vector> 
#include <string>

// Estructuras para comparación

template<class T>
struct Min {
    bool operator()(T a, T b) {
        return a < b;
    }
};
template<class T>
struct Max {
    bool operator()(T a, T b) {
        return a > b;
    }
};

// Clase priority_queue
template<class T, class Compare>
class priority {
public:
    std::vector<T> map;

    int hijo_derecho(int a);
    int hijo_izquierdo(int a);
    int padre(int a);
    void push(T valor);
    void del();
    void heapify(int index);
    void heapify_down(int index);
    T get_top();
    void mostrar_tareas() const;

};

template<class T, class Compare>
int priority<T, Compare>::hijo_derecho(int a) {
    return (2 * a) + 2;
}

template<class T, class Compare>
int priority<T, Compare>::hijo_izquierdo(int a) {
    return (2 * a) + 1;
}

template<class T, class Compare>
int priority<T, Compare>::padre(int a) {
    return (a - 1) / 2;
}

template<class T, class Compare>
void priority<T, Compare>::push(T valor) {
    map.push_back(valor);
    heapify(map.size() - 1);
}

template<class T, class Compare>
T priority<T, Compare>::get_top() {
    return map[0];
}

template<class T, class Compare>
void priority<T, Compare>::del() {
    if (map.empty()) {
        return;
    }
    else {
        map[0] = map.back();
        map.pop_back();
        if (!map.empty()) {
            heapify_down(0);
        }
    }
}

template<class T, class Compare>
void priority<T, Compare>::heapify(int index) {
    Compare dir;
    while (index > 0 && dir(map[index], map[padre(index)])) {
        std::swap(map[index], map[padre(index)]);
        index = padre(index);
    }
}

template<class T, class Compare>
void priority<T, Compare>::heapify_down(int index) {
    Compare comp;
    int size = map.size();
    while (true) {
        int mayor = index;
        int izq = hijo_izquierdo(index);
        int der = hijo_derecho(index);

        if (izq < size && comp(map[izq], map[mayor])) {
            mayor = izq;
        }

        if (der < size && comp(map[der], map[mayor])) {
            mayor = der;
        }

        if (mayor != index) {
            std::swap(map[index], map[mayor]);
            index = mayor;
        }
        else {
            break;
        }
    }
}

template<class T, class Compare>
void priority<T, Compare>::mostrar_tareas() const {
    for (const auto& t : map) {
        std::cout << "ID: " << t.id << ", Prioridad: " << t.prioridad << ", Descripción: " << t.descripcion << std::endl;
    }
}

// Clase Tarea
class Tarea {
public:
    int id;
    int prioridad;
    std::string descripcion;

    Tarea(int id, int prioridad, const std::string& descripcion)
        : id(id), prioridad(prioridad), descripcion(descripcion) {}

    bool operator<(const Tarea& other) const {
        return prioridad < other.prioridad;
    }

    bool operator>(const Tarea& other) const {
        return prioridad > other.prioridad;
    }
};

// Clase gestión
class gestion {
public:
    priority<Tarea, Max<Tarea>> test;

    void add_task(int id, int immp, const std::string& cont) {
        Tarea tarea(id, immp, cont);
        test.push(tarea);
    }

    void del_top() {
        test.del();
    }

    Tarea get_top() {
        return test.get_top();
    }

    void mostrar() {
        test.mostrar_tareas();
    }
};

// Función para mostrar el menú
void mostrar_menu() {
    std::cout << "\nMenu de Gestion de Tareas\n";
    std::cout << "1. Agregar tarea\n";
    std::cout << "2. Eliminar tarea con mayor prioridad\n";
    std::cout << "3. Obtener tarea con mayor prioridad\n";
    std::cout << "4. Mostrar todas las tareas\n";
    std::cout << "5. Salir\n";
    std::cout << "Seleccione una opcion: ";
}

int main() {
    gestion gestor;
    int opcion;
    int id = 1;

    do {
        mostrar_menu();
        std::cin >> opcion;

        switch (opcion) {
        case 1: {
            int prioridad;
            std::string descripcion;
            std::cout << "Ingrese la prioridad de la tarea: ";
            std::cin >> prioridad;
            std::cin.ignore(); // Ignorar el salto de línea residual
            std::cout << "Ingrese la descripcion de la tarea: ";
            std::getline(std::cin, descripcion);
            gestor.add_task(id++, prioridad, descripcion);
            break;
        }
        case 2:
            gestor.del_top();
            break;
        case 3:
            try {
                Tarea t = gestor.get_top();
                std::cout << "Tarea con mayor prioridad:\n";
                std::cout << "ID: " << t.id << ", Prioridad: " << t.prioridad << ", Descripcion: " << t.descripcion << std::endl;
            }
            catch (const std::runtime_error& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        case 4:
            gestor.mostrar();
            break;
        case 5:
            std::cout << "Saliendo del programa...\n";
            break;
        default:
            std::cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 5);

    return 0;
}
