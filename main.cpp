int main()
{
	Tipo* proyecto = new Tipo("proyecto");
	Tipo* tarea = new Tipo("tarea");
	Tipo* fase = new Tipo("fase", proyecto, tarea);
	tarea->setPadre(fase);
	proyecto->setHijo(fase);
	ActividadCompuesta* proyecto1 = new ActividadCompuesta("cuchi", proyecto, "01/07/1999", "17/08/2021", "01/07/1999", "17/08/2021", "proyecto global", nullptr);
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
	ActividadCompuesta* fase1 = new ActividadCompuesta("cuchi", fase, "01/07/1999", "17/08/2021", "01/07/1999", "17/08/2021", "primera fase", proyecto1);
	proyecto1->add(fase1);
	std::cout << proyecto1->getHijo()[0]->getDescripcion() << std::endl;
	return 0;
}
