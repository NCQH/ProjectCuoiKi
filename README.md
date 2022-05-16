HƯỚNG DẪN CÀI ĐẶT

Bước 1: Cài đặt bản DevC++ bất kì
![image](https://user-images.githubusercontent.com/66376544/168626445-367dc17b-c5c9-4947-b4fc-098691f7c452.png)
![image](https://user-images.githubusercontent.com/66376544/168626468-c8fd651f-a063-4c19-b7f8-16a4c16fb2d0.png)
Bước 2: (lưu ý cài đặt đúng file thư viện được cung cấp vì file thư viện khác có thể không hoạt động chính xác)

Copy file graphics.h và winbgim.h vào đường dẫn

C:\Program Files (x86)\Dev-Cpp\MinGW64\x86\_64-w64-mingw32\include

Copy file libbgi.a vào đường dẫn

C:\Program Files (x86)\Dev-Cpp\MinGW64\x86\_64-w64-mingw32\lib
![image](https://user-images.githubusercontent.com/66376544/168626489-a895f9e8-f90c-4f4b-97b7-4b6b0272e700.png)
Bước 3: Mở DevC++ và tạo project mới
![image](https://user-images.githubusercontent.com/66376544/168626505-543c0105-4d49-4a73-ad62-d6d097be1af1.png)

Bước 4: Thêm source file vào project
![image](https://user-images.githubusercontent.com/66376544/168626517-dfa02315-8862-479b-a923-f3be102f0875.png)
Bước 5: Tuỳ chỉnh Project

Vào Project -> Project Options
![image](https://user-images.githubusercontent.com/66376544/168626544-b7c7c3e8-5101-4949-bf53-9902a8cc3e63.png)
![image](https://user-images.githubusercontent.com/66376544/168626564-05123aa0-158d-4ba6-9504-128ce7b99a3f.png)
Thêm các linker sau
-lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 -lwinmm
![image](https://user-images.githubusercontent.com/66376544/168626583-3a16cb95-e465-40fc-82a7-1e6952fd0f09.png)
Cuối cùng F9 để compiler and run

