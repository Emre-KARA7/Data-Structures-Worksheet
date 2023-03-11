CompileAndRun:Program Run

Program:SatirListesi YoneticiListesi main Dugum
	g++ ./lib/Dugum.o ./lib/Satirlistesi.o ./lib/YoneticiListesi.o ./lib/main.o -o ./bin/program

SatirListesi:
	g++ -I "./include" -c ./src/SatirListesi.cpp -o ./lib/SatirListesi.o
Dugum:
	g++ -I "./include" -c ./src/Dugum.cpp -o ./lib/Dugum.o
YoneticiListesi:
	g++ -I "./include" -c ./src/YoneticiListesi.cpp -o ./lib/YoneticiListesi.o
main:
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o
Run:
	./bin/program.exe
