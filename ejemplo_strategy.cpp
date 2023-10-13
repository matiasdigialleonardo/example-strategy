#include <iostream>

using namespace std;

class TransportStrategy 
{
    public:
        virtual void calcularRuta() = 0;
};

class PeatonStrategy : public TransportStrategy
{
    public:
        void calcularRuta() override
        {
            cout << "Calculando ruta para peaton..." << endl;
        }
};

class CocheStrategy : public TransportStrategy
{
    public:
        void calcularRuta() override
        {
            cout << "Calculando ruta para coche..." << endl;
        }
};

class TransportePublicoStrategy : public TransportStrategy
{
    public:
        void calcularRuta() override
        {
            cout << "Calculando ruta para transporte público..." << endl;
        }
};

class Navigator
{
    private:
        TransportStrategy* strategy;

    public:
        Navigator(TransportStrategy* initialStrategy) : strategy(initialStrategy) {}

        void setStrategy(TransportStrategy* newStrategy)
        {
            strategy = newStrategy;
        }

        void calcularRuta()
        {
            strategy->calcularRuta();
        }

        TransportStrategy* getStrategy()
        {
            return strategy;
        }
};

#include <iostream>

// ... (Definición de clases y código anterior) ...

int main() {
    TransportStrategy* peaton = new PeatonStrategy();
    TransportStrategy* coche = new CocheStrategy();
    TransportStrategy* transportePublico = new TransportePublicoStrategy();
    Navigator* navigator = new Navigator(peaton);

    int opcion = 0;

    while (opcion != 4) {
        cout << "Seleccione una opcion:" << endl;
        cout << "1. Calcular ruta para Peaton" << endl;
        cout << "2. Calcular ruta para Coche" << endl;
        cout << "3. Calcular ruta para Transporte Publico" << endl;
        cout << "4. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                navigator->setStrategy(peaton);
                navigator->calcularRuta();
                break;
            case 2:
                navigator->setStrategy(coche);
                navigator->calcularRuta();
                break;
            case 3:
                navigator->setStrategy(transportePublico);
                navigator->calcularRuta();
                break;
            case 4:
                delete peaton;
                delete coche;
                delete transportePublico;
                delete navigator;
                return 0;
            default:
                cout << "Opcion no valida. Por favor, seleccione una opción valida." << endl;
        }
    }

    return 0;
}


