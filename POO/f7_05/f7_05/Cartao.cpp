#include <sstream>
#include "Cartao.h"

bool Cartao::autorizaChamada() const
{
    if ( !tarifario)
        return false;
    return tarifario->autorizaChamada(saldo);
}

bool Cartao::registaChamada(int duracao)
{
    if ( !tarifario)
        return false;
    saldo -= tarifario->custoChamada(duracao);
    return true;
}

bool Cartao::carrega(double quantia)
{
    if ( !tarifario)
        return false;
    saldo += tarifario->carrega(quantia);
    return true;
}

bool Cartao::adereTarifario(Tarifario *t)
{
    if ( !t || tarifario) //só adiro ao tarifario se não tiver já um
        return false;
    tarifario = t;
    return true;
}

string Cartao::getAsString() const
{
    ostringstream os;
    os << numero << " saldo " << saldo << " ";
    if (tarifario)
        os << *tarifario;
    return os.str();
}

ostream &operator<<(ostream &os, const Cartao &c)
{
    os << c.getAsString();
    return os;
}
