echo "launching make in srcs..."
cd srcs
make re
cd ../
echo "copy of libasm.a in current directory"
cp srcs/libasm.a .
echo "compilation..."
clang -Wall -Wextra -Werror test.c libasm.a -o tests
