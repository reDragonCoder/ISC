Algoritmo colegxUnidad
	Definir total_coleg, prom, desc, mat_rep Como Real
	Definir tipo_alumno Como Entero
	Escribir 'Ingrese 1 si es alumno es de profesional o 2 si es de preparatoria: '
	Leer tipo_alumno
	Escribir 'Ingrese el promedio del alumno: '
	Leer prom
	Escribir 'Ingrese el numero de materias reprobadas: '
	Leer mat_rep
	Si prom>=9.5 Y tipo_alumno=2 Entonces
		total_coleg <- 55*36
		desc <- total_coleg*0.25
		total_coleg <- total_coleg-desc
		Escribir 'La colegiatura del alumno sera de: $', total_coleg
	FinSi
	Si prom>=9 Y prom<9.5 Y tipo_alumno=2 Entonces
		total_coleg <- 50*36
		desc <- total_coleg*0.1
		total_coleg <- total_coleg-desc
		Escribir 'La colegiatura del alumno sera de: $', total_coleg
	FinSi
	Si prom>7 Y prom<9 Y tipo_alumno=2 Entonces
		total_coleg <- 50*36
		Escribir 'La colegiatura del alumno sera de: $', total_coleg
	FinSi
	Si prom<=7 Y mat_rep>=0 Y mat_rep<=3 Y tipo_alumno=2 Entonces
		total_coleg <- 45*36
		Escribir 'La colegiatura del alumno sera de: $', total_coleg
	FinSi
	Si prom<=7 Y mat_rep>=4 Y tipo_alumno=2 Entonces
		total_coleg <- 40*36
		Escribir 'La colegiatura del alumno sera de: $', total_coleg
	FinSi
	Si prom>=9.5 Y tipo_alumno=1 Entonces
		total_coleg <- 55*60
		desc <- total_coleg*0.2
		total_coleg <- total_coleg-desc
		Escribir 'La colegiatura del alumno sera de: $', total_coleg
	FinSi
	Si prom<9.5 Y tipo_alumno=1 Entonces
		total_coleg <- 55*60
		Escribir 'La colegiatura del alumno sera de: $', total_coleg
	FinSi
FinAlgoritmo
