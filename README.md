# Cpp_tools

## sort_files

sort_files program sorts image and movie files to quarter folders

Description:
```text
BEFORE:
/resources
    /image_0.jpg (created at: April 2020 / q2)
    /image_1.JPG (created at: May 2019 / q2)
    /image_2.png (created at: January 2020 / q1)
    /movie_0.MOV (created at: January 2018 / q1)
    /movie_1.mp4 (created at: December 2017 / q4)

AFTER:
(file names are transformed to lowercase)
/resources
    /photos
        /2019/2/image_1.jpg
        /2020/1/image_2.png
        /2020/2/image_0.jpg
    /movies
        /2017/4/movie_1.mp4
        /2018/1/movie_0.mov
```
Usage:
```text
[slawtul@localhost family]$ ./sort_files
program: sort_files
please confirm you want to run it inside "/home/slawtul/family" [y/n]

```
Download:
```text
Cpp_tools/bin/linux/sort_files
```
* linux binary compiled with (gcc version 9.3.1 20200408 (Red Hat 9.3.1-2) (GCC) on x86_64 platform)