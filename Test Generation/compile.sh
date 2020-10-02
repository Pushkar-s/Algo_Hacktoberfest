echo $"1 compiling gen.cpp"
g++ -std=c++11 -o gen gen.cpp -Wall
echo $"2 compiling a.cpp"
g++ -std=c++11 -o a a.cpp -Wall
echo $"3 compiling b.cpp"
g++ -std=c++11 -o brute brute.cpp -Wall
echo $"Testing.."
bash s.sh
