cd src

@RD /S /Q /build
@REM @RD /S /Q .cmake
@REM @RD /S /Q src/build

@REM cmake -Bbuilddir "build" -G "Ninja" -DCMAKE_BUILD_TYPE=Debug

cd build
ninja 
app.exe

