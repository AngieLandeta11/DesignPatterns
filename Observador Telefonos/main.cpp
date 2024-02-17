#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Cliente
{
private:
    string nombre;
    string productoDeseado;

public:
    Cliente(const string& nombre, const string& producto) : nombre(nombre), productoDeseado(producto) {}

    void recibirNotificacion(const string& mensaje)
    {
        cout << "Cliente " << nombre << " recibió notificación: " << mensaje << endl;
    }

    const string& getProductoDeseado() const
    {
        return productoDeseado;
    }
};

// Sujeto Observado (Tienda)
class Tienda
{
private:
    string nuevoProducto;
    vector<Cliente*> clientes;

public:
    void agregarCliente(Cliente* cliente)
    {
        clientes.push_back(cliente);
    }

    void eliminarCliente(Cliente* cliente){}

    void notificarClientes()
    {
        for (Cliente* cliente : clientes)
        {
            if (cliente->getProductoDeseado() == nuevoProducto)
            {
                cliente->recibirNotificacion("Nuevo producto disponible: " + nuevoProducto);
            }
        }
    }

    void setNuevoProducto(const string& producto)
    {
        nuevoProducto = producto;
        notificarClientes();
    }
};

int main()
{
    Tienda tienda;

    Cliente cliente1("Juan", "iPhone");
    Cliente cliente2("Maria", "Samsung");

    tienda.agregarCliente(&cliente1);
    tienda.agregarCliente(&cliente2);

    tienda.setNuevoProducto("iPhone");

    return 0;
}
