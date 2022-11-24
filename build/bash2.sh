#! /bin/bash

echo "\title{Permutacje}" > plik.tex
echo "\documentclass{article}" >> plik.tex
echo "\begin{document}" >> plik.tex
echo "\author{JAJJAJAJAJ}" >> plik.tex
echo "\maketitle" >> plik.tex

a=0
all=A

args=( "$@" )

for (( i=0;i<${args[0]};i++ ))
do

    echo "\section{Rozdzial $(($a+1))}" >> plik.tex   
    
    z=`expr $a \* 2`
    y=`expr $a \* 2`

    z1=$((1+$z))
    y1=$((2+$y))

    echo "\begin{center}" >> plik.tex
    echo "\begin{longtable}{|r|}" >> plik.tex
    echo "\hline" >> plik.tex
    ./1 ${args[${z1}]} ${args[${y1}]} >> plik.tex
    echo "\end{longtable}" >> plik.tex
    echo "\end{center}" >> plik.tex

    a=$((a+1)) 

    echo "\newpage" >> plik.tex
done

echo "\end{document}" >> plik.tex

pdflatex plik.tex
