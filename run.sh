if [[ -d "./build" ]]; then
  cd build 
  cmake clear ../
else
	mkdir build
  cd build
fi

cmake ../
make 
pwd

echo -e "\n \nUruchamianie programu \n \n"

sleep 1

if [ "$1" == "-v" ]; then
    valgrind ./projekt_1
else
    ./projekt_1
fi 
