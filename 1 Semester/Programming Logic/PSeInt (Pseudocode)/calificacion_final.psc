Algoritmo calificacion_final
	definir calif_parcial1, calif_parcial2, calif_final, calif_proyecto, total_calif Como Real
	imprimir "Ingrese la calificacion del 1er parcial: "
	leer calif_parcial1
	imprimir "Ingrese la calificacion del 2ndo parcial: "
	leer calif_parcial2
	imprimir "Ingrese la calificacion del final: "
	leer calif_final
	imprimir "Ingrese la calificacion del proyecto: "
	leer calif_proyecto
	total_calif = (calif_parcial1 * .25) + (calif_parcial2 * .25) + (calif_final * .3) + (calif_proyecto * .2)
	Imprimir "Su calificacion total es: ", total_calif
FinAlgoritmo
