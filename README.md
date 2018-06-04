### What's this?

This repo is for test `curl` connection with Komodo daemon in two variants:

- 1000 sequential requests `getblock 1..1000` with keep-alive connection (pipelined)
- 1000 sequential requests `getblock 1..1000` with new connection

Change username and password in `main.c` to credentials from your `komodo.conf`, build all of this using `build.sh` in the root of repo, with `#define RECONNECT 1` enabled in `stuff.c` each connection will be new, if you comment this string `// #define RECONNECT 1` and rebuild test - connections will be pipelined (keep-alive).

Example of obvious connection:

	* Rebuilt URL to: http://localhost:7771/
	*   Trying 127.0.0.1...
	* Connected to localhost (127.0.0.1) port 7771 (#0)
	* Server auth using Basic with user '< hidden >'
	> POST / HTTP/1.1
	Host: localhost:7771
	Authorization: Basic '< hidden >'
	Accept: */*
	Content-Length: 78
	Content-Type: application/x-www-form-urlencoded
	
	* upload completely sent off: 78 out of 78 bytes
	< HTTP/1.1 200 OK
	< Content-Type: application/json
	< Date: Mon, 04 Jun 2018 09:41:31 GMT
	< Content-Length: 3616
	< 
	* Connection #0 to host localhost left intact
	Result: {"result":{"hash":"01bda24269891b625a95bfa494cadb123f5e10e154414d811881566afec174a4","confirmations":862851,"size":1588,"height":1000,"version":4,"merkleroot":"27a2e3c66304c8bfac1a54d52a5c9218e71f31854c32b2bb2667588a222adf3a","tx":["27a2e3c66304c8bfac1a54d52a5c9218e71f31854c32b2bb2667588a222adf3a"],"time":1474060357,"nonce":"00009f5772f039946a809b1df27cc42c55bc7462172ce84951115ebbb5bb0001","solution":"000be099b10a9790d78ed36934575d3a4238bf279302b9332a03d0c0e98610f3169c4ae629e8441593720ad6eb8d7c8733c84d7fa65134e2f0fe3ebb78eb1b103f92fc5ae81a87ac3076988245e59ec4361c5a130c7fcd61b91a77cba6032172e1baadb9f113df565912a5cd5ae75521bddaf45184df2b1584b5c9ff05ce17336bf5926ca9a58b2f2646d9f049624a9e16924b1bf299d6529ce00b9a54740a1fa8379d8b492ffc78006bdcd3a31a5d0f88232406dc52212e8f17f6e5b90f66cbd408ee3c43e3f212e413696c54d39389b7ba01e6e483ce6f0795a7fa032b106e88a6b4107d303433082c85da933bef2654d7ac505908627e30d7ee7c06b664cfb1486f3ef13791db875705a7d55cdfc4652a0d06c4a8d22848be0d4329a17fac00ccb96da29c0ae28c2f94a5c83f37067172cae7d69e946bbb272c1fb30af00478cd75d630750deb75d3bd6bc99107c509812999a093f7ab2599414f4c2731e9346e8c8f3542fc0301251b2ea534f195345d6dd265579d3507ea0dcd8409cf92ad4dddda635fa79d15e124279202a21c892d674d27b611d909021b8eae0a2a63a5bf4ebd0fe32abf4417a9e5e45eb29c3b5311e689a219b6be1a81ebdcec66766bd873441411f140b11f65c95894196fd51ff59b975f071984032ddbb512d4d41bae1c2c0f59aaf6e3619f213c661679e67e2de6751381880a5ee15d2986228bda6a529e0c4470f5139670b1091f452d5e3a53119ba70fa3adaf3a83093a457e4c5b0d40a0cfcf4fdcb3b67fc28ad8fd4d0a2687dfe55a1609adb9a38c38e70565e3726f42e217b8105f2e611a7c1ad63a737e21f535b63374f0fb21ce3fdff9695378db79f29af8591b3766f0963e6c7dce97ef40742fc4076be9e107d150f264a3254cccef3df27eae6237deb36ccf9410b32e556548394bb216d445bbde2f00dd5e81e142400e6b41330c55b8a32966c855d1e120c75b1b32c954aae53a043bcfacb02110ec2aae140359916de493ba27a38331132d6ca82ab8193c2bba13f32724085658cd502a66dbc85afec6b7dc1b539707c6d1d07b9fc9e7cddf7267017794cbb0fdde195c2b915d81f11e85252253e455eb66076f22ae7c64c115e06b9b4d5bb4df30d6537b7772a506e71bdd07e62fdcf6a72d952e82fc67e404f7bfafc5a74afc101001016df15964c16f6c2c75b01a7600b29428f8f0b0504ec2f19623210b466488fcbdfdf00f1cf7fc0de72942bc3280162df3fb1649dc2d6cf9367936f7bc9d2dec5d91bff63c4be9e40499c6578c6e1deb946fec05a9efc9a44696eb4a3c525c1440f5f1001c9ff2e907149a84df51a807a87c035d55ef36d9ec2cd371a629c5b4d0b710e60bd4df97b14bc85901ef6d75c7d23243cd70e857340d0d78649fa950a556118216206f021211414af280abf71b21b8253907e6cb673c1b782fe0027ff8e0306d1493b4e7c558f1826f66d41ca50b886ade88cb7427446f2497d0b94ce53ca6ffb63f2aa86c3b610c0286ebfb9d9391f1678b9dcd1dafaa088b6a29a165619faac974e6c24c5a1281e73cb8a93ccba60cd6922549ae344684d43c3b3637f8dc32a31178f698d90a7281c793a3020e538ebcc4aef689384957fded05d58ae8d44205fcb960d515874b924a120edfea84a0fcddc1ecad120f34ad96d9435ffab00511fe4a7e47454ab679b6b2e8ccc9cba572fb3177c4213c1f7f66efb9a5a6dc9488c6de0d2e3dd7b394b12a2a4afd620b2fe2cd5cc5fb34417839e6bf1efebc1374b53ce927fdad6187d3dff2ab42adfc6253afe0219e2d9da98cf4e1b24f024c526bd469d7ad18df4f1a18fe13b0a1baf52cd6e4c927b96e0b152e197fd6462106e54c91c0c16f6ae722b9fc938e6881994e6a","bits":"200f0f0f","difficulty":1,"chainwork":"0000000000000000000000000000000000000000000000000000000000004279","anchor":"59d2cde5e65c1414c32ba54f0fe4bdb3d67618125286e6a191317917c812c6d7","valuePools":[{"id":"sprout","monitored":true,"chainValue":0.00000000,"chainValueZat":0,"valueDelta":0.00000000,"valueDeltaZat":0}],"previousblockhash":"043daeb9276c4fb9176f95d043567e18d40bff3aff114f551b950ee48c75ca02","nextblockhash":"06bc7098c8df18403af23dcb7147f58a0af031a1853a686a1964eb16b48ce509"},"error":null,"id":"curltest"}
	Total time = 5.759622 seconds
	
In this case ` curl = curl_easy_init()` calls each time before request and `curl_easy_cleanup(curl)` - before end request. these calls tooks time, as you are see ` 5.759622 seconds` spent here on 1000 requests.

Example of keep-alive (pipelined) connection:

	* Rebuilt URL to: http://localhost:7771/
	* Found bundle for host localhost: 0xe9c2a0 [can pipeline]
	* Re-using existing connection! (#0) with host localhost
	* Connected to localhost (127.0.0.1) port 7771 (#0)
	* Server auth using Basic with user '< hidden >'
	> POST / HTTP/1.1
	Host: localhost:7771
	Authorization: Basic '< hidden >'
	Accept: */*
	Content-Length: 78
	Content-Type: application/x-www-form-urlencoded
	
	* upload completely sent off: 78 out of 78 bytes
	< HTTP/1.1 200 OK
	< Content-Type: application/json
	< Date: Mon, 04 Jun 2018 09:45:01 GMT
	< Content-Length: 3616
	< 
	* Connection #0 to host localhost left intact
	Result: {"result":{"hash":"01bda24269891b625a95bfa494cadb123f5e10e154414d811881566afec174a4","confirmations":862855,"size":1588,"height":1000,"version":4,"merkleroot":"27a2e3c66304c8bfac1a54d52a5c9218e71f31854c32b2bb2667588a222adf3a","tx":["27a2e3c66304c8bfac1a54d52a5c9218e71f31854c32b2bb2667588a222adf3a"],"time":1474060357,"nonce":"00009f5772f039946a809b1df27cc42c55bc7462172ce84951115ebbb5bb0001","solution":"000be099b10a9790d78ed36934575d3a4238bf279302b9332a03d0c0e98610f3169c4ae629e8441593720ad6eb8d7c8733c84d7fa65134e2f0fe3ebb78eb1b103f92fc5ae81a87ac3076988245e59ec4361c5a130c7fcd61b91a77cba6032172e1baadb9f113df565912a5cd5ae75521bddaf45184df2b1584b5c9ff05ce17336bf5926ca9a58b2f2646d9f049624a9e16924b1bf299d6529ce00b9a54740a1fa8379d8b492ffc78006bdcd3a31a5d0f88232406dc52212e8f17f6e5b90f66cbd408ee3c43e3f212e413696c54d39389b7ba01e6e483ce6f0795a7fa032b106e88a6b4107d303433082c85da933bef2654d7ac505908627e30d7ee7c06b664cfb1486f3ef13791db875705a7d55cdfc4652a0d06c4a8d22848be0d4329a17fac00ccb96da29c0ae28c2f94a5c83f37067172cae7d69e946bbb272c1fb30af00478cd75d630750deb75d3bd6bc99107c509812999a093f7ab2599414f4c2731e9346e8c8f3542fc0301251b2ea534f195345d6dd265579d3507ea0dcd8409cf92ad4dddda635fa79d15e124279202a21c892d674d27b611d909021b8eae0a2a63a5bf4ebd0fe32abf4417a9e5e45eb29c3b5311e689a219b6be1a81ebdcec66766bd873441411f140b11f65c95894196fd51ff59b975f071984032ddbb512d4d41bae1c2c0f59aaf6e3619f213c661679e67e2de6751381880a5ee15d2986228bda6a529e0c4470f5139670b1091f452d5e3a53119ba70fa3adaf3a83093a457e4c5b0d40a0cfcf4fdcb3b67fc28ad8fd4d0a2687dfe55a1609adb9a38c38e70565e3726f42e217b8105f2e611a7c1ad63a737e21f535b63374f0fb21ce3fdff9695378db79f29af8591b3766f0963e6c7dce97ef40742fc4076be9e107d150f264a3254cccef3df27eae6237deb36ccf9410b32e556548394bb216d445bbde2f00dd5e81e142400e6b41330c55b8a32966c855d1e120c75b1b32c954aae53a043bcfacb02110ec2aae140359916de493ba27a38331132d6ca82ab8193c2bba13f32724085658cd502a66dbc85afec6b7dc1b539707c6d1d07b9fc9e7cddf7267017794cbb0fdde195c2b915d81f11e85252253e455eb66076f22ae7c64c115e06b9b4d5bb4df30d6537b7772a506e71bdd07e62fdcf6a72d952e82fc67e404f7bfafc5a74afc101001016df15964c16f6c2c75b01a7600b29428f8f0b0504ec2f19623210b466488fcbdfdf00f1cf7fc0de72942bc3280162df3fb1649dc2d6cf9367936f7bc9d2dec5d91bff63c4be9e40499c6578c6e1deb946fec05a9efc9a44696eb4a3c525c1440f5f1001c9ff2e907149a84df51a807a87c035d55ef36d9ec2cd371a629c5b4d0b710e60bd4df97b14bc85901ef6d75c7d23243cd70e857340d0d78649fa950a556118216206f021211414af280abf71b21b8253907e6cb673c1b782fe0027ff8e0306d1493b4e7c558f1826f66d41ca50b886ade88cb7427446f2497d0b94ce53ca6ffb63f2aa86c3b610c0286ebfb9d9391f1678b9dcd1dafaa088b6a29a165619faac974e6c24c5a1281e73cb8a93ccba60cd6922549ae344684d43c3b3637f8dc32a31178f698d90a7281c793a3020e538ebcc4aef689384957fded05d58ae8d44205fcb960d515874b924a120edfea84a0fcddc1ecad120f34ad96d9435ffab00511fe4a7e47454ab679b6b2e8ccc9cba572fb3177c4213c1f7f66efb9a5a6dc9488c6de0d2e3dd7b394b12a2a4afd620b2fe2cd5cc5fb34417839e6bf1efebc1374b53ce927fdad6187d3dff2ab42adfc6253afe0219e2d9da98cf4e1b24f024c526bd469d7ad18df4f1a18fe13b0a1baf52cd6e4c927b96e0b152e197fd6462106e54c91c0c16f6ae722b9fc938e6881994e6a","bits":"200f0f0f","difficulty":1,"chainwork":"0000000000000000000000000000000000000000000000000000000000004279","anchor":"59d2cde5e65c1414c32ba54f0fe4bdb3d67618125286e6a191317917c812c6d7","valuePools":[{"id":"sprout","monitored":true,"chainValue":0.00000000,"chainValueZat":0,"valueDelta":0.00000000,"valueDeltaZat":0}],"previousblockhash":"043daeb9276c4fb9176f95d043567e18d40bff3aff114f551b950ee48c75ca02","nextblockhash":"06bc7098c8df18403af23dcb7147f58a0af031a1853a686a1964eb16b48ce509"},"error":null,"id":"curltest"}
	Total time = 0.716569 seconds	
	
As you are see this way is more faster, curl  re-using existing connection to daemon each time and 1000 sequential calls to daemon tooks only `0.716569 seconds`.

### Results

| 1000 calls with new connection  | 1000 calls with keep-alive (pipelined) connection |
| ------------- | ------------- |
| Time (sec.)  | Time (sec.)  |
| 5.759622  | 0.716569  |

**p.s.** Also you can play with `curl_easy_setopt(curl, CURLOPT_TCP_FASTOPEN, 1L);` flag and others. But in my case these doesn't affect on overall time.

**p.p.s.** All tests made with statically linked curl:

	curl 7.61.0-DEV (Linux) libcurl/7.61.0-DEV OpenSSL/1.0.2g zlib/1.2.8 
	Release-Date: [unreleased]                                           
	Protocols: http https smb smbs                                       
	Features: AsynchDNS Largefile NTLM SSL libz UnixSockets HTTPS-proxy  
	
To build you'll need `cmake` installed.	