#! /bin/bash



config_file="$1"

config_error=$(./config_error_handler.sh "$config_file" 100)

if ! [ -z "${config_error}" ]; then
	echo $config_error
	exit 1
fi


declared_number_of_lines=$(head -n 1 "$config_file")

cat header.tex > generated_file.tex
for ((i=2;i<=declared_number_of_lines+1;i++)); do
  current_line="$(awk "NR==$i" "$config_file")"
   echo "\section{Operation \"$current_line\"}" >> generated_file.tex
   echo "" >> generated_file.tex
  ./generator_main $current_line |
    while IFS= read -r line
    do
    		operation=$(echo "$line" | cut -f 1 -d ":")
    		result=$(echo "$line" | cut -f2- -d " ")
    		#echo "$operation" >> generated_file.tex
    		#echo "\hline" >> generated_file.tex
    		
    		#echo "$result" >> generated_file.tex
    		
        if [[ $operation = "PERMUTATION" ]]; then
        	echo "\subsection{$result}" >> generated_file.tex
        	echo "" >> generated_file.tex
        elif [[ $operation = "NEXT" ]]; then
        	echo "\subsubsection{Next permutation:}" >> generated_file.tex
        	echo "" >> generated_file.tex
        	echo "$result" >> generated_file.tex
        elif [[ $operation = "PREV" ]]; then
        	echo "\subsubsection{Previous permutation:}" >> generated_file.tex
        	echo "" >> generated_file.tex
        	echo "$result" >> generated_file.tex
        elif [[ $operation = "INVERSIONS" ]]; then
        	echo "\subsubsection{Number of inversions in permutation:}" >> generated_file.tex
        	echo "" >> generated_file.tex
        	echo "$result" >> generated_file.tex
        elif [[ $operation = "IS_EVEN" ]]; then
        	if ((result==1)); then
        		echo "\subsubsection{The permutation is even}" >> generated_file.tex
        	else
        		echo "\subsubsection{The permutation is odd}" >> generated_file.tex
        	fi
        	echo "" >> generated_file.tex
        	echo "" >> generated_file.tex
        fi
        
    done
done
echo "\end{document}" >> generated_file.tex

pdflatex generated_file.tex
evince generated_file.pdf &
