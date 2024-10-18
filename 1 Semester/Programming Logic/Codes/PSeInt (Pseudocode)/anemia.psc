Algoritmo anemia
	Definir edad, hemoglob Como Real
	Definir sexo Como Caracter
	Escribir 'Ingrese la edad del paciente como entero, si solo tiene meses, escriba un punto y la cantidad de meses de 9 a 12: '
	Leer edad
	Escribir 'Ingrese una M si el paciente es mujer o una H si es hombre: '
	Leer sexo
	Escribir 'Ingrese el nivel de hemoglobina del paciente: '
	Leer hemoglob
	Si edad=0.0 O edad=0.1 Entonces
		Si hemoglob>=13.0 Y hemoglob<=26.0 Entonces
			Escribir 'El paciente está dentro de los niveles normales'
		SiNo
			Si hemoglob<13.0 Entonces
				Escribir 'El paciente tiene anemia'
			SiNo
				Si hemoglob>26.0 Entonces
					Escribir 'El paciente tiene policitemia'
				FinSi
			FinSi
		FinSi
	FinSi
	// **//
	Si edad>0.1 Y edad<=0.6 Entonces
		Si hemoglob>=10.0 Y hemoglob<=18.0 Entonces
			Escribir 'El paciente está dentro de los niveles normales'
		SiNo
			Si hemoglob<10.0 Entonces
				Escribir 'El paciente tiene anemia'
			SiNo
				Si hemoglob>18.0 Entonces
					Escribir 'El paciente tiene policitemia'
				FinSi
			FinSi
		FinSi
	FinSi
	// **//
	Si edad>0.6 Y edad<=0.12 Entonces
		Si hemoglob>=11.0 Y hemoglob<=15.0 Entonces
			Escribir 'El paciente está dentro de los niveles normales'
		SiNo
			Si hemoglob<11.0 Entonces
				Escribir 'El paciente tiene anemia'
			SiNo
				Si hemoglob>15.0 Entonces
					Escribir 'El paciente tiene policitemia'
				FinSi
			FinSi
		FinSi
	FinSi
	// **//
	Si edad>1 Y edad<=5 Entonces
		Si hemoglob>=11.5 Y hemoglob<=15.0 Entonces
			Escribir 'El paciente está dentro de los niveles normales'
		SiNo
			Si hemoglob<11.5 Entonces
				Escribir 'El paciente tiene anemia'
			SiNo
				Si hemoglob>15.0 Entonces
					Escribir 'El paciente tiene policitemia'
				FinSi
			FinSi
		FinSi
	FinSi
	// **//
	Si edad>5 Y edad<=10 Entonces
		Si hemoglob>=12.6 Y hemoglob<=15.5 Entonces
			Escribir 'El paciente está dentro de los niveles normales'
		SiNo
			Si hemoglob<12.6 Entonces
				Escribir 'El paciente tiene anemia'
			SiNo
				Si hemoglob>15.5 Entonces
					Escribir 'El paciente tiene policitemia'
				FinSi
			FinSi
		FinSi
	FinSi
	// **//
	Si edad>10 Y edad<=15 Entonces
		Si hemoglob>=13.0 Y hemoglob<=15.5 Entonces
			Escribir 'El paciente está dentro de los niveles normales'
		SiNo
			Si hemoglob<13.0 Entonces
				Escribir 'El paciente tiene anemia'
			SiNo
				Si hemoglob>15.5 Entonces
					Escribir 'El paciente tiene policitemia'
				FinSi
			FinSi
		FinSi
	FinSi
	// **//
	Si edad>15 Y sexo='M' Entonces
		Si hemoglob>=12.0 Y hemoglob<=16.0 Entonces
			Escribir 'El paciente está dentro de los niveles normales'
		SiNo
			Si hemoglob<12.0 Entonces
				Escribir 'El paciente tiene anemia'
			SiNo
				Si hemoglob>16.0 Entonces
					Escribir 'El paciente tiene policitemia'
				FinSi
			FinSi
		FinSi
	FinSi
	// **//
	Si edad>15 Y sexo='H' Entonces
		Si hemoglob>=14.0 Y hemoglob<=18.0 Entonces
			Escribir 'El paciente está dentro de los niveles normales'
		SiNo
			Si hemoglob<14.0 Entonces
				Escribir 'El paciente tiene anemia'
			SiNo
				Si hemoglob>18.0 Entonces
					Escribir 'El paciente tiene policitemia'
				FinSi
			FinSi
		FinSi
	FinSi
FinAlgoritmo
