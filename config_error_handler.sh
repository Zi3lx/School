#!/bin/bash

config_file="$1"
max_set_size="$2"

#config file doesn't exist
if [ ! -f "$config_file" ]; then
  echo error_file_does_not_exist
  exit 
fi

#number of lines < 2
number_of_lines=$(wc -l "$config_file" | awk '{print $1}')
if ((number_of_lines<2)); then
  echo error_input_incomplete
  exit
fi

declared_number_of_lines=$(head -n 1 "$config_file")

#declared_number_of_lines is not a valid number

if ! [[ $declared_number_of_lines =~ ^[0-9]+$ ]] ; then
  echo error_not_a_valid_number
  exit
fi


#awk 'NR==1' "$config_file"


#syntax error: $current_line doesn't match regex [0-9A]+\s[0-9]+  
counter=0
for ((i=2;i<=declared_number_of_lines;i++)); do
  current_line="$(awk "NR==$i" "$config_file")"
  if ! [[ "$current_line" =~ [0-9]+\s[0-9A]+ ]] ; then
    echo error_syntax_error
    exit
  fi
  set_size="$(echo $current_line | awk '{print $1;}')"
  if ((set_size>max_set_size)); then
    echo error_set_too_big
    exit
  fi

  ((counter++))
done

# $declared_number_of_lines doesn't match

if ((counter!=declared_number_of_lines)); then
  echo error_lines_dont_match
  exit
fi


