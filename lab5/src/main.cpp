#include <fstream>
#include <iostream>
#include <sstream>

#include "Chat.hpp"
#include "Sesion.hpp"

int main() {
  std::stringstream bitacora;
  Sesion *javier = new Sesion("Javier"), *charlie = new Sesion("Charlie"),
         *asdrubal = new Sesion("Asdrubal"), *pedro = new Sesion("Pedro");
  Sesion* personas[4];
  personas[0] = javier;
  personas[1] = charlie;
  personas[2] = asdrubal;
  personas[3] = pedro;
  Chat chatGeneral("CI-420"), compas("Compas");
  for (Sesion* sesion : personas) bitacora << chatGeneral.meterAlChat(sesion);
  bitacora << pedro->enviarBroadcast(chatGeneral,
                                     "Chicos, mañana tendremos quiz a primera "
                                     "hora de clase, no lleguen tarde.");
  bitacora << charlie->enviarP2P(
      chatGeneral,
      "Mae asdrubal, digale a javier que se meta al chat de compas", *asdrubal);
  bitacora << asdrubal->enviarP2P(
      chatGeneral, "Mae, vamos al chat de compas un toque", *javier);
  bitacora << chatGeneral.sacarDelChat(asdrubal);
  bitacora << chatGeneral.sacarDelChat(javier);
  bitacora << chatGeneral.sacarDelChat(charlie);
  bitacora << compas.meterAlChat(asdrubal);
  bitacora << compas.meterAlChat(javier);
  bitacora << compas.meterAlChat(charlie);
  bitacora << charlie->enviarBroadcast(
      compas,
      "Maes vieron que pereza, quiz en la mañana y "
      "hasta ahora avisa");
  bitacora << pedro->enviarP2P(
      chatGeneral, "Hola Charlie, tenemos que hablar sobre sus notas...",
      *charlie);  // charlie no recibe el mensaje porque salio del chat
  std::cout << bitacora.str();
  std::ofstream output;
  output.open("Bitacora.txt");
  output << bitacora.str();
  output.close();
  return 0;
}
