//
// Created by carlo on 10/22/2021.
//

#ifndef LAB5_MEDIADOR_CHAT_HPP
#define LAB5_MEDIADOR_CHAT_HPP


#include "Mediador.hpp"

class Chat : public Mediador {
     void distributeMessage ( Colega*, const  std::string&)  override;
     void distributeMessage ( Colega*, const  std::string&,  Colega* receptor)  override;


};


#endif //LAB5_MEDIADOR_CHAT_HPP
