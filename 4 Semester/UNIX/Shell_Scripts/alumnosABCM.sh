# !/bin/bash

BLUE="\e[1;34m"
GREEN="\e[1;32m"
RED="\e[1;31m"
BOLD="\e[1;38m"
RESET="\e[0m"

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
 echo -n "UAA id: "; read uaaid
 registro=$(awk -F: -v llave="$uaaid" '($1==llave){print}' alumnos.datos)
}

alta(){
 existe
 if [ -z "$registro" ]; then
  captura
  bloqueo
  echo "$uaaid:$nombre:$apellidos:$carrera:$semestre:$grupo:$materia:$faltas:$promedio" >> "$DATA_FILE"
  desbloqueo
  echo "${GREEN}¡Alumno agregado exitosamente!${RESET}"
 else
  echo "${RED}¡El UAA id $uaaid ya existe!${RESET}"
 fi
}

baja_general(){
 echo -n "Dato a buscar para dar de baja: "; read dato
 coincidencias=$(grep -i "$dato" "$DATA_FILE")
 
 if [ -z "$coincidencias" ]; then
  echo "${RED}¡No se encontraron coincidencias con \"$dato\"!${RESET}"
 else
  echo "${BOLD}Coincidencias encontradas:${RESET}"
  echo "$coincidencias"
  echo ""
  echo -n "${BOLD}¿Deseas eliminar estos registros? (s/n): ${RESET}"; read confirmacion
  if [ "$confirmacion" = "s" ] || [ "$confirmacion" = "S" ]; then
   bloqueo
   grep -iv "$dato" "$DATA_FILE" > tmp.$$
   mv -f tmp.$$ "$DATA_FILE"
   desbloqueo
   echo "${GREEN}¡Registros eliminados exitosamente!${RESET}"
  else
   echo "${BOLD}Operación cancelada${RESET}"
  fi
 fi

}

baja_uaaid(){
 echo ""
 echo -n "UAA id a dar de baja: "; read uaaid
 registro=$(awk -F: -v llave="$uaaid" '($1==llave){print}' "$DATA_FILE")
 
 if [ -z "$registro" ]; then
  echo "${RED}¡El UAA id $uaaid no existe!${RESET}"
 else
  echo ""
  echo "${BOLD}Registro econtrado: ${RESET}"
  echo "$registro"
  echo ""
  echo -n "${BOLD}¿Desea eliminar este registro? (s/n): ${RESET}"; read confirmacion
  if [ "$confirmacion" = "s" ] || [ "$confirmacion" = "S" ]; then
   bloqueo
   awk -F: -v llave="$uaaid" '($1!=llave){print}' "$DATA_FILE" > tmp.$$
   mv -f tmp.$$ "$DATA_FILE"
   desbloqueo
   echo "${GREEN}¡Baja por UAA id realizada exitosamente!${RESET}"
  else
   echo "${BOLD}Operación cancelada${RESET}"
  fi
 fi
}

# NOTA: grep -i (insensible a mayúsculas), -n (num. de línea),
# --color (resalta el match) y comillas para cadenas con espacios
consulta_general(){
 echo ""
 echo -n "Datos a buscar: "; read dato
 grep -i -n --color=always "$dato" "$DATA_FILE" | less -R
}

