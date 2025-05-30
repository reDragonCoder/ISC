# !/bin/bash

add(){
bc -lw <<FIN
$1+$2
FIN
}

substract(){
bc -lw <<FIN
$1-$2
FIN
}

multiplicate(){
bc -lw <<FIN
$1*$2
FIN
}

divide(){
bc -lw <<FIN
$1/$2
FIN
}

case $2 in
+) add $1 $3;;
-) substract $1 $3;;
x) multiplicate $1 $3;;
/) divide $1 $3;;
*) echo "Invalid operator";;
esac
