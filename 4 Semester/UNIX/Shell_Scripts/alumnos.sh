# !/bin/bash

DATA_FILE="alumnos.datos"
LOCK_FILE="bloquear.alumnos"

touch "$DATA_FILE"

bloqueo(){
 while [ -f "$LOCK_FILE" ]; do
  sleep 5
 done
 touch "$LOCK_FILE"
}

desbloqueo(){
 rm -f "$LOCK_FILE"
}

captura(){
 echo -n "Nombre: "; read nombre
 echo -n "Apellidos: "; read apellidos
 echo -n "Carrera: "; read carrera
 echo -n "Semestre: "; read semestre
 echo -n "Grupo: "; read grupo
 echo -n "Materia: "; read materia
 echo -n "Faltas: "; read faltas
 echo -n "Promedio: "; read promedio
}

existe(){
 echo ""
 echo -n "Uaa id: "; read uaaid
 registro=$(awk -F: -v llave="$uaaid" '($1==llave){print}' alumnos.datos)
}

alta(){
 existe
 if [ -z "$registro" ]; then
  captura
  bloqueo
  echo "$uaaid:$nombre:$apellidos:$carrera:$semestre:$grupo:$materia:$faltas:$promedio" >> "$DATA_FILE"
  desbloqueo
  echo "Alumno agregado"
 else
  echo "El uaa id $uaaid ya existe"
 fi
}

# Baja con grep
baja-general(){
 echo -n "Uaaid a dar de baja: "; read uaaid
 bloqueo
 grep -v "^$uaaid:" "$DATA_FILE" > tmp.$$
 mv -f tmp.$$ "$DATA_FILE"
 desbloqueo
 echo "Baja general realizada"
}

# Baja con awk
baja-uaaid(){
 echo "Uaaid de dar de baja: "; read uaaid
 bloqueo
 awk -F: -v llave="$uaaid" '($1!=llave){print}' "$DATA_FILE" > tmp.$$
 mv -f tmp.$$ "$DATA_FILE"
 desbloqueo
 echo "Baja por UAAID realizada"
}

# NOTA: grep -i (insensible a mayúsculas), -n (num. de línea),
# --color (resalta el match) y comillas para cadenas con espacios
consulta-general(){
 echo -n "Datos a buscar: "; read dato
 grep -i -n --color=always "$dato" "$DATA_FILE" | less -R
}

consulta-uaaid(){
 echo -n "Uaaid: "; read uaaid
 awk -F: -v llave="$uaaid" '
  ($1==llave){
    print "Uaaid: " $1
    print "Nombre: " $2 " " $3
    print "Promedio: " $9
  }
 ' "$DATA_FILE"
}

reporte-carrera(){
 echo -n "Cual carrera: "; read carrera
 resultados=$(awk -F: -v llave="$carrera" '(tolower($4)==llave){print}' "$DATA_FILE")
 if [ -z "$resultados" ]; then
  echo "No se encontraron alumnos en la carrera \"$carrera\"."
 else
  echo "Alumnos de la carrera \"$carrera\":"
  echo "$resultados"
 fi
}

reporte-reprobados(){
 resultados=$(awk -F: '($9<6.5){print}' "$DATA_FILE")
 if [ -z "$resultados" ]; then
  echo "Ningún alumno tiene promedio menor a 6.5"
 else
  echo "Alumnos con promedio menor a 6.5: "
  echo "$resultados"
 fi
}

limpiar-pantalla(){
 clear
}

menu(){
 echo ""
 echo "======= Menu ======"
 echo "1) Alta"
 echo "2) Baja general"
 echo "3) Baja por UAAID"
 echo "4) Consulta general"
 echo "5) Consulta por UAAID"
 echo "6) Modificaciones"
 echo "7) Reportes"
 echo "8) Limpiar terminal"
 echo "S) Salir"
 echo -n "Opcion: "; read opcion
 case "$opcion" in
  1) alta ;;
  2) baja-general ;;
  3) baja-uaaid ;;
  4) consulta-general ;;
  5) consulta-uaaid ;;
# 6) modificacion ;;
  7)
    echo "a) Por carrera"
    echo "b) Reprobados"
    echo -n "Tipo: "; read tipo
    case "$tipo" in
     a) reporte-carrera ;;
     b) reporte-reprobados ;;
     *) echo "Reporte inválido" ;;
    esac
    ;;
  8) limpiar-pantalla ;;
  [Ss]) echo "¡Hasta luego!"; exit 0 ;;
  *) echo "Opcion inválida" ;;
 esac
}


# Codigo principal
 opcion=0
 while true; do
  menu
 done
