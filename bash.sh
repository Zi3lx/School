#! /bin/bash

nazwaPliku=$3

if [[ $nazwaPliku == *.tex ]]
then
    echo "\documentclass{article}" > $nazwaPliku
    echo "\begin{document}" >> $nazwaPliku

    ./1 4 2 >> $nazwaPliku
    echo "\end{document}" >> $nazwaPliku
fi

pdflatex $nazwaPliku
