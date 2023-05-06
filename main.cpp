#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;

int A[50], jml, temp = 0, pos;

int bersih()
{
  cout << "\n\n";
  system("PAUSE");
  system("cls");
  return true;
}

int system() { system("cls");return true; }

int nama()
{
  cout << "\n\t\t\t\t ==> PROGRAM STRUKTUR DATA PRATIKUM 2 <==" << endl;
  cout << "\n====================================";
  cout << "\n| Deby Stevani Liu(20220801172)    |";
  cout << "\n| Kelly Felicia Riandy(20220801176)|";
  cout << "\n====================================";
  cout << endl;
  return true;
}

int garis()
{
  for (int i = 0; i <= 79; i++)
  {
    cout << "_";
  }
  cout << endl;
  return true;
}

int data()
{
  cout << "\n Input Jumlah Data: ";
  cin >> jml;
  cout << "\n Input Data: " << endl
       << endl;

  for (int i = 0; i < jml; i++)
  {
    cout << " ==> Data ke-" << i << "=";
    cin >> A[i];
  }
  cout << endl;
  return true;
}

int cetak()
{
  garis();
  cout << endl;
  cout << "\n>>Data Setelah di Sorting:" << endl
       << endl;

  for (int i = 0; i < jml; i++)
  {
    cout << " " << A[i];
  }
  cout << endl;
  return true;
}

void merge(int arr[], int left, int mid, int right, bool ascending)
{
  int i = left, j = mid + 1, k = 0;
  int *temp = new int[right - left + 1]; 
  while (i <= mid && j <= right)
  {
    if (ascending ? arr[i] <= arr[j] : arr[i] >= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
    }
  }
  while (i <= mid)
  {
    temp[k++] = arr[i++];
  }
  while (j <= right)
  {
    temp[k++] = arr[j++];
  }
  for (i = left, k = 0; i <= right; ++i, ++k)
  {
    arr[i] = temp[k];
  }
  delete[] temp; // Deallocate the dynamically allocated memory
}

void merge_sort(int arr[], int left, int right, bool ascending)
{
  if (left >= right)
  {
    return;
  }
  int mid = left + (right - left) / 2;
  merge_sort(arr, left, mid, ascending);
  merge_sort(arr, mid + 1, right, ascending);
  merge(arr, left, mid, right, ascending);
}

// Quick Sort Functions
int partition(int arr[], int low, int high, bool ascending)
{
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j <= high - 1; j++)
  {
    if (ascending ? (arr[j] < pivot) : (arr[j] > pivot))
    {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return i + 1;
}

void quickSort(int arr[], int low, int high, bool ascending)
{
  if (low < high)
  {
    int pivotIndex = partition(arr, low, high, ascending);
    quickSort(arr, low, pivotIndex - 1, ascending);
    quickSort(arr, pivotIndex + 1, high, ascending);
  }
}

// Radix function

void radixSort(int arr[], int n, bool ascending)
{
  int max_element = arr[0];
  for (int i = 1; i < n; i++)
  {
    if (arr[i] > max_element)
    {
      max_element = arr[i];
    }
  }
  for (int exp = 1; max_element / exp > 0; exp *= 10)
  {
    int *output = new int[n];    // Dynamically allocate memory for output array
    int *count = new int[10]{0}; // Dynamically allocate memory for count array and initialize with 0
    for (int i = 0; i < n; i++)
      count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++)
      count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--)
    {
      output[count[(arr[i] / exp) % 10] - 1] = arr[i];
      count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
      arr[i] = output[i];

    delete[] output; // Deallocate memory for output array
    delete[] count;  // Deallocate memory for count array
  }
  if (!ascending)
  {
    reverse(arr, arr + n);
  }
}