consulta_uaaid(){
 echo ""
 echo -n "UAA id: "; read uaaid
 resultado=$(awk -F: -v llave="$uaaid" '
  ($1==llave){
    print "Nombre: " $2 " " $3
    print "Carrera: " $4
    print "Semestre: " $5
    print "Grupo: " $6
    print "Materia: " $7
    print "Faltas: " $8
    print "Promedio: " $9
    existe=1
  }
  END{
    if (!existe){
      print "¡No se encontró el UAA id!"
    }
  }
 ' "$DATA_FILE")
  
  echo "$resultado" | grep -q "¡No se encontró el UAA id!"
  if [ $? -eq 0 ]; then
   echo -n "${RED}¡No se encontró el UAA id!${RESET}"
   echo ""
  else
   echo "$resultado"
  fi
}

reporte_carrera(){
 echo -n "¿Cuál carrera?: "; read carrera
 carrera=$(echo "$carrera" | tr '[:upper:]' '[:lower:]' | xargs)
 resultados=$(awk -F: -v llave="$carrera" '(tolower($4)==llave){print}' "$DATA_FILE")
 if [ -z "$resultados" ]; then
  echo "${RED}¡No se encontraron alumnos en la carrera \"$carrera\"!${RESET}"
 else
  echo ""
  echo "${BOLD}Alumnos de la carrera \"$carrera\"${RESET}"
  echo "$resultados"
 fi
}

reporte_reprobados(){
 resultados=$(awk -F: '($9<6.5){print}' "$DATA_FILE")
 if [ -z "$resultados" ]; then
  echo "${RED}¡Ningún alumno tiene promedio menor a 6.5!${RESET}"
 else
  echo ""
  echo "${BOLD}***Alumnos con promedio menor a 6.5***${RESET}"
  echo "$resultados"
 fi
}

modificacion(){
 existe
 if [ "$registro" != "" ]
 then
  onombre=$(echo "$registro" | cut -d: -f2)
  oapellido=$(echo "$registro" | cut -d: -f3)
  ocarrera=$(echo "$registro" | cut -d: -f4)
  osemestre=$(echo "$registro" | cut -d: -f5)
  ogrupo=$(echo "$registro" | cut -d: -f6)
  omateria=$(echo "$registro" | cut -d: -f7)
  ofaltas=$(echo "$registro" | cut -d: -f8)
  opromedio=$(echo "$registro" | cut -d: -f9)

  echo "*** Solo captura aquellos datos que deseas modificar ***"
  echo -n "Nombre [$onombre]: "; read nombre
  echo -n "Apellidos [$oapellido]: "; read apellido
  echo -n "Carrera [$ocarrera]: "; read carrera
  echo -n "Semestre [$osemestre]: "; read semestre
  echo -n "Grupo [$ogrupo]: "; read grupo
  echo -n "Materia [$omateria]: "; read materia
  echo -n "Faltas [$ofaltas]: "; read faltas
  echo -n "Promedio [$opromedio]: "; read promedio

  bloqueo
  awk -F: -v llave="$uaaid" \
          -v nnombre="$nombre" \
          -v napellido="$apellido" \
          -v ncarrera="$carrera" \
          -v nsemestre="$semestre" \
          -v ngrupo="$grupo" \
          -v nmateria="$materia" \
          -v nfaltas="$faltas" \
          -v npromedio="$promedio" '
  ($1!=llave){print}
  ($1==llave){
    if(nnombre==""){nnombre=$2}
    if(napellido==""){napellido=$3}
    if(ncarrera==""){ncarrera=$4}
    if(nsemestre==""){nsemestre=$5}
    if(ngrupo==""){ngrupo=$6}
    if(nmateria==""){nmateria=$7}
    if(nfaltas==""){nfaltas=$8}
    if(npromedio==""){npromedio=$9}
    print llave":"nnombre":"napellido":"ncarrera":"nsemestre":"ngrupo":"nmateria":"nfaltas":"npromedio
  }
  ' "$DATA_FILE" > tmp.$$ \
    && mv -f tmp.$$ "$DATA_FILE"
  desbloqueo
  echo "${GREEN}¡Modificación guardada para UAA id $uaaid!${RESET}"
  else
   echo "${RED}¡El UAA id $uaaid no existe!${RESET}"
  fi
}

limpiar_pantalla(){
 clear
}

menu(){
 echo ""
 echo "${BOLD}======= Menu =======${RESET}"
 echo "${BLUE}1) Alta${RESET}"
 echo "${BLUE}2) Baja general${RESET}"
 echo "${BLUE}3) Baja por UAAID${RESET}"
 echo "${BLUE}4) Consulta general${RESET}"
 echo "${BLUE}5) Consulta por UAAID${RESET}"
 echo "${BLUE}6) Modificacion${RESET}"
 echo "${BLUE}7) Reportes${RESET}"
 echo "${BLUE}8) Limpiar terminal${RESET}"
 echo "${BLUE}S) Salir${RESET}"
 echo -n "Opción: "; read opcion
 case "$opcion" in
  1) alta ;;
  2) baja_general ;;
  3) baja_uaaid ;;
  4) consulta_general ;;
  5) consulta_uaaid ;;
  6) modificacion ;;
  7)
    echo "${BLUE}a) Por carrera${RESET}"
    echo "${BLUE}b) Reprobados${RESET}"
    echo -n "Tipo: "; read tipo
    case "$tipo" in
     a) reporte_carrera ;;
     b) reporte_reprobados ;;
     *) echo "${RED}¡Reporte inválido!${RESET}" ;;
    esac
    ;;
  8) limpiar_pantalla ;;
  [Ss]) echo ""
        echo "${BOLD}¡Hasta luego!${RESET}"; exit 0 ;;
  *) echo "${RED}¡Opción inválida!${RESET}" ;;
 esac
}


# Codigo principal
 opcion=0
 while true; do
  menu
 done
