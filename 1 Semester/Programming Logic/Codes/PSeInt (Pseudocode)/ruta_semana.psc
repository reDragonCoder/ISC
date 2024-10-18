Algoritmo ruta_semana
	definir tiem_lunes, tiem_miercoles, tiem_viernes, total como real
	Imprimir "Ingrese el tiempo en min y seg del lunes: "
	leer tiem_lunes
	Imprimir "Ingrese el tiempo en min y seg del miercoles: "
	leer tiem_miercoles
	Imprimir "Ingrese el tiempo en min y seg del viernes: "
	leer tiem_viernes
	total = (tiem_lunes + tiem_miercoles + tiem_viernes) / 3
	Imprimir "El tiempo promedio de la semana es: ", total
FinAlgoritmo
