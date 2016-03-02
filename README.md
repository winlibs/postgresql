# libpq

## Available prebuilt libraries

All prebuilt libraries are available in the php-libs
[repositories](http://windows.php.net/downloads/php-sdk/deps/)

# Building for PHP

## Requirements

  * postgres sources, fetch our patched [version](https://github.com/winlibs/) or the original [sources](http://www.postgresql.org)
  * Common tools used to compile PHP
  * openssl libs (optional)


## Compilation

	cd src
    nmake /f win32.mak USE_OPENSSL=1 SSL_INC=<ssl include> SSL_LIB_PATH=<ssl lib>
  
- for debug add DEBUG=1
- for x64 add CPU=AMD64
- openssl is optional at the time
