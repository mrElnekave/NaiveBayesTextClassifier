cat ./data/Authors/$1.txt | ./cleanup_scripts/new_lines_to_spaces.bash | ./train.exe -Author=$1