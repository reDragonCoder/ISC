Algoritmo viaje_descuento
	Definir costo_primera, costo_segunda, total como Real
	imprimir "Ingrese el costo del camion de primera: "
	leer costo_primera
	costo_segunda = costo_primera-(costo_primera*0.30)
	total = (2*costo_primera)+(3*costo_segunda)
	imprimir "El total a pagar por las cinco personas es: " total
FinAlgoritmo
