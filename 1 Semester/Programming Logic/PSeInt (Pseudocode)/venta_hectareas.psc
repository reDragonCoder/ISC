Algoritmo venta_hectareas
	definir DESCUENTO, hectareas, costo, costo_descuento, costo_individual, total_hectareas como real
	definir PERSONAS como entero
	PERSONAS = 3
	DESCUENTO = 0.07
	costo = 0
	para i = 1 hasta PERSONAS Hacer
		imprimir "Ingrese la cantidad de hectáreas vendidas a la persona ", i, ":"
		leer hectareas
		costo = costo+(hectareas*3000)
	FinPara
	costo_descuento = costo-(costo*DESCUENTO)
	costo_individual = costo_descuento/PERSONAS 
	total_hectareas = costo/3000
	Imprimir  "El número total de hectareas vendidas es: " total_hectareas
	imprimir "El costo individual con descuento es: " costo_individual
	imprimir "El costo total con descuento es: " costo_descuento
FinAlgoritmo
