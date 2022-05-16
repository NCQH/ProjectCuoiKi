HƯỚNG DẪN CÀI ĐẶT

Bước 1: Cài đặt bản DevC++ bất kì

Bước 2: (lưu ý cài đặt đúng file thư viện được cung cấp vì file thư viện khác có thể không hoạt động chính xác)

Copy file graphics.h và winbgim.h vào đường dẫn

C:\Program Files (x86)\Dev-Cpp\MinGW64\x86\_64-w64-mingw32\include

Copy file libbgi.a vào đường dẫn

C:\Program Files (x86)\Dev-Cpp\MinGW64\x86\_64-w64-mingw32\lib

Bước 3: Mở DevC++ và tạo project mới


Bước 4: Thêm source file vào project

Bước 5: Tuỳ chỉnh Project

Vào Project -> Project Options

Thêm các linker sau
-lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 -lwinmm

Cuối cùng F9 để compiler and run

