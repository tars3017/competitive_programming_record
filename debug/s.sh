for((i = 1; i <= 1000; ++i)); do
    echo $i
    ./gen $i > int
    ./a.out < int > out1
    ./ac.out < int > out2
    diff -w out1 out2 || break
done
