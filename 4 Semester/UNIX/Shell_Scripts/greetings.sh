# !/usr/bin/env bash
# Objective: greeat the user based on its age
# Use: bash greetings.sh

echo "What is your name?"
read NAME
echo "What is your age?"
read AGE

if test $AGE -le 2; then
 echo "Hi $NAME, you are a baby!"
elif test $AGE -le 11; then
 echo "Hi $NAME, you are a kid!"
elif test $AGE -le 17; then
 echo "Hi $NAME, you are a teenager!"
elif test $AGE -le 35; then
 echo "Hi $NAME, you are a young adult!"
elif test $AGE -le 59; then
 echo "Hi $NAME, you are an adult!"
else
 echo "Hi $NAME, you are a grown adult!"
fi
