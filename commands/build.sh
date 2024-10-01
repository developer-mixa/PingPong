rm -rf ./build
mkdir -p ./build
g++ -c src/main.cpp -o build/main.o
g++ build/main.o -o build/sfml-app -lsfml-graphics -lsfml-window -lsfml-system
./build/sfml-app