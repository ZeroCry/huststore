sudo yum install -y libidn-devel openssl-devel

rm -fr curl-curl-7_50_2
tar -zxvf curl-curl-7_50_2.tar.gz
cd curl-curl-7_50_2
./buildconf
./configure --prefix=${prefix_3rd} --disable-ldap --disable-ldaps
make -j`nproc`
sudo make install
cd ..

