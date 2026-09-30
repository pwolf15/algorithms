# algorithms

Collection of solutions to various programming exercises.

# Build

``` bash
mkdir build
cmake --build ./build
```

# Run

* Run all tests (GoogleTest)

``` bash
./build/tests
```

* Run specific test

``` bash
./build/tests --gtest_filter='P0015*' # run only P0015 tests
```
