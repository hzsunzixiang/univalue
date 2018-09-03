CURDIR=`pwd`
DIR=`pwd`


find -L $DIR/gen  $DIR/lib $DIR/lib $DIR/test $DIR/include -name "*.hpp" -o -name "*.h" -o -name "*.cpp" -o -name "*.c" > cscope_my.files

cscope -bkq -i cscope_my.files  -f cscope_my.out

for i in $DIR/gen  $DIR/lib $DIR/lib $DIR/test $DIR/include  
do 
	cp .vimrc	$i/
done


