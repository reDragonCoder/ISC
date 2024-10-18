Algoritmo colegiatura
	definir total_coleg, costoxMat, prom, desc, coleg_Iva como real
	definir num_mat Como Entero
	Imprimir "Ingrese la cantidad de materias a cursar: "
	leer num_mat
	Imprimir "Ingrese el costo por materia: "
	leer costoxMat
	total_coleg=num_mat*costoxMat
	Imprimir "Ingrese el promedio del alumno del ultimo periodo: "
	leer prom
	si prom>=9 Entonces
		desc=total_coleg*.3
		total_coleg=total_coleg-desc
		Imprimir "El total de su colegiatura es de: $", total_coleg
	sino
		si prom<9 Entonces
			coleg_Iva=total_coleg*1.1
			Imprimir "El total de su colegiatura incluyendo el IVA es de: $", coleg_Iva
		FinSi
	FinSi
FinAlgoritmo
