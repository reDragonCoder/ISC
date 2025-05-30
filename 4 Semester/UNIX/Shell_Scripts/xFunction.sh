# !/bin/bash

evaluate(){
 echo "x=$1; $2" | bc -lw
}

#Principal code
evaluate "$1" "$2"
