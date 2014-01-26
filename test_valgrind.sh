#!/bin/bash

export USE_ZEND_ALLOC=0
export ZEND_DONT_UNLOAD_MODULES=1
valgrind --tool=memcheck --leak-check=full --num-callers=30 php test/test.php

