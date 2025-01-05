Algoritmo pago_empleado
	definir hrsmes, pago, tarifaxhr como real
	imprimir "Ingrese las horas trabajadas en el mes: "
	leer hrsmes
	imprimir "Ingrese la tarifa por hora: "
	leer tarifaxhr
	pago = hrsmes * tarifaxhr
	imprimir "Su pago será de ", pago, " pesos"
FinAlgoritmo
