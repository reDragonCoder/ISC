# !/bin/bash
# Documentation

case $2 in
+) R=$(($1+$3));;
-) R=$(($1-$3));;
x) R=$(($1*$3));;
/) R=$(($1/$3));;
*) echo "Invalid operator";;
esac
echo "$R"
