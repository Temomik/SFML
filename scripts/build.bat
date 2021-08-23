@echo off

pushd .

cd ../

g++ ^
    source\main.cpp ^
    source\shapes\Circle.cpp ^
    source\shapes\Dot.cpp ^
    source\shapes\Line.cpp ^
    source\shapes\rectangle.cpp ^
    source\shapes\ShapeObject.cpp ^
    source\Utils\Collisions.cpp ^
-I SFML\include ^
-I source\shapes ^
-I source\Utils ^
-I source ^
-o binary\app.exe ^
-L SFML\lib ^
-lsfml-graphics -lsfml-window -lsfml-system ^
-std=c++17 

popd
