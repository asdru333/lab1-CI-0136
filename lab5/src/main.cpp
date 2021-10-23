#include <iostream>
#include "Sesion.hpp"
#include "Chat.hpp"

int main() {
//TODO: Bitacora

    Sesion *bob = new Sesion ("Bob"),  *sam = new Sesion ("Sam"),  *frank = new Sesion ("Frank"),  *tom = new Sesion ("Tom");
    Sesion* staff[] = {bob, sam, frank, tom};
    Chat chatGeneral, compas;
    for (Sesion* sesion : staff)
        chatGeneral.meterAlChat(sesion);
    bob->enviarBroadcast(chatGeneral, "I'm quitting this job!"); // Broadcast
    bob->enviarP2P(chatGeneral,"quePa", *frank);
    compas.meterAlChat(frank);
    compas.meterAlChat(tom);  // Sam's buddies only
    sam->enviarBroadcast(compas, "Hooray!  He's gone!  Let's go for a drink, guys!");  // BroadCast
    return 0;
}
