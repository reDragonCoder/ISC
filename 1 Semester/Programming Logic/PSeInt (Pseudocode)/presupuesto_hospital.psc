Algoritmo presupuesto_hospital
	Definir pres_anual, pres_gine, pres_trauma, pres_pedia Como Real
	Escribir 'Ingrese el presupuesto anual: '
	Leer pres_anual
	pres_gine <- pres_anual*0.4
	pres_trauma <- pres_anual*0.3
	pres_pedia <- pres_anual*0.3
	Escribir 'El area de ginecologia recibira $', pres_gine
	Escribir 'El area de traumatologia recibira $', pres_trauma
	Escribir 'El area de pediatria recibira $', pres_pedia
FinAlgoritmo
