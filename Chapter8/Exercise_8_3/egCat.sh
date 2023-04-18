gcc -I./ -o myCat_v2 myCat_v2.c _myflushbuf.c _myfillbuf.c myFopen.c

echo -e "Hello darkness, my old friend" | ./myCat_v2

./myCat_v2 A_Tale_of_Two_Cities.txt
