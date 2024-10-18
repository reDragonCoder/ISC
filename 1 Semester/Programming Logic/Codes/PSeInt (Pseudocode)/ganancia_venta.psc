Algoritmo ganancia_venta
	definir precio_original, precio_ganancia Como Real
	definir GANANCIA Como Real
	Imprimir "Ingrese el precio original del artículo: "
	leer precio_original
	GANANCIA = 0.05
	precio_ganancia = (precio_original * GANANCIA) + precio_original
	Imprimir "El precio de venta para obtener una ganancia de 5% es: " precio_ganancia
FinAlgoritmo 
