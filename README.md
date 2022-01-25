# Tugas Kecil 1 Strategi Algoritma

<i>Azka Syauqy Irsyad - 13520107</i>

Repository ini dibuat dalam rangka memenuhi Tugas Kecil 1 Mata Kuliah Strategi Algoritma Tahun 2021/2022

## Contents

- [Deskripsi Program](#deskripsi-program)
- [Struktur Repository](#struktur-repository)
- [Requirements](#requirements)
- [How to Use](#how-to-use)

## Deskripsi Program

Program <i>Word Search Puzzle</i> ini dibuat dengan memanfaatkan algoritma <i>brute force</i>. <i>Puzzle</i> serta <i>keyword</i> yang diinginkan dimasukkan dari dalam suatu file yang kemudian dibaca oleh program. Program akan langsung mencari daftar <i>keyword</i> yang diminta dalam <i>puzzle</i> tersebut, mencetak hasilnya dalam bentuk matriks, serta memperlihatkan lama waktu eksekusi serta total perbandingan karakter yang terjadi dalam menemukan keseluruhan <i>keyword</i> tersebut.

## Struktur Repository

Repository ini terdiri dari 4 <i>child directory</i> dan satu file README.

1. **bin**, directory yang berisi file-file hasil kompilasi dari <i>source code</i>.
2. **doc**, directory yang berisi file laporan tugas.
3. **src**, directory yang berisi semua file <i>source code</i> yang dibutuhkan dalam mengeksekusi program.
4. **test**, directory yang berisi file teks <i>test case</i> yang digunakan dalam menguji program.
5. **README.md**

## Requirements

Untuk dapat menjalankan program, terlebih dahulu harus ada <i>compiler</i> yang dapat meng-<i>compile</i> program `c`.

## How to Use

1. <i>Clone</i> repository ini (jika diambil dari github) atau simpan di <i>directory</i> yang diinginkan jika langsung diambil dari **zip** serta <i>extract</i>;
2. Buka terminal dan masuk ke dalam <i>directory</i> tempat Anda menyimpan repo ini dengan `cd`;
3. Ketika sudah di <i>directory</i> yang tepat, ketikkan `cd src`;
4. Ketikkan `gcc -c main.c`;
5. Ketikkan `gcc main.c -o main && ./main` untuk mengeksekusi program;
6. Perhatikan bahwa untuk memasukkan nama file, masukkan pengguna harus menggunakan format `../test/[nama-file.txt]`, jika tidak maka akan terjadi <i>segmentation fault</i>;
7. Program berhasil dieksekusi sampai akhir.