# BMP-Encryptor-CMD-Tool

A lightweight BMP image encryption command line tool written in C++.

### Usage

To use the program, `cd` into the build folder and run:

```bash
./bmp_encryptor <input_path> <password> [encrypted_bmp_file_name]
```

The encrypted image will be created in the same directory as the original.

To decrypt an image simply rerun the program with the encrypted image's path as the input path
and use the same password you used to encrypt it.

Features:
-Encrypt and decrypt .bmp images
-CMake build support
