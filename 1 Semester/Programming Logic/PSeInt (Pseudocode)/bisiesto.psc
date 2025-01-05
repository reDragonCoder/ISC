Algoritmo bisiesto
	definir anio Como Entero
	Imprimir "Ingrese un año: "
	leer anio
	anio_bisiesto = 0
	anio_noBisiesto = 0
	si anio%4=0 Entonces
		anio_bisiesto=anio
		si anio%100=0 Entonces
			anio=anio
			si anio%400=0
				anio_bisiesto=anio
				Imprimir "El año ", anio_bisiesto, " es bisiesto"
			sino
				anio_noBisiesto=anio
				Imprimir "El año ", anio_noBisiesto, " no es bisiesto"
			FinSi
		sino
			Imprimir "El año ", anio_bisiesto, " es bisiesto"
		FinSi
	SiNo
		anio_noBisiesto=anio
		Imprimir "El año ", anio_noBisiesto, " no es bisiesto"
	FinSi
FinAlgoritmo

	