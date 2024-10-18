Algoritmo area_perimetro
	definir lado_cuadrado, area_cuadrado, perimetro_cuadrado como real
	definir base_rectangulo, altura_rectangulo, area_rectangulo, perimetro_rectangulo como real
	definir base_triangulo, altura_triangulo, area_triangulo, perimetro_triangulo, lado2, lado3 como real
	imprimir "Ingrese el lado del cuadrado: "
	leer lado_cuadrado
	area_cuadrado = lado_cuadrado*lado_cuadrado
	perimetro_cuadrado = 4*lado_cuadrado
	imprimir "El area del cuadrado es: " area_cuadrado
	imprimir "El perimetro del cuadrado es: " perimetro_cuadrado
	
	imprimir "Ingrese la base del rectangulo: "
	leer base_rectangulo
	imprimir "Ingrese la altura del rectangulo: "
	leer altura_rectangulo
	area_rectangulo = base_rectangulo*altura_rectangulo
	perimetro_rectangulo = 2*(base_rectangulo+altura_rectangulo)
	imprimir "El area del rectangulo es: " area_rectangulo
	imprimir "El perimetro del rectangulo es: " perimetro_rectangulo
	
	imprimir "Ingrese la base del triangulo: "
	leer base_triangulo
	imprimir "Ingrese la altura del triangulo: "
	leer altura_triangulo
	imprimir "Ingrese el valor del lado 2 (diferente a la base): "
	leer lado2
	imprimir "Ingrese el valor del lado 2 (diferente a la base y al lado anterior): "
	leer lado3
	area_triangulo = (base_triangulo*altura_triangulo)/2
	perimetro_triangulo = base_triangulo+lado2+lado3
	imprimir "El área del triángulo es: " area_triangulo
	imprimir "El perímetro del triángulo es: " perimetro_triangulo
	
FinAlgoritmo
