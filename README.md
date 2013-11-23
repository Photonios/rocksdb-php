RocksDB PHP Extension
===
RocksDB is a new embedded database for storing key-value pairs developed by Facebook. This project hosts a PHP extension for RocksDB. More information on RocksDB can be found here:

https://github.com/facebook/rocksdb

Build
--
##### Building RocksDB
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
