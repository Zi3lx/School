#! /bin/bash

nazwaPliku=$2

echo "\documentclass{article}" > $nazwaPliku
echo "\begin{document}" >> $nazwaPliku

for i in {1..$1}
do
    ./1 5 A 12 12 17 7 >> $nazwaPliku
done

echo "\end{document}" >> $nazwaPliku


pdflatex $nazwaPliku
