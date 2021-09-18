int main()
{
    Tipo* proyecto = new Tipo("proyecto");
    Tipo* tarea = new Tipo("tarea");
    Tipo* fase = new Tipo("fase", proyecto, tarea);
    tarea->setPadre(fase);
    proyecto->setHijo(fase);
    ActividadCompuesta* proyecto1 = new ActividadCompuesta("cuchi", proyecto, "01/07/1997", "17/08/2021", "01/07/1999", "17/08/2021", "proyecto global");
    std::cout << proyecto1->getResponsable() << std::endl;
    std::cout << proyecto1->getDescripcion() << std::endl;
    std::cout << proyecto1->getFechaPlanteadaInicio() << std::endl;
    std::cout << proyecto1->getFechaPlanteadaFinal() << std::endl;
    std::cout << proyecto1->getFechaRealInicio() << std::endl;
    std::cout << proyecto1->getFechaRealFinalizacion() << std::endl;
    std::cout << proyecto1->getTipo()->getNombre() << std::endl;
    if (!proyecto1->getPadre())
        std::cout << "EXITO" << std::endl;
    std::cout << fase->getNombre() << std::endl;
    
    ActividadCompuesta* fase1 = new ActividadCompuesta("Asdrúbal", fase, "01/07/1999", "17/08/2021", "01/07/1999", "17/08/2021", "primera fase");
    proyecto1->add(fase1);
    std::cout << proyecto1->getHijos()[0]->getDescripcion() << std::endl;
    std::cout << proyecto1->getHijos()[0]->getPadre()->getDescripcion() << std::endl;
    
    ActividadCompuesta* fase2 = new ActividadCompuesta("Juan", fase, "01/07/1998", "17/08/2022", "01/07/1998", "17/08/2021", "segunda fase");
    proyecto1->add(fase2);
    proyecto1->calcularFechas();
    std::cout << proyecto1->getFechaPlanteadaInicio() << std::endl;
    std::cout << proyecto1->getFechaPlanteadaFinal() << std::endl;
    proyecto1->remove(fase1);
    if (proyecto1->getHijos().size() == 1 and !fase1->getPadre())
        std::cout << "EXITO2" << std::endl;
    ActividadSimple* tarea1 = new ActividadSimple("José", tarea, "01/07/1998", "17/08/2022", "01/07/1998", "17/08/2021", "primera tarea");
    std::cout << tarea1->getDescripcion() << std::endl;
    fase2->add(tarea1);
    std::cout << tarea1->getPadre()->getDescripcion() << std::endl;
    std::cout << fase2->getHijos()[0]->getDescripcion() << std::endl;
    return 0;
}