int main()
{
  int jml;
  std::cout << "Enter the size of the array: ";
  std::cin >> jml;

  int *arr = new int[jml];
  char kode;
nama:
  nama();
  goto menu;
menu:
  bersih();
  cout << "\t\t=== TUGAS STRUKTUR DATA PRATIKUM 2 ===\n\t\t\t\t*SORTING*" << endl;
  garis();
  cout << "\n\t\n\t\t 1. Bubble Sort";
  cout << "\n\t\n\t\t 2. Selection Sort";
  cout << "\n\t\n\t\t 3. Insertion Sort";
  cout << "\n\t\n\t\t 4. Merge Sort";
  cout << "\n\t\n\t\t 5. Quick Sort";
  cout << "\n\t\n\t\t 6. Redix Sort";
  cout << "\n\t\n\t\t 7. Kembali ke Menu Sorting" << endl;
  cout << "\n\t\t\t Masukan Kode [1/2/3/4/5/6/7] =";
  cin >> kode;

  switch (kode)
  {
  case '1':
    char kode1;
    system("cls");
  menu1:
    cout << "\t\t\t=== BUBBLE SORT ===" << endl;
    garis();
    cout << "\n\t\t\n\n\t\t 1. Ascending\n";
    cout << "\t\t 2. Descending\n";
    cout << "\t\t 3. Kembali ke Menu Utama" << endl;
    cout << "\n\n\t\t\t Masukkan Kode [1/2/3]:";
    cin >> kode1;

    switch (kode1)
    {
    case '1':
      system("cls");
      cout << "\t\t\t=== Bubble Sort Ascending ===" << endl;
      data();
      cout << "Langkah Sorting:" << endl;
      cout << "=> ** <=" << endl;

      for (int i = 1; i < jml; i++)
      {
        for (int j = jml - 1; j >= i; j--)
        {
          if (A[j] < A[j - 1])
          {
            temp = A[j];
            A[j] = A[j - 1];
            A[j - 1] = temp;
          }
        }
        cout << "=> Data <=" << i << "=";
        for (int k = 0; k < jml; k++)
        {
          cout << A[k] << " ";
        }
        cout << endl;
      }
      cetak();
      bersih();
      goto menu1;

    case '2':
      system("cls");
      cout << "\t\t\t=== Bubble Sort Descending ===" << endl;
      data();
      cout << "Langkah Sorting:" << endl;
      cout << "=> ** <=" << endl;

      for (int i = 1; i < jml; i++)
      {
        for (int j = jml - 1; j >= i; j--)
        {
          if (A[j] < A[j - 1])
          {
            temp = A[j];
            A[j] = A[j - 1];
            A[j - 1] = temp;
          }
        }
        cout << "=> Data <=" << i << "=";
        for (int k = 0; k < jml; k++)
        {
          cout << A[k] << " ";
        }
        cout << endl;
      }
      cetak();
      bersih();
      goto menu1;

    case '3':
      system("cls");
      goto menu;
    default:
      system("cls");
      cout << "\n\n\t KODE YANG ANDA MASUKKAN SALAH, SILAHKAN ULANGI LAGI !!!\a\a\a\a" << endl;
      goto menu1;
      bersih();
    }

  case '2':
    char kode2;
    system("cls");
  menu2:
    cout << "\t\t\t    === SELECTION SORT ===" << endl;
    garis();
    cout << "\n\t\t\n\n\t\t 1. Ascending \n";
    cout << "\n\t\t 2. Descending \n";
    cout << "\n\t\t 3. Kembali Ke Menu Sorting" << endl;
    cout << "\n\n\t\t\t  Masukan Kode [1/2/3] = ";
    cin >> kode2;
    switch (kode2)
    {
    case '1':
      system("cls");
      cout << "\t\t\t=== Selection Sort Ascending === " << endl;
      data();
      cout << "  Langkah Sorting:" << endl;
      cout << "  => ** <= " << endl;
      for (int i = 1; i < jml; i++)
      {
        pos = i;

        for (int j = jml - 1; j >= i; j--)
        {
          if (A[j] < A[j - 1])
          {
            temp = A[j];
            A[j] = A[j - 1];
            A[j - 1] = temp;
          }
          pos = j;
        }
        cout << "  => Data <= " << i << "  =  ";
        for (int k = 0; k < jml; k++)
        {
          cout << A[k] << "  ";
        }
        cout << endl;
      }
      cetak();
      bersih();
      goto menu2;

    case '2':
      system("cls");
      cout << "\t\t\t=== Selection Sort Descending === " << endl;
      data();
      cout << "  Langkah Sorting:" << endl;
      cout << "  => ** <= " << endl;
      for (int i = 1; i < jml; i++)
      {
        pos = i;

        for (int j = jml - 1; j >= i; j--)
        {
          if (A[j] > A[j - 1])
          {
            temp = A[j];
            A[j] = A[j - 1];
            A[j - 1] = temp;
          }
          pos = j;
        }
        cout << "  => Data <= " << i << "  =  ";
        for (int k = 0; k < jml; k++)
        {
          cout << A[k] << "  ";
        }
        cout << endl;
      }
      cetak();
      bersih();
      goto menu2;

    case '3':
      system("cls");
      goto menu;
    default:
      system("cls");
      cout << "\n\n\t KODE YANG ANDA MASUKAN SALAH, SILAHKAN ULANGI LAGI !!!\a\a\a\a" << endl;
      goto menu1;
      bersih();
    }

  case '3':
    char kode3;
    system("cls");
  menu3:
    cout << "\t\t\t    === INSERTION SORT ===" << endl;
    garis();
    cout << "\n\t\t\n\n\t\t 1. Ascending \n";
    cout << "\n\t\t 2. Descending \n";
    cout << "\n\t\t 3. Kembali Ke Menu Sorting" << endl;
    cout << "\n\n\t\t\t  Masukan Kode [1/2/3] = ";
    cin >> kode3;
    switch (kode3)
    {
    case '1':
      system("cls");
      cout << "\t\t\t=== Insertion Sort Ascending === " << endl;
      data();
      cout << "  Langkah Sorting:" << endl;
      cout << "  => ** <= " << endl;
      for (int i = 1; i < jml; i++)
      {
        temp = A[i];
        int j = i - 1;

        while (A[j] > temp && j >= 0)
        {
          A[j + 1] = A[j];
          j--;
        }
        A[j + 1] = temp;

        cout << "  => Data <= " << i << "  =  ";
        for (int k = 0; k < jml; k++)
        {
          cout << A[k] << "  ";
        }
        cout << endl;
      }
      cetak();
      bersih();
      goto menu3;
      break;

    case '2':
      system("cls");
      cout << "\t\t\t=== Insertion Sort Descending === " << endl;
      data();
      cout << "  Langkah Sorting:" << endl;
      cout << "  => ** <= " << endl;
      for (int i = 1; i < jml; i++)
      {
        temp = A[i];
        int j = i - 1;

        while (A[j] < temp && j >= 0)
        {
          A[j + 1] = A[j];
          j--;
        }
        A[j + 1] = temp;

        cout << "  => Data <= " << i << "  =  ";
        for (int k = 0; k < jml; k++)
        {
          cout << A[k] << "  ";
        }
        cout << endl;
      }
      break;

    case '3':
      system("cls");
      goto menu;
    default:
      system("cls");
      cout << "\n\n\t KODE YANG ANDA MASUKAN SALAH, SILAHKAN ULANGI LAGI !!!\a\a\a\a" << endl;
      goto menu1;
      bersih();
      return 0;
    }

  case '4':
    char kode4;
    system("cls");
  menu4:
    cout << "\t\t\t===Merge Sort Ascending===" << endl;
    garis();
    cout << "\n\t\t\n\n\t\t 1. Ascending\n";
    cout << "\n\t\t 2. Descending \n";
    cout << "\n\t\t 3. Kembali Ke Menu Sorting" << endl;
    cout << "\n\n\t\t\t  Masukkan Kode [1/2/3] = ";
    cin >> kode4;

    switch (kode4)
    {
    case '1':
      cout << "=== Merge Sort Ascending ===" << endl;
      cout << "  Langkah Sorting:" << endl;
      cout << "  => ** <= " << endl;
      merge_sort(arr, 0, jml - 1, true);
      for (int i = 0; i < jml; i++)
      {
        cout << arr[i] << " ";
      }
      break;
    case '2':
      cout << "=== Merge Sort Descending ===" << endl;
      merge_sort(arr, 0, jml - 1, false);
      for (int i = 0; i < jml; ++i)
      {
        cout << arr[i] << " ";
      }
      break;
    case '3':
      system("cls");
      goto menu;
    default:
      system("cls");
      cout << "\n\n\t KODE YANG ANDA MASUKAN SALAH, SILAHKAN ULANGI LAGI !!!\a\a\a\a" << endl;
      goto menu1;
      bersih();
    }

  case '5':
    char kode5;
    system("cls");
  menu5:
    cout << "\t\t\t===Quick Sort Ascending===" << endl;
    garis();
    cout << "\n\t\t\n\n\t\t 1. Ascending\n";
    cout << "\n\t\t 2. Descending \n";
    cout << "\n\t\t 3. Kembali Ke Menu Sorting" << endl;
    cout << "\n\n\t\t\t  Masukkan Kode [1/2/3] = ";
    cin >> kode5;

    switch (kode5)
    {
    case '1':
      cout << "=== Quick Sort Ascending ===" << endl;
      cout << "  Langkah Sorting:" << endl;
      cout << "  => ** <= " << endl;
      quickSort(arr, 0, jml - 1, true);
      for (int i = 0; i < jml; i++)
      {
        cout << arr[i] << " ";
      }
      break;

    case '2':
      cout << "=== Quick Sort Descending ===" << endl;
      quickSort(arr, 0, jml - 1, false);
      for (int i = 0; i < jml; ++i)
      {
        cout << arr[i] << " ";
      }
      break;

    case '3':
      system("cls");
      goto menu;

    default:
      system("cls");
      cout << "\n\n\t KODE YANG ANDA MASUKAN SALAH, SILAHKAN ULANGI LAGI !!!\a\a\a\a" << endl;
      goto menu1;
      bersih();
    }

  case '6':
    char kode6;
    system("cls");
  menu6:
    cout << "\t\t\t===Radix Sort Ascending===" << endl;
    garis();
    cout << "\n\t\t\n\n\t\t 1. Ascending\n";
    cout << "\n\t\t 2. Descending \n";
    cout << "\n\t\t 3. Kembali Ke Menu Sorting" << endl;
    cout << "\n\n\t\t\t  Masukkan Kode [1/2/3] = ";
    cin >> kode6;

    switch (kode6)
    {
    case '1':
      cout << "=== Radix Sort Ascending ===" << endl;
      cout << "  Langkah Sorting:" << endl;
      cout << "  => ** <= " << endl;
      radixSort(arr, jml, true);
      for (int i = 0; i < jml; i++)
      {
        cout << arr[i] << " ";
      }
      break;
    case '2':
      cout << "=== Radix Sort Descending ===" << endl;
      radixSort(arr, jml, false);
      for (int i = 0; i < jml; ++i)
      {
        cout << arr[i] << " ";
      }
      break;
    case '3':
      system("cls");
      goto menu;
    default:
      system("cls");
      cout << "\n\n\t KODE YANG ANDA MASUKAN SALAH, SILAHKAN ULANGI LAGI !!!\a\a\a\a" << endl;
      goto menu1;
      bersih();
    }

  case 7:
    char kode7;
    system("cls");
    goto nama;
  menu7:
    cin >> kode7;
    switch (kode7)
    {
    case '1':
      system("cls");
      goto nama;
    default:
      system("cls");
    }
  default:
    system("cls");
    cout << "\n\n\t KODE YANG ANDA MASUKKAN SALAH, SILAHKAN ULANGI LAGI !!!\a\a\a\a" << endl;
    goto menu;
    bersih();

    return 0;
  }
}