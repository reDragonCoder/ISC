Algoritmo aumento_15
	definir sueldoEmpleado, nuevoSaldo Como Real
	Imprimir "Ingrese el sueldo: "
	leer sueldoEmpleado
	si (sueldoEmpleado < 1450) Entonces
		nuevoSaldo = sueldoEmpleado * 1.15
		Imprimir "Su nuevo sueldo es: ", nuevoSaldo
	SiNo
		Imprimir "No tiene aumento"
	FinSi
FinAlgoritmo
