Algoritmo desc_azar
	definir total_compra, compra_des, descuento Como Real
	definir num Como Entero
	Imprimir "Ingrese el total de su compra: "
	leer total_compra
	num = azar(148)
	Imprimir "El numero que le toco es: ", num
	si num<74 Entonces
		descuento=total_compra*0.15
		compra_des=total_compra-descuento
		imprimir "El total de su compra con un descuento del 15% es $", compra_des
	SiNo
		si num>=74
			descuento=total_compra*0.2
			compra_des=total_compra-descuento
			imprimir "El total de su compra con un descuento del 20% es $", compra_des
		FinSi
	FinSi
FinAlgoritmo