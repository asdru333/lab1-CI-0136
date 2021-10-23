//
// Created by carlo on 10/22/2021.
//

#ifndef LAB5_MEDIADOR_MEDIADOR_HPP
#define LAB5_MEDIADOR_MEDIADOR_HPP


#include <list>
#include <vector>
#include "Colega.hpp"

class Mediador {
private:
    std::vector<Colega*> miembros;
public:
    const std::vector<Colega*>& getMiembros() const {return miembros;}
    virtual void distributeMessage ( Colega* emisor, const  std::string&)  = 0;
    virtual void distributeMessage ( Colega* emisor,const   std::string&, Colega* receptor)  = 0;

    virtual void meterAlChat (Colega* colleague) {miembros.emplace_back (colleague);}
};



#endif //LAB5_MEDIADOR_MEDIADOR_HPP
