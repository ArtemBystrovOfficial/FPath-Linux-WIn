# FPath-Linux-Win
Easy work with Fstream, filesystem etc.pathes on all platforms.

## About
🚀 Fast find your files at bash or you can use lib in c++ project( for fstream or filesystem)
`FPath.lib` `FPath.h`(try find this files use, after install repositry) 

## For what
📝 Programm make smart analysis for find all path to some file, now you must'nt write and remind full pathes in your projects

## Install
_________

```console
git clone https://github.com/ArtemBystrovOfficial/FPath-Linux-WIn ./FPath
sudo ln -s $PWD/FPath/build/bin/fpath /usr/bin
fpath -h
```
_________
## How use
use command in bash <br/>
`fpath [FLAG] ROOT_PATH FILE_SEARCHED ARGUMENTS...`
- FLAG `-s` -> if you must use accurate way you can put in arguments directiories before file 
  - Example : `fpath -s /home/artem main.cpp Project_x Debug`
  - Output  : `/home/artem/Desktop/repos/Projcet_x/Debug/main.cpp`
- You must use Arguments when file not only one in search space, if programm find too or you make doesn't true arguments, she said that
- Without flag `-s` Arguments work with any directiores on way. if this directory or some directory unique for situation, programm return path to file

### You can help for developed this kit, and add some smart functions
