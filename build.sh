#!/bin/bash
curdir=$(pwd)

# Install via ./configure ...

#sudo apt-get install build-essential nghttp2 libnghttp2-dev libssl-dev
#wget https://curl.haxx.se/download/curl-7.58.0.tar.gz
#tar -xvf curl-7.58.0.tar.gz
#cd curl-7.58.0
#./configure --with-nghttp2 --prefix=/usr/local --with-ssl=/usr/local/ssl
#make
#make install

# https://curl.haxx.se/docs/todo.html#hardcode_the_localhost_address
# 1.27 hardcode the "localhost" addresses

mkdir -p $curdir/depends
cd $curdir/depends

# https://github.com/alexa/avs-device-sdk/wiki/Optimize-libcurl

git clone https://github.com/curl/curl
mkdir -p curl-build
cd curl-build
cmake ../curl -DCURL_STATICLIB:BOOL=ON -DCURL_STATIC_CRT:BOOL=ON -DHTTP_ONLY:BOOL=ON -DENABLE_IPV6:BOOL=OFF -DCMAKE_INSTALL_PREFIX=$curdir 
cmake ../curl -LA > $curdir/options.txt
make -j$(nproc)
make install
cd $curdir

make -f curltest_tfo.cbp.mak 


