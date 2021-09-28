#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

struct InfoPupusas
{
    int cantidad;
    string masa, bebida, ingredientes;

    InfoPupusas *siguiente;
};

class ListaSimple
{
    private:
    InfoPupusas *pInicio;

    public:
    ListaSimple ()
    {
        pInicio = NULL;
    }
    ~ListaSimple()
    {
        InfoPupusas *dato;
        while(dato->siguiente)
        {
            dato = pInicio;
            pInicio = pInicio->siguiente;
            delete dato;
        }
    };

    void insertOrden(int cantidad2, string masa2, string bebida2, string ingredientes2)
    {
        InfoPupusas *nuevaOrden = new InfoPupusas;

        nuevaOrden->cantidad = cantidad2;
        nuevaOrden->masa = masa2;
        nuevaOrden->bebida = bebida2;
        nuevaOrden->ingredientes = ingredientes2;
    
        nuevaOrden->siguiente = NULL;

        if(pInicio == NULL)
        {
            pInicio = nuevaOrden;
        } 
        else
        {
            InfoPupusas *auxiliar = nuevaOrden;
            auxiliar = pInicio;
            while(auxiliar->siguiente) //Busqueda del NULL.
            {
                auxiliar = auxiliar->siguiente;
            }
            auxiliar->siguiente = nuevaOrden;
        }
    }

    void mostrarInfo()
    {
        InfoPupusas *lectura = new InfoPupusas;
        lectura = pInicio;
        while(lectura != NULL)
        {
            cout<< " Cantidad de pupusas que desea: " << lectura->cantidad <<endl;
            cout<< " Las pupusas de arroz o maiz: " << lectura->masa <<endl;
            cout<< " Con Coca Cola o no?: " << lectura->bebida <<endl;
            cout<< " Ingredientes de la pupusas: " << lectura->ingredientes <<endl;
            
            lectura = lectura->siguiente;

        }
    }

};

int main()
{
    ListaSimple objListaSimple;

    int opcion = 0;
    bool continuar = true;
    int cantidad;
    string masa, bebida, ingredientes;

    while(continuar)
    {
        cout <<"Bienvenidos a la pupuseria Carlos" <<endl;

        cout <<"Menu" <<endl;
        cout <<"1) Ingresar la ordden de pupusas" <<endl;
        cout <<"2) Ver la orden" <<endl;
        cout <<"3) Salir" <<endl;

        cin >> opcion;

        switch (opcion)
        {
            case 1:
            cout << "Ingrese los datos de su orden de pupusas segun se le indica" <<endl;
            cout << "Ingrese la cantidad de pupusas que desea:" <<endl;
            cin >> cantidad;
            cout << "Ingrese la masa de las pupusas:" <<endl;
            cin >> masa;
            cout << " ¿La quiere con Coca Cola o sin bebida?" <<endl;
            cin >> bebida;
            cout << "Ingrese de que quiere que sean las pupusas o los ingredientes" <<endl;

            cin >> ingredientes;
            cin.ignore();

            objListaSimple.insertOrden(cantidad, masa, bebida, ingredientes);
            break;

            case 2:
            cout << " Imprimir la Lista Simple Enlazada:" <<endl;
            objListaSimple.mostrarInfo();
            opcion = 0;
            break;

            case 3:
            continuar = false;
            break;

            default:
            cout <<"El numero ingresado no pertenece a la lista de nuestro menu, ingrese otro nuevamente"<<endl;
            break;

        }

    } return 0;
    
}