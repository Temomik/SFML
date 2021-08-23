@echo off

pushd .

echo ____prepare_for_buidling____
rm binary/app.exe 

cd scripts

echo ____buidling____
call  build.bat 

echo ____running____ 
call run.bat

popd
