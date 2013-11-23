RocksDB PHP Extension
===
RocksDB is a new embedded database for storing key-value pairs developed by Facebook. This project hosts a PHP extension for RocksDB. More information on RocksDB can be found here:

https://github.com/facebook/rocksdb

##Platforms
RocksDB is said to compile on Linux and Mac OS X. So far, I haven't seen anyone getting it to build on Windows, but it should work.
My build environment is:

* Ubuntu 13.10 x64
* GCC 4.8.1

All documentation, instructions and guides assume my configuration. If you were able to get it working on another platform, please let me know.

## Build
#### Building PHP
The RocksDB PHP extension is being written against PHP 5.5.6. To make debugging and development easier, it's best to build PHP from source. Download PHP 5.5.6 from here:

    wget -O php-5.5.6.tar.bz2 http://nl1.php.net/get/php-5.5.6.tar.bz2/from/this/mirror
    
After downloading, extract the archive and go into it:

    tar jxvf php-5.5.6.tar.bz2
    cd php-5.5.6
    
Because you might already have an existing installation of PHP, it's best to install it by using a custom prefix. In preperation, set PHPDIR to the current directory:

    PHPDIR=`pwd`
    
Now, choose a custom installation prefix. I choose 'php-debug-zts'. Create a directory named after your custom installation prefix:

    mkdir php-debug-zts
    
Configure PHP by running:

    ./configure --enable-debug --enable-maintainer-zts --prefix=$PHPDIR/php-debug-zts
    
Don't forget to replace 'php-debug-zts' with your installation prefix. After that's done, run:

    make install
    
That's it! Now, all you have to do, is to add PHP to your path, use the following command to add it to your path for
this session:

    PATH=$PHPDIR/php-debug-zts/bin:$PATH
    
#### Building RocksDB
To build the RocksDB PHP Extension, you first need to build RocksDB. Clone the RocksDB git repository using:

    git clone https://github.com/facebook/rocksdb.git
  
To be able to build RocksDB, you first need to install all dependencies, this can be done using apt-get:

    sudo apt-get install libsnappy-dev
    sudo apt-get install zlib1g-dev
    sudo apt-get install libbz2-dev
    
You'll also need gflags, which is a library for parsing command line flags. The following guide will help you to set it up:

    http://askubuntu.com/questions/312173/installing-gflags-12-04
    
After you've install all dependencies, you can simply run:

    make clean
    make
    
To build and run all unit tests:

    make check
    
To install the RocksDB library you can do either of these three things:

* Add the path where you cloned RocksDB to LD_LIBRARY_PATH (`export LD_LIBRARY_PATH+=/path/to/rocksdb`)
* Create a new file in `/etc/ld.so.conf.d` with the `.conf` extension, where the path to RocksDB is on a single line
* Copy the file `librocksdb.a` to `/usr/lib`

Choose whatever you like :)
