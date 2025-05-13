# !/usr/bin/env bash
# Documentacion

R=1
while test $R = "1"
do

echo -n "Como te llamas: "; read NOM
echo -n "$NOM, que te gusta tomar: "; read BEBIDA

case $BEBIDA in
tequila|TEQUILA|Tequila) NT=$(($NT+1));;
cerveza|chela|cheve) NC=$(($NC+1));;
whisky|WHISKY|Whisky) NW=$(($NW+1));;
ron|RON|Ron) NR=$(($NR+1));;
*) NI=$(($NI+1));;
esac

echo -n "Repito (0,1)"; read R
done

echo "Tequilas: $NT"
echo "Cervezas: $NC"
echo "Whiskies: $NW"
echo "Rones: $NR"
echo "No identificado: $NI"
