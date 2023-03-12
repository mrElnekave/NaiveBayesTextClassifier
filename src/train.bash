cat ../data/Authors/$1.txt | ./cleanup_scripts/all_clean_ups.bash | ./train_model.exe -Author=$1
