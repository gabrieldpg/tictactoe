Main.exe		: 	Main.o TicTacToe.o 
	g++ -O2 -std=c++11  -Wl,-s -o Main.exe Main.o TicTacToe.o -l gdi32 -static-libgcc -static-libstdc++	
	
Main.o		:	 Main.cpp TicTacToe.h
	g++ -O2  -std=c++11  -c -fpermissive -fconserve-space  -Wno-write-strings Main.cpp		

TicTacToe.o		:	 TicTacToe.cpp TicTacToe.h
	g++ -O2  -std=c++11  -c -fpermissive -fconserve-space -Wno-write-strings  TicTacToe.cpp
	
clean:
	del *.o
	del *.exe
