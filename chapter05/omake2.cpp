/*

$ g++ omake2.cpp -o p -std=c++17
-> 何もエラーなし



$ g++ omake2.cpp -o p -std=c++20 //コンパイルエラー
omake2.cpp: In function ‘int main()’:
omake2.cpp:11:13: error: no matching function for call to ‘X::X(<brace-enclosed initializer list>)’
   11 |     X x{1, 2};
      |             ^
omake2.cpp:6:5: note: candidate: ‘X::X(const X&)’ (deleted)
    6 |     X(const X&) = delete;             // または = default
      |     ^
omake2.cpp:6:5: note:   candidate expects 1 argument, 2 provided
omake2.cpp:12:9: error: no matching function for call to ‘X::X(<brace-enclosed initializer list>)’
   12 |     X y{};
      |         ^
omake2.cpp:6:5: note: candidate: ‘X::X(const X&)’ (deleted)
    6 |     X(const X&) = delete;             // または = default
      |     ^
omake2.cpp:6:5: note:   candidate expects 1 argument, 0 provided



*/


struct X {
    int a;
    int b;
    X(const X&) = delete;             // または = default
    X& operator=(const X&) = delete;
};

int main(){
    X x{1, 2};
    X y{};
}
