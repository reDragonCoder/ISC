Algoritmo materias_dificiles_prom
	Definir ex_mate, tarea_mate, total_mate, ex_fisi, tarea_fisi, total_fisi, ex_quim, tarea_quim, total_quim, cal_mate, cal_fisi, cal_quimi, prom Como Real
	Escribir 'Ingrese la calificacion del examen de matematicas: '
	Leer ex_mate
	Para i<-1 Hasta 3 Hacer
		Escribir 'Ingrese la calificación de la tarea ', i
		Leer cal_mate
		tarea_mate <- tarea_mate+cal_mate
	FinPara
	total_mate <- (ex_mate*0.9)+(tarea_mate/3*0.1)
	Escribir 'Ingrese la calificacion del examen de fisica: '
	Leer ex_fisi
	Para i<-1 Hasta 2 Hacer
		Escribir 'Ingrese la calificación de la tarea ', i
		Leer cal_fisi
		tarea_fisi <- tarea_fisi+cal_fisi
	FinPara
	total_fisi <- (ex_fisi*0.8)+(tarea_fisi/2*0.2)
	Escribir 'Ingrese la calificacion del examen de quimica: '
	Leer ex_quim
	Para i<-1 Hasta 3 Hacer
		Escribir 'Ingrese la calificación de la tarea ', i
		Leer cal_quim
		tarea_quim <- tarea_quim+cal_quim
	FinPara
	total_quim <- (ex_quim*0.85)+(tarea_quim/3*0.15)
	prom <- (total_mate+total_fisi+total_quim)/3
	Escribir 'El promedio general es: ', prom
FinAlgoritmo
