```mermaid
flowchart TD;

A(start) --> B[/Masukkan jumlah data/];
B -->  C[Print judul Input Data Slip Gaji Karyawan];
C --> D[/Input ID/];
D --> E[/Input Nama/];
E ---> F{Pilih Tipe Staff}
F --Permanen--> G[Gaji Pokok =5.500.000];
F --non--> H[Gaji Pokok = 4.500.000];
G & H --> I{status};
I --menikah--> J[Tunj = 1.000.000];
I --belum--> K[Tunj = 0];
J & K --> L{Insentive Position:STaff};
L --True--> M[Gaji = 1.000.000]
L --false--> N{Supervisor};
N --true--> O[Gaji = 3.000.000];
N --false--> P{Manager};
P --true--> Q[gaji = 4.500.000];
P --false--> R{Head of Department};
R --true--> S[gaji = 10.000.000];
R --false--> T{Director};
T --true--> U[gaji = 25.000.000]
T --false--> V((salah posisi));

M & O & Q & S & U --> W[/Input Overtime/]
W --> Y[Hitung Gross Salary]
Y --> Z[Hitung Net Salary]

Z --> z(end)

```