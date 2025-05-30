#!/bin/bash

capture(){
 echo -n "Value a="; read A
 echo -n "Value b="; read B
 echo -n "Value c="; read C
}

discriminate(){
 D=$(echo "$2^2-4*$1*$3" | bc -lw)
}

roots(){
 echo "(-$2+sqrt($D))/(2*$1);(-$2-sqrt($D))/(2*$1)" | bc -lw
}

#Principal code
capture
discriminate $A $B $C
if [ $D -ge 0 ]
then
 roots $A $B $C
else
 echo "There is no roots, only imaginary"
fi
