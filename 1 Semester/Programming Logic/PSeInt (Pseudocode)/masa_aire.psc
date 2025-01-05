Algoritmo masa_aire
	definir masa, presion, volumen, temperatura como Real
	imprimir "Ingrese el valor de la presion: "
	leer presion
	imprimir "Ingrese el valor del volumen: "
	leer volumen 
	imprimir "Ingrese el valor de la temperatura: "
	leer temperatura
	masa = (presion*volumen) / (0.37*(temperatura+460))
	imprimir "La masa es: ", masa
FinAlgoritmo
