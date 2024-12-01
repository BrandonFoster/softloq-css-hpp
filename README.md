[![Unit-Testing](https://github.com/BrandonFoster/softloq-css-hpp/actions/workflows/testing.yml/badge.svg)](https://github.com/BrandonFoster/softloq-css-hpp/actions/workflows/testing.yml) [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
### Softloq CSS Version 1.0.0
# About
[Documentation](https://brandonfoster.github.io/softloq-css-hpp/)

Softloq Software C++ headers for CSS (Cascading Style Sheets).

Features:
- Converts CSS from a string to a modifiable C++ object and vice-versa.
- CSS Tokenizer.
- CSS Parser.

# Usage Example
W.i.P.


# CMake Build
## Options
* BUILD_SHARED_LIBS [ON/OFF]:

    Controls building source as shared or static library files.
    
    Default: OFF.
* SOFTLOQ_CSS_BUILD_TESTING [ON/OFF]:

    Controls building unit-testing.
    
    Default: OFF.
* SOFTLOQ_CSS_MONOLITHIC_BUILD [ON/OFF]:

    Controls building everything in one unit.
    
    Default: OFF.

# Running Tests
## Targets
### softloq-css-macros-test
Runs unit-tests on softloq-css/macros.hpp header file.

Source Files:
- tests/css_macros_test.cpp

### softloq-css-token-test
Runs unit-tests on softloq-css/token.hpp header file.

Source Files:
- tests/css_token_test.cpp

### softloq-css-tokenizer-test
Runs unit-tests on softloq-css/tokenizer.hpp header file.

Source Files:
- tests/css_tokenizer_test.cpp

### softloq-css-parser-test
Runs unit-tests on softloq-css/parser.hpp header file.

Source Files:
- tests/css_parser_test.cpp

## Building
Set the CMake option SOFTLOQ_CSS_BUILD_TESTING to ON.

The targets will be built to their respective output folder.
