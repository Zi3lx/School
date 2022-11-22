#! /bin/bash

echo "\title{Permutacje}" > plik.tex
echo "\documentclass{article}" >> plik.tex
echo "\begin{document}" >> plik.tex
echo "\author{ja}" >> plik.tex

a=0
all=A

args=( "$@" )

for (( i=0;i<${args[0]};i++ ))
do
    echo "\maketitle" >> plik.tex
    echo "\section{Rozdzial $(($a+1))}" >> plik.tex   
    
    z=`expr $a \* 2`
    y=`expr $a \* 2`

    z1=$((1+$z))
    y1=$((2+$y))

    ./1 ${args[${z1}]} ${args[${y1}]} >> plik.tex

    a=$((a+1)) 

    echo "\newpage" >> plik.tex
done

echo "\end{document}" >> plik.tex

pdflatex plik.tex
