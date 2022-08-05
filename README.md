# opengl_codes

basic setup for Debian based OS
```console
# generic opengl implementation
sudo apt-get install mesa-utils 

# to create and manage windows
sudo apt-get install freeglut3-dev 
```
---

## building and running programmes

For most of the programmes in this repo you can follow this syntax it compiles the c code and links it with the necessary libraries.
```
gcc  program_file_name.c -lglut -lGL -lGLU -lm  -o output_file_name.out && ./output_file_name.out
```

for example to run [dda line drawing program](https://github.com/Omkar76/opengl_codes/tree/main/dda_line_drawing) you can write.
```
gcc  dda.c -lglut -lGL -lGLU -lm  -o dda.out && ./dda.out
```

---

# Contributing
if you find any bug let me know by opening an issue. 
Currently builds are not automated. If you know how to use cmake consider adding a PR for the same because IDK how to use cmake yet :eyes:
