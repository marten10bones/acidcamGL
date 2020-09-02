#!/bin/sh

make clean && make -j16 && cp ./acidcamGL /Applications/acidcamGL/acidcamGL.app/Contents/MacOS/acidcamGL 
install_name_tool -change @loader_path/../Frameworks/Syphon.framework/Versions/A/Syphon  @executable_path/../Frameworks/Syphon.framework/Versions/A/Syphon  /Applications/acidcamGL/acidcamGL.app/Contents/MacOS/acidcamGL && open /Applications/acidcamGL/acidcamGL.app --args -g -p /Applications/acidcamGL/filters
cp acidcamGL /usr/local/bin
