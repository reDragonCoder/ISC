Algoritmo manzanas_descuento
	definir numKilos, totalPagar, costoxkg Como Real
	Imprimir "Ingrese el numero de kilos: "
	leer numKilos
	Imprimir "Ingrese el precio del kilo: "
	leer costoxkg
	si (numKilos>=0) y (numKilos<=2) Entonces
		totalPagar=(costoxkg*numKilos)
		Imprimir "Total a pagar: $", totalPagar
	FinSi
	si (numKilos>=2.01) y (numKilos<=5) Entonces
		totalPagar=(costoxkg*numKilos)*0.90
		Imprimir "Total a pagar: $", totalPagar
	FinSi
	si (numKilos>=5.01) y (numKilos<=10) Entonces
		totalPagar=(costoxkg*numKilos)*0.85
		Imprimir "Total a pagar: $", totalPagar
	FinSi
	si (numKilos>=10.01) Entonces
		totalPagar=(costoxkg*numKilos)*0.80
		Imprimir "Total a pagar: $", totalPagar
	FinSi
FinAlgoritmo
