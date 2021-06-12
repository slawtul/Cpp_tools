# Cpp_tools

> _No boundaries, no limits, no compromises. That’s C++_

## sort_files

sort_files program sorts image and movie files to quarter folders

Description:

```text
BEFORE:
/family
    /image_0.jpg (created at: April 2020 / q2)
    /image_1.JPG (created at: May 2019 / q2)
    /image_2.png (created at: January 2020 / q1)
    /movie_0.MOV (created at: January 2018 / q1)
    /movie_1.mp4 (created at: December 2017 / q4)

AFTER:
(file names are transformed to lowercase)
/family
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
Run ./sort_files program inside folder
[Pictures]$ ./sort_files
```

Example output:

```text
[slawtul@localhost family]$ ./sort_files
program: sort_files
please confirm you want to run it inside "/home/slawtul/family" [y/n]
y

"/home/slawtul/family/photos/20190818.jpg"     2020, May       quarter: 2
"/home/slawtul/family/photos/20200607.jpg"     2020, June      quarter: 2
"/home/slawtul/family/photos/87020825.jpg"     2020, February  quarter: 1
"/home/slawtul/family/photos/8809128n.jpg"     2020, February  quarter: 1
"/home/slawtul/family/photos/20200410.jpg"     2020, April     quarter: 2
"/home/slawtul/family/photos/8757283n.jpg"     2020, February  quarter: 1
"/home/slawtul/family/photos/874311_n.jpg"     2020, February  quarter: 1
"/home/slawtul/family/photos/8749533n.jpg"     2020, February  quarter: 1
"/home/slawtul/family/photos/851830_n.jpg"     2020, February  quarter: 1

found files: 9
exec time [ms]: 0
```

### How to build and run

```bash
cd sort_files
meson build
ninja
./sort_files
```
