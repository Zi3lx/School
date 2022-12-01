#!/bin/bash

config_file="$1"
max_set_size="$2"

#config file doesn't exist
if [ ! -f "$config_file" ]; then
  echo "Error: file doesn't exist"
  exit 
fi

#number of lines < 2
number_of_lines=$(wc -l "$config_file" | awk '{print $1}')
if ((number_of_lines<2)); then
  echo "Error: input incomplete"
  exit
fi

declared_number_of_lines=$(head -n 1 "$config_file")

#declared_number_of_lines is not a valid number

if ! [[ $declared_number_of_lines =~ ^[0-9]+$ ]] ; then
  echo "Error in line 1: not a valid number"
  exit
fi


#awk 'NR==1' "$config_file"


#syntax error: $current_line doesn't match regex [0-9A]+\s[0-9]+  
counter=0
for ((i=2;i<=declared_number_of_lines+1;i++)); do
  current_line="$(awk "NR==$i" "$config_file")"
  if ! [[ "$current_line" =~ [0-9]+' '[0-9A]+ ]] ; then
    echo "Error in line $i: syntax error"
    exit
  fi
  set_size="$(echo $current_line | awk '{print $1;}')"
  if ((set_size>max_set_size)); then
    echo "Error in line $i: set size is higher than the maximum set limit($max_set_size)"
    exit
  fi

  ((counter++))
done

# $declared_number_of_lines doesn't match

if ((counter!=declared_number_of_lines)); then
  echo "Error: declared number of parameters doesn't match. Expected: $declared_number_of_lines. Got: $counter"
  exit
fi


