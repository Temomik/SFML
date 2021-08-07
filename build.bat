@REM g++ -c circle.cpp -I SFML/include
@REM g++ -o circle circle.o -L SFML/lib -lsfml-graphics -lsfml-window -lsfml-system 

g++ circle.cpp -o binary/app.exe -I SFML/include -L SFML/lib -lsfml-graphics -lsfml-window -lsfml-system 
