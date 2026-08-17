



[Rule of three/file/zero](https://en.cppreference.com/cpp/language/rule_of_three)

> Because C++ copies and copy-assigns objects of user-defined types in various situations (passing/returning by value, manipulating a container, etc), these special member functions will be called, if accessible, and if they are not user-defined, they are implicitly-defined by the compiler.

> The implicitly-defined special member functions should not be used if the class manages a resource whose handle is an object of non-class type (raw pointer, POSIX file descriptor, etc), whose destructor does nothing and copy constructor/assignment operator performs a "shallow copy" (copies the value of the handle, without duplicating the underlying resource).

ユーザ定義のデストラクタ，コピーコンストラクタ，コピー代入演算子が存在すると，ムーブコンストラクタとムーブ代入演算しの暗黙定義が阻害されてムーブが静かに消えてコピーにフォールバックする
https://accu.org/conf-docs/PDFs_2014/Howard_Hinnant_Accu_2014.pdf
