# libpq

## Available prebuilt libraries

All prebuilt libraries are available in the php-libs
[repositories](http://windows.php.net/downloads/php-sdk/deps/)

# Building for PHP

## Requirements

  * postgres sources, fetch our patched [version](https://github.com/winlibs/) or the original [sources](http://www.postgresql.org)
  * Common tools used to compile PHP
  * openssl libs


## Compilation

    cd src\interfaces\libpq
    nmake /f win32.mak USE_OPENSSL=1 SSL_INC=<ssl include> SSL_LIB_PATH=<ssl lib>
  
- for debug add `DEBUG=1`
- for x64 add `CPU=AMD64`
- for vc11 (PHP 5.6) builds **only**, add `NOCFG=1`

# Updating postgresql

- Download the respective source package from https://www.postgresql.org/ftp/source/
- Replace all files in the repo except README.md and postgresql-9.6.patch with the downloaded sources
- `cd src\tools\msvc`
- run `build libpq` in x86 and x64 environment (requires Perl), and compare src\include\pg_config.h.win32 with the generated src\include\pg_config.h, and update the former accordingly.
