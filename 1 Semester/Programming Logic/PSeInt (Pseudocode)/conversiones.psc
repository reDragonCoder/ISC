Algoritmo conversiones
	definir pies, metros, suma_pulgadas, suma_yardas, suma_metros, suma_millas Como Real
	Imprimir "Ingresa la cantidad en pies: "
	leer pies
	Imprimir "Ingresa la cantidad en metros: "
	leer metros
	suma_metros = (pies/3.281) + metros
	suma_pulgadas = suma_metros * 39.37
	suma_yardas = suma_metros * 1.094
	suma_millas = suma_metros / 1609
	Imprimir "La suma expresada en pulgadas es: ", suma_pulgadas
	Imprimir "La suma expresada en yardas es: ", suma_yardas
	Imprimir "La suma expresada en metros es: " suma_metros
	Imprimir "La suma expresada en millas es: ", suma_millas
FinAlgoritmo
